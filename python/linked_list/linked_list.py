class Node:
    def __init__(self,initdata):
        self.data = initdata
        self.next = None

    def __init__(self,initdata, next):
        self.data = initdata
        self.next = next

    def getData(self):
        return self.data

    def getNext(self):
        return self.next

    def setData(self,newdata):
        self.data = newdata

    def setNext(self,newnext):
        self.next = newnext


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def getHead(self):
        return self.head

    def getTail(self):
        return self.tail

    def setHead(self, head):
        self.head = head

    def setTail(self, tail):
        self.tail = tail

    def isEmpty(self):
        return self.head == None and self.tail == None

    def pushFirst(self, item):
        node = Node(item, self.getHead())
        if (self.isEmpty()):
            self.setTail(node)
        self.setHead(node)

    def getFirst(self):
        if (self.isEmpty()):
            return None
        return self.getHead()

    def popFirst(self):
        if (self.isEmpty()):
            return None
        node = self.getHead()
        self.setHead(node.getNext())
        if (self.getHead() is None):
            self.setTail(None)
        return node

    def printList(self):
        if (self.isEmpty()):
            print("List is empty")
            return;

        node = self.getHead()
        index = 0

        while node is not None:
            print("{}: {}".format(index, node.getData()))
            node = node.getNext()
            index+=1


    def pushBack(self, item):
        node = Node(item, None)
        if (self.isEmpty()):
            self.setHead(node)
            
        else:
            self.getTail().setNext(node)

        self.setTail(node)

    def getBack(self):
        if (self.isEmpty()):
            return None
        return self.getTail()

    def popBack(self):
        if (self.isEmpty()):
            return None
        node = self.getTail()
        tempNode = self.getHead()
        while (tempNode.getNext() is not node):
            tempNode = tempNode.getNext()
        tempNode.setNext(None)
        self.setTail(tempNode)

        return node

    def find(self, item):
        tempNode = self.getHead()
        while tempNode.getData() is not item and tempNode is not None:
            tempNode = tempNode.getNext()
        return tempNode

    def addBefore(self, itemBefore, item):
        nodeBefore = self.find(itemBefore)
        if (nodeBefore is None):
            print("Item not found")
            return

        if (nodeBefore == self.getHead()):
            self.pushFirst(item)
            return

        node = Node(item, nodeBefore)
        tempHead = self.getHead()
        while (tempHead.getNext() is not nodeBefore):
            tempHead = tempHead.getNext()
        tempHead.setNext(node)