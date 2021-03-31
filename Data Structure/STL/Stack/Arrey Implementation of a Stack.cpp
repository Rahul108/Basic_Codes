#include<bits/stdc++.h>
#define MAX 10
using namespace std;

void insert(int queue[],int *rear,int value)
{
    if(*rear < MAX -1){
        *rear = *rear - 1;
        queue[*rear] = value;
    }
    else{
        printf("The queue is Full can not insert a value\n");
        exit(0);
    }
}

void Delete(int queue[],int *front,int rear,int *value)
{
    if(*front == rear){
        printf("The queue is empty cannot Delete a value\n");
        exit(0);
    }
    *front = *front + 1;
    *value = queue[*front];
}

main()
{
    int queue[MAX];
    int front,rear;
    int n,value;
    front = rear = (-1);
    do{
        do{
            printf("Enter The Element to be inserted\n");
            scanf("%d",&value);
            insert(queue,&rear,value);
            printf("Enter 1 to continue\n");
            scanf("%d",&n);
        }while(n==1);

        printf("Enter 1 to Delete an element\n");
        scanf("%d",&n);
        while(n==1)
        {
            Delete(queue,&front,rear,&value);
            printf("The Value Deleted is %d\n",value);
            printf("Enter 1 to Delete an element\n");
            scanf("%d",&n);
        }
        printf("Enter 1 to Continue\n");
        scanf("%d",&n);
    } while(n==1);
}
