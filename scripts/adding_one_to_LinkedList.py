import sys
import math

# Linked list node


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to create a new node with given data */


def newNode(data):
    return Node(data)

# Function to reverse the linked list */


def reverseList(head):

    if not head:
        return
    curr = head
    prev = None

    while(curr != None):
        nextNode = curr.next
        curr.next = prev
        prev = curr
        curr = nextNode

    return(prev)
# Adds one to a linked lists and return the head
# node of resultant list


def addOne(head):

    # Reverse linked list
    head = reverseList(head)
    temp = head
    carry = 1
    while(temp):
        temp.data += carry
        if temp.data % 10 == 0:
            # update carry for next calulation
            carry = 1
            temp.data = 0
        else:
            # update carry for next calulation
            carry = 0
        temp = temp.next

    # Reverse the modified list
    return reverseList(head)

# A utility function to print a linked list


def printList(head):
    if not head:
        return
    while(head):
        print("{}".format(head.data), end="")
        head = head.next


# Driver code
if __name__ == '__main__':
    head = newNode(1)
    head.next = newNode(9)
    head.next.next = newNode(9)
    head.next.next.next = newNode(9)

    print("List is: ", end="")
    printList(head)

    head = addOne(head)

    print("\nResultant list is: ", end="")
    print()
    printList(head)
    print("\n")
