#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

struct node *insert(struct node *p, int n)
{
    struct node *temp;
    if(p==NULL)
    {
        p=(struct node *)malloc(sizeof(struct node));
        if(p==NULL)
        {
            printf("Error\n");
            exit(0);
        }
        p-> data = n;
        p->link = NULL;
    }
    else
    {
        temp = p;
        while(temp-> link !=NULL)
            temp = temp-> link;
        temp-> link = NULL;
    }
    return  (p);
};

void printlist(struct node *p)
{
    printf("The data Values in the list are\n");
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p = p-> link;
    }
}

struct node *reverse(struct node *p)
{
    struct node *prev,*curr;
    prev = NULL;
    curr = p;
    while(curr!=NULL)
    {
        p = p-> link;
        curr-> link = prev;
        prev = curr;
        curr = p;

        return(prev);
    }
};

struct node *shortlist(struct node *p)
{
    struct node *temp1,*temp2,*min,*prev,*q;
    q = NULL;
    while(p != NULL)
    {
        prev = NULL;
        min = temp1 = p;
        temp2 = p-> link;

        while(temp2 != NULL)
        {
            if(min -> data > temp2 -> data)
            {
                min = temp2;
                prev= temp1;
            }
            temp1 = temp2;
            prev  = temp2-> link;
        }
        if(prev == NULL)
            p = min -> link;
        else
            prev -> link = min -> link;
        min-> link = NULL;
        if(q == NULL)
            q=min;
        else
            temp1 = q;
        while(temp1 -> link != NULL)
            temp1 = temp1 -> link;
    }
    return (q);
};

main()
{
    int n,x;
    struct node *start = NULL;
    printf("Enter The code to be created \n");
    scanf("%d",&n);

    while( n--> 0 )
    {
        printf("Enter The data values to be pleased in a node\n");
        scanf("%d",&x);
        start = insert(start,x);
    }
    printf("The created list is\n");
    printlist(start);
    start = shortlist(start);
    printf("The sorted list is\n");
    printlist(start);
    start = reverse(start);
    printf("The reversed list is\n");
    printlist(start);
}
