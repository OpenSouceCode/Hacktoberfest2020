#Packet sniffer in python


import socket, sys, re, string
from struct import *

#Convert a string of 6 characters of ethernet address into a dash separated hex string


def eth_addr(a):
    a = str(a)
    b = "%.2x:%.2x:%.2x:%.2x:%.2x:%.2x" % (ord(a[0]), ord(a[1]), ord(a[2]), ord(a[3]), ord(a[4]), ord(a[5]))
    return b

#Start of the program
inputs = sys.argv[1:]
argv_len = len(inputs)

if argv_len > 3:
	print("Too many arguments.\nExpected maximum of 3 arguments")

try:
	dest_add = [i for i in inputs if '.' in i][0]
	if len(dest_add) == 0:
		dest_add = None
except:
	dest_add = None

try:
	app_protocol = [i for i in inputs if i.isalpha()][0]
	if app_protocol.lower() == 'http':
		port = 80
		app_protocol = 'tcp'
	elif app_protocol.lower() == 'ftp':
		port = 20
		app_protocol = 'tcp'
	elif app_protocol.lower() == 'smtp':
		port = 25
		app_protocol = 'tcp'
	elif app_protocol.lower() == 'imap':
		port = 143
		app_protocol = 'tcp'
	elif app_protocol.lower() == 'https':
		port = 443
		app_protocol = 'tcp'
	else:
		app_protocol = app_protocol.lower()
		port = None
except:
	app_protocol = ['tcp', 'udp', 'icmp']
	port = None

try:
	port1 = int([i for i in inputs if i.isdigit()][0])
except:
	port1 = None

if port1 is not None:
	port = port1



print(port, app_protocol, dest_add)

printable = string.ascii_letters + string.digits + string.punctuation + ' '

#create a AF_PACKET type raw socket (thats basically packet level)
#define ETH_P_ALL    0x0003          /* Every packet (be careful!!!) */
try:
	s = socket.socket( socket.AF_PACKET , socket.SOCK_RAW , socket.ntohs(0x0003))
except socket.error as msg:
	print ('Socket could not be created. Error Code : ' + str(msg[0]) + ' Message ' + msg[1])
	sys.exit()

