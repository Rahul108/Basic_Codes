#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[], int n){
    int k;
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1] > arr[j]){
            int k = arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=k;
            j--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    insertion_sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}