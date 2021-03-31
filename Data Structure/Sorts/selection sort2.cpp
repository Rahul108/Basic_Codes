#include<bits/stdc++.h>
#define MAX 10
using namespace std;

void swap(int *x,int *y)
{
    int temp(0);
    temp=*x;
    *x = *y;
    *y = temp;
}

void selection_sort(int list[],int n)
{
    int i,j,min;
    for(int i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
            if(list[j]<list[min])
            min=j;
        swap(&list[i],&list[min]);
    }
}

void printlist(int list[],int n)
{
    int i;
    for(int i=0;i<n;i++)
        printf("%d\t",list[i]);
}

main()
{
    int list[MAX];
    int i=0;
    for(int i=0;i<MAX;i++)
    list[i]=rand();
    printf("The List Before Sorting is:\n");
    printlist(list,MAX);
    selection_sort(list,MAX);
    printf("The list after sorting is:\n");
    printlist(list,MAX);
}
