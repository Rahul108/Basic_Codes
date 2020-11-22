#include<bits/stdc++.h>
using namespace std;

void merge_arr(int arr[], int fi, int mid, int li){
    int hlpr[100001];
    int i,j,k;
    i=fi;
    j=mid+1;
    k=0;
    while(i<=mid && j<=li){
        if(arr[i]<arr[j])
            hlpr[k++]=arr[i++];
        else
            hlpr[k++]=arr[j++];
    }
    while(i<=mid)
        hlpr[k++]=arr[i++];
    while(j<=li)
        hlpr[k++]=arr[j++];
    for(i=li;i>=fi;i--)
        arr[i]=hlpr[--k];
}

void merge_sort(int arr[], int fi, int li){
    int mid;
    if(fi<li){
        mid=(fi+li)/2;
        merge_sort(arr,fi,mid);
        merge_sort(arr,mid+1,li);
        merge_arr(arr,fi,mid,li);
    }
}


int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}