class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None
    
class LinkedList:
    def __init__(self):
        self.head = None
        
    def append(self, value):
        new = Node(value)
        
        if not self.head:
            self.head = new
            return
        
        temp = self.head
        
        while temp.next:
            temp = temp.next
            
        temp.next = new
        
    def prepend(self, value):
        new = Node(value)
        new.next = self.head
        self.head = new
        
    def display(self):
        temp = self.head
        
        while temp:
            print(f"{temp.data} -> ", end="")
            temp = temp.next
        print("NULL")
        
    def insertaftervalue(self, value, aftervalue):
        new = Node(value)
        
        if not self.head:
            return
            
        temp = self.head
        
        while temp:
            if temp.data == aftervalue:
                new.next = temp.next
                temp.next = new
                return  
            temp = temp.next
             
    def deleteathead(self):
       delq = self.head
       self.head = self.head.next
       
    def deleteattail(self):
        if not self.head:
            return
        
        if not self.head.next:
            self.head = None
            return
        temp = self.head
        while temp.next.next:
            temp = temp.next
        temp.next = None 
        
    def insertafterindex(self, value, index):
        new = Node(value)
        count = 0
        if not self.head:
            return
        
        temp = self.head
        
        while temp:
            if count == index:
                new.next = temp.next
                temp.next = new
                return
            count += 1
            temp = temp.next
                
    
L1 = LinkedList()
L1.append(1)
L1.append(2)
L1.display()
L1.insertaftervalue(value=2.5, aftervalue=2)
L1.display()
L1.insertafterindex(3, 2)
L1.display()
L1.insertaftervalue(1.5, 1)
L1.display()
L1.deleteathead()
L1.display()
L1.deleteattail()
L1.display()