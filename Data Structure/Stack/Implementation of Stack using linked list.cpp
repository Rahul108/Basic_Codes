#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

struct node *push(struct node *p,int value)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("No Memory Available Error\n");
        exit(0);
    }
    temp->data = value;
    temp->link = p;
    p = temp;
    return (p);
};

struct node *pop(struct node *p,int *value)
{
    struct node *temp;
    if(p==NULL){
        printf("The Stack is empty can not POP error\n");
        exit(0);
    }
    *value = p->data;
    temp = p;
    p = p->link;
    free(temp);
    return (p);
};

main()
{
    struct node *top = NULL;
    int n,value;
    do{
        do{
            printf("Enter the element to be Pushed\n");
            scanf("%d",&value);
            top = push(top,value);
            printf("Enter 1 To be continue\n");
            scanf("%d",&n);
        }while(n==1);
        printf("Enter 1 to POP an element\n");
        scanf("%d",&n);
        while(n==1)
        {
            top = pop(top,&value);
            printf("The value POPED is %d\n",value);
            printf("Enter 1 to POP an element\n");
            scanf("%d",&n);
        }
        printf("Enter 1 To continue");
        scanf("%d",&n);
    }while(n==1);
}
