class Node:
    def __init__(self, data, next):
        self.data = data
        self.next = next
        pass


class Stack:
    def __init__(self):
        self.top = None

    def isEmpty(self):
        if self.top is None:
            return True
        return False

    def push(self, data):
        self.top = Node(data, self.top)

    def pop(self):
        if self.isEmpty():
            print("Stack Underflow!")
            return
        data = self.top.data
        self.top = self.top.next
        return data

    def peek(self):
        if self.isEmpty():
            print("Stack Underflow!")
            return
        return self.top.data

    def display(self):
        if self.isEmpty():
            print("Stack Underflow!")
            return
        head = self.top
        while head:
            print(head.data, end="\t")
            head = head.next
        print()


def main():
    s = Stack()
    print("1.Push\n2.Pop\n3.Print Top Element\n4.Display All\n5.Exit")
    while 1:
        i = int(input("Select Option: "))
        match i:
            case 1:
                data = int(input("Enter Data: "))
                s.push(data)
            case 2:
                print(f"{s.pop()} is Deleted")
            case 3:
                print(f"Element At top is {s.peek()}")
            case 4:
                s.display()
            case 5:
                exit(0)


if __name__ == '__main__':
    main()
