#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
} *top = NULL;

void push(int data);
int pop();
int peek();
int isEmpty();
int isFull();
void display();
int main(){
    int op, data;
    printf("1.Push\n2.Pop\n3.Display Top Element");
    printf("\n4.Display All Stack Elements\n5.Exit\n");
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
                exit(0);
            default:
                printf("Enter Correct Option!\n");
        }
    }while(op != 5);
}
int isFull(){
    struct node *tmp = (struct node *) malloc(sizeof(struct node));
    if (tmp == NULL) return 1;
    return 0;
}
int isEmpty(){
    if(top == NULL) return 1;
    return 0;
}
void push(int data){
    struct node *tmp = (struct node *) malloc(sizeof(struct node));
    if(isFull()){
        printf("Stack overflow!\n");
        return;
    }
    tmp->data = data;
    tmp->next = top;
    top = tmp;
}
int pop(){
    int data;
    if(isEmpty()){
        printf("Stack Underflow!\n");
        return -1;
    }
    data = top->data;
    top = top->next;
    return data;
}
int peek(){
    if(isEmpty()){
        printf("Stack Undeflow!\n");
        return -1;
    }
    return top->data;
}
void display(){
    struct node *temp;
    if(top == NULL){
        printf("Stack Undeflow!\n");
        return;
    }
    printf("Stack Elements Are: \n");
    for(temp = top; temp != NULL; temp = temp->next) printf("%d\t", temp->data);
    printf("\n");
}
