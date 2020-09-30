class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    def printlist(self):
        arr = []
        temp = self.head
        while(temp):
            # print(temp.data)
            arr.append(temp.data)
            temp = temp.next
        arr.sort()
        return arr
if __name__ == "__main__":
    llist = LinkedList()

    llist.head = Node(1)
    second = Node(0)
    third = Node(0)
    four = Node(1)

    llist.head.next = second
    second.next = third
    third.next = four
    

    print(llist.printlist())

