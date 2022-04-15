class Stack:
    def __init__(self, max):
        self.max = max
        self.arr = [i for i in range(max)]
        self.top = -1

    def isEmpty(self):
        if self.top == -1:
            return True
        return False

    def isFull(self):
        if self.top == self.max - 1:
            return True
        return False

    def push(self, data):
        if self.isFull():
            print("Stack Overflow!")
            return
        self.top += 1
        self.arr[self.top] = data

    def pop(self):
        if self.isEmpty():
            print("Stack Underflow!")
            return
        data = self.arr[self.top]
        self.top -= 1
        return data

    def peek(self):
        if self.isEmpty():
            print("Stack Underflow!")
            return
        return self.arr[self.top]

    def display(self):
        if self.isEmpty():
            print("Stack Underflow!")
            return
        for i in range(self.top, -1, -1):
            print(self.arr[i], end="\t")
        print()


def main():
    max = int(input("Enter Max: "))
    s = Stack(max)
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
