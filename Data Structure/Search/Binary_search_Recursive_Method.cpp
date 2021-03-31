#include<bits/stdc++.h>
#define MAX 10
using namespace std;

int search(int data[],int key,int left,int right)
{
    if(left<=right){
        int middle = (left + right)/2;
    if(key==data[middle])
        return middle;
    else if(key<data[middle])
        return search(data,key,left,middle-1);
    else
        return search(data,key,middle+1,right);
    }
}

main()
{
    int key;
    int index;
    int data[MAX];

    for(int i=0;i<10;i++)
    scanf("%d",&data[i]);
    printf("Enter a number to search: ");
    scanf("%d",&key);
    index=search(data,key,0,9);
    if(index== -1)
        cout<<endl<<"Key not Found :-( ! "<<endl;
    else
        cout<<endl<<"Data found on "<<index+1<< " no of index :-)"<<endl;
}
