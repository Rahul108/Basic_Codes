#include<bits/stdc++.h>
using namespace std;

void quicksort(int arr[], int lf, int rf){
    int i=lf,j=rf,tmp;
    int pv=arr[(lf+rf)/2];
    while(i<=j){
        while(arr[i]<pv)
            i++;
        while(arr[j]>pv)
            j--;
        if(i<=j){
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            i++;
            j--;
        }
    }
    if(lf<j)
        quicksort(arr,lf,j);
    if(rf>i)
        quicksort(arr,i,rf);
}

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}