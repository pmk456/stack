#include<stdio.h>
#include<stdlib.h>
int top = -1;
void push(int data);
int *arr, MAX;
int pop();

int peek();
int isEmpty();
int isFull();
void display();
void change_max(){
    printf("Enter Max: ");
    scanf("%d", &MAX);
    arr = (int *) realloc(arr, MAX * sizeof(int));
    top = -1;
}
int main(){
    int op, data;
    printf("Enter Max: ");
    scanf("%d", &MAX);
    arr = (int *) malloc(MAX * sizeof(int));
    printf("1.Push\n2.Pop\n3.Display Top Element");
    printf("\n4.Display All Stack Elements\n5.Change Max\n6.Exit\n");
    do{
        printf("Enter option: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Enter Data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) printf("Popped item is %d\n", data);
                break;
            case 3:
                data = peek();
                if(data != -1) printf("Top Element is %d\n", data);
                break;
            case 4:
                display();
                break;
            case 5:
                change_max();
                break;
            case 6:
                exit(0);
            default:
                printf("Enter Correct Option!\n");
        }
    }while(op != 6);
}
int isFull(){
    if (top == MAX - 1) return 1;
    return 0;
}
int isEmpty(){
    if (top == -1) return 1;
    return 0;
}
void push(int data){
    if(isFull()){
        printf("Stack Overflow!\n");
        return;
    }
    top++;
    arr[top] = data;
}
int pop(){
    int data;
    if(isEmpty()){
        printf("Stack Underflow!\n");
        return -1;
    }
    data = arr[top];
    top--;
    return data;
}
int peek(){
    if(isEmpty()){
        printf("Stack underflow\n");
        return -1;
    }
    return arr[top];
}
void display(){
    if(isEmpty()){
        printf("Stack Underflow!\n");
        return;
    }
    printf("Stack Elements Are: \n");
    for(int i=top; i>=0; i--){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
