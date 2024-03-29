#include <stdio.h>

//global variables
int top;
//define structure
struct Stack{
    //components
    int item;
};

//vector size and init
struct Stack stack[4];

//function init structure
void init(){
    top = -1;
}

//function print structure
void print_stack(){
    printf("\n\n[%d] [%d] [%d] [%d]\n\n",stack[0].item,stack[1].item,stack[2].item,stack[3].item);
}

//insert item in stack structure
void Push(){
    
    //stack full
    if(top == 4){
        
        printf("Stack full");
        
    }else{//in case stack  is not full
        
    top++;
    int value;
    
    printf("\nValue:");
    scanf("%d",&value);
    stack[top].item = value;
    
    print_stack();
    
    }
    
}

//function to delete item
void Pop(){
    
    if(top == -1){//minimum value
        
        printf("Stack full");
        
    }else{
        
    stack[top].item = 0;
    top--;
    
    }
}

//function to delete stack
void Clear_stack(){
    while(top != -1){
        Pop();
    }
    
    print_stack();
}

int main()
{
    char option;
    int i = 0;
    
    init();
    
    //loop to keep the user
    while(i!=100){
        
        printf("\nOption:\n[p] = Push\n[c] = Pop\n[d] = Delete Stack\n");
        scanf("%c",&option);
        
        
        //series of option conditionals
        if(option == 'p'){
            Push();
        }
        
        if(option == 'c'){
            Pop();
            print_stack();
        }
        
        if(option == 'd'){
            Clear_stack();
        }
            
        //to keep the user in loop
        scanf("%d",&i);
        
    }
    
    return 0;
}