# receive a packet
while True:
	packet = s.recvfrom(65565)
	
	#packet string from tuple
	packet = packet[0]
	
	#parse ethernet header
	eth_length = 14
	
	eth_header = packet[:eth_length]
	eth = unpack('!6s6sH' , eth_header)
	eth_protocol = socket.ntohs(eth[2])

	# if port is None and app_protocol is None and dest_add is None:
		# print ('Destination MAC : ' + eth_addr(packet[0:6]) + ' Source MAC : ' + eth_addr(packet[6:12]) + ' Protocol : ' + str(eth_protocol))

	#Parse IP packets, IP Protocol number = 8
	if eth_protocol == 8 :
		#Parse IP header
		#take first 20 characters for the ip header
		ip_header = packet[eth_length:20+eth_length]
		
		#now unpack them :)
		iph = unpack('!BBHHHBBH4s4s' , ip_header)

		version_ihl = iph[0]
		version = version_ihl >> 4
		ihl = version_ihl & 0xF

		iph_length = ihl * 4

		ttl = iph[5]
		protocol = iph[6]
		s_addr = socket.inet_ntoa(iph[8]);
		d_addr = socket.inet_ntoa(iph[9]);

		# if port is None and app_protocol is None and (dest_add is None or dest_add is str(d_addr)):
		# print ('Version : ' + str(version) + ' IP Header Length : ' + str(ihl) + ' TTL : ' + str(ttl) + ' Protocol : ' + str(protocol) + ' Source Address : ' + str(s_addr) + ' Destination Address : ' + str(d_addr))

		#TCP protocol
		if protocol == 6 and 'tcp' in app_protocol:
			t = iph_length + eth_length
			tcp_header = packet[t:t+20]

			#now unpack them :)
			tcph = unpack('!HHLLBBHHH' , tcp_header)
			
			source_port = tcph[0]
			dest_port = tcph[1]
			sequence = tcph[2]
			acknowledgement = tcph[3]
			doff_reserved = tcph[4]
			tcph_length = doff_reserved >> 4
			
			
			h_size = eth_length + iph_length + tcph_length * 4
			data_size = len(packet) - h_size
			
			#get data from the packet
			data = packet[h_size:]
			if (port is None or port == dest_port) and (dest_add is None or dest_add is str(d_addr)):
				# print ('Version : ' + str(version) + ' IP Header Length : ' + str(ihl) + ' TTL : ' + str(ttl) + ' Protocol : ' + str(protocol) + ' Source Address : ' + str(s_addr) + ' Destination Address : ' + str(d_addr))
				print ('Destination MAC : ' + eth_addr(packet[0:6]) + ' Source MAC : ' + eth_addr(packet[6:12]) + ' Protocol : ' + str(eth_protocol))
				print ('Version : ' + str(version) + ' IP Header Length : ' + str(ihl) + ' TTL : ' + str(ttl) + ' Protocol : ' + str(protocol) + ' Source Address : ' + str(s_addr) + ' Destination Address : ' + str(d_addr))
				print ('Source Port : ' + str(source_port) + ' Dest Port : ' + str(dest_port) + ' Sequence Number : ' + str(sequence) + ' Acknowledgement : ' + str(acknowledgement) + ' TCP header length : ' + str(tcph_length))
				print ('Data: ', end='')
				try:
					i = data.decode('utf-8', 'ignore')
					j = ''.join(c if c in printable else r'.'.format(ord(c)) for c in i)
					if j.isprintable():
						print(j)
				except:
					print('.', end='')
					
				print()

		#ICMP Packets
		elif protocol == 1 and 'icmp' in app_protocol:
			u = iph_length + eth_length
			icmph_length = 4
			icmp_header = packet[u:u+4]

			#now unpack them :)
			icmph = unpack('!BBH' , icmp_header)
			
			icmp_type = icmph[0]
			code = icmph[1]
			checksum = icmph[2]
			
			h_size = eth_length + iph_length + icmph_length
			data_size = len(packet) - h_size
			
			#get data from the packet
			data = packet[h_size:]
			if (port is None or port == dest_port) and (dest_add is None or dest_add is str(d_addr)):
				# print ('Version : ' + str(version) + ' IP Header Length : ' + str(ihl) + ' TTL : ' + str(ttl) + ' Protocol : ' + str(protocol) + ' Source Address : ' + str(s_addr) + ' Destination Address : ' + str(d_addr))
				print ('Destination MAC : ' + eth_addr(packet[0:6]) + ' Source MAC : ' + eth_addr(packet[6:12]) + ' Protocol : ' + str(eth_protocol))
				print ('Version : ' + str(version) + ' IP Header Length : ' + str(ihl) + ' TTL : ' + str(ttl) + ' Protocol : ' + str(protocol) + ' Source Address : ' + str(s_addr) + ' Destination Address : ' + str(d_addr))
				print ('Type : ' + str(icmp_type) + ' Code : ' + str(code) + ' Checksum : ' + str(checksum))
				print ('Data: ', end='')
				try:
					i = data.decode('utf-8', 'ignore')
					j = ''.join(c if c in printable else r'.'.format(ord(c)) for c in i)
					if j.isprintable():
						print(j)
				except:
					print('.', end='')
					
				print()

		#UDP packets
		elif protocol == 17 and 'udp' in app_protocol:
			u = iph_length + eth_length
			udph_length = 8
			udp_header = packet[u:u+8]

			#now unpack them :)
			udph = unpack('!HHHH' , udp_header)
			
			source_port = udph[0]
			dest_port = udph[1]
			length = udph[2]
			checksum = udph[3]
			
			
			h_size = eth_length + iph_length + udph_length
			data_size = len(packet) - h_size
			
			#get data from the packet
			data = packet[h_size:]
			if (port is None or port == dest_port) and (dest_add is None or dest_add is str(d_addr)):
				# print ('Version : ' + str(version) + ' IP Header Length : ' + str(ihl) + ' TTL : ' + str(ttl) + ' Protocol : ' + str(protocol) + ' Source Address : ' + str(s_addr) + ' Destination Address : ' + str(d_addr))
				print ('Destination MAC : ' + eth_addr(packet[0:6]) + ' Source MAC : ' + eth_addr(packet[6:12]) + ' Protocol : ' + str(eth_protocol))
				print ('Version : ' + str(version) + ' IP Header Length : ' + str(ihl) + ' TTL : ' + str(ttl) + ' Protocol : ' + str(protocol) + ' Source Address : ' + str(s_addr) + ' Destination Address : ' + str(d_addr))
				print ('Source Port : ' + str(source_port) + ' Dest Port : ' + str(dest_port) + ' Length : ' + str(length) + ' Checksum : ' + str(checksum))
				print ('Data: ', end='')
				try:
					i = data.decode('utf-8', 'ignore')
					j = ''.join(c if c in printable else r'.'.format(ord(c)) for c in i)
					if j.isprintable():
						print(j)
				except:
					print('.', end='')
					
				print()

		#some other IP packet like IGMP
		# else :
		# 	print ('Result not a part of filter')
