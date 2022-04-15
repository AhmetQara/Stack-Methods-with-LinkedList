/******************************************************************************

created by @AhmetKara
GitHub: https://github.com/ahmetQara

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
  
  int data;
  struct node *next;
    
};

struct node* top = NULL;

void push(int input) 

{
    
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data = input;
    new->next = NULL;
    
    if (top!=NULL) 
        new->next=top; // The next of input will be top so that the input can be appended to the beginning.
    top=new;
    
}

void pop(){
    
    if(top == NULL) {
        printf("The stack is already EMPTY!!! ");
    } 
    
    else { // if stack is not empty
        
        struct node* temp;
        temp=top; // we temporarily set it to the temp value so that we can pop it and then delete it without losing the previous "top" value
        top=top->next; // We moved the top to one side so that we can delete the previous top. "top" value decreased by 1 after "pop" method
        free(temp);
    }

}


int peek() {
    return top->data;
}

void print() {
    
    struct node* q;
    q=top;
    printf("\n");
    while(q!=NULL) {
        printf("%d -> ", q->data);
        q=q->next;
    }
    printf("NULL");
    
}
    

int main()
{
    int userInput;
  
    while(1==1){
        printf("\n1- Push");
        printf("\n2- Pop");
        printf("\n3- Peek");
        printf("\nMake your choice: ");
        scanf("%d", &userInput);
        
        switch(userInput){
            case 1:
                printf("\nEnter a number: ");
                scanf("%d", &userInput);
                push(userInput);
                print();
                break;
            case 2:
                pop();
                print();
                break;
            case 3:
                printf("\nTop data(item) = %d", peek());
                break;
                
        }

        
    }
 
    return 0;
}
