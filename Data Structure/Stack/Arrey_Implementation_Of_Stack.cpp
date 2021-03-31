#include<bits/stdc++.h>
#define MAX 10
using namespace std;

void push(int stack[],int *top,int value)
{
    if(*top<MAX){
        *top = *top+1;
        stack[*top]=value;
    }
    else{
        printf("The Stack is Full can't Push a value :-( \n");
        exit(0);
    }
}
void pop(int stack[],int *top,int *value)
{
    if(*top>=0)
    {
        *value = stack[*top];
        *top = *top - 1;
    }
    else{
        printf("The Stack is empty and can't pop a value :-( \n");
        exit(0);
    }
}

main()
{
    int stack[MAX] ;
    int top = -1;
    int n,value;
    do{
        do{
            printf("Enter a Value to be pushed:\n");
            scanf("%d",&value);
            push(stack,&top,value);
            printf("Enter 1 To Continue\n");
            scanf("%d",&n);
        }while(n==1);

        printf("Enter 1 to POP an element\n");
        scanf("%d",&n);
        while(n==1)
        {
            pop(stack,&top,&value);
            printf("The Value POPED is %d\n",value);
            printf("Enter 1 to POP an element\n");
            scanf("%d",&n);
        }
        printf("Enter 1 to Continue\n");
        scanf("%d",&n);
    }while(n==1);
}
