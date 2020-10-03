string = 'BCAADDDCCACACAC'


# Creating tree nodes
class NodeTree(object):

    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right

    def children(self):
        return (self.left, self.right)

    def nodes(self):
        return (self.left, self.right)

    def __str__(self):
        return '%s_%s' % (self.left, self.right)


# Main function implementing huffman coding 
# marking 0&1 to nodes
def huffman_code_tree(node, left=True, binString=''):
    if type(node) is str:
        return {node: binString}
    (l, r) = node.children()
    d = dict()
    d.update(huffman_code_tree(l, True, binString + '0'))
    d.update(huffman_code_tree(r, False, binString + '1'))
    
    return d


# Calculating frequency
# Using a dictionary name freq
freq = {}
for items in string: 
        freq[items] = string.count(items)

freq = sorted(freq.items(), key=lambda x: x[1], reverse=True)
print('Frequency of characters:')
print(freq)

nodes = freq


# code for selecting smallest two elements 
print('\n\nLeaf Nodes :')
while len(nodes) > 1:
    
    (key1, val1) = nodes[-1] # gives the smallest element
    (key2, val2) = nodes[-2] # gives second smallest element
    nodes = nodes[:-2] #assigns all values of dict except last two
    node = NodeTree(key1, key2)
    nodes.append((node, val1 + val2)) # adding smallest two to create node
    print(node)
    nodes = sorted(nodes, key=lambda x: x[1], reverse=True)
    

huffmanCode = huffman_code_tree(nodes[0][0])

print('\n\n Char | Huffman code ')
print('----------------------')
for (char, frequency) in freq:
    print(' %-4r |%12s' % (char, huffmanCode[char]))

