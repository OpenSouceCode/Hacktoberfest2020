import os

folders = os.listdir()
# print(folders)
path = os.getcwd()
# print(path)
# pdfs = []
# total = {}
# Binod_in = []
print('#'*35, 'binod detector results', '#'*35)

for folder in folders:
	if folder == 'Binod_detector.py':
		pass
	else:
		Binod_in = ''
		names = ''
		new_path = path+'\\'+folder
		os.chdir(new_path)
		# print(os.getcwd())
		# os.chdir(path)
		files = os.listdir()
		# print(file)
		
		binod = [file for file in files if file.split('.')[0].lower()=='binod']
		for name in binod:
			names += name+','

		binod_file = len(binod)

		for file in files:
			if file.endswith('txt'):
				with open(file, 'r') as f:
					if 'binod' in f.read().lower():
						Binod_in += file+', '

		print(f'\nBinod name found in {binod_file} files in {folder} folder: {names}',end='')
		if len(Binod_in)>0:
			print(f' and binod was hidden inside {Binod_in} files.')
		else:
			print('\n')

		
			
# print(total)
# print(pdf)










	