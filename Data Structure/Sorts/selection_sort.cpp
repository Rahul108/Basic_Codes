#include<bits/stdc++.h>
using namespace std;

void swap_val(int arr[], int fi, int li){
    int tmp;
    tmp = arr[fi];
    arr[fi]=arr[li];
    arr[li]=tmp;
}

int selection_prs(int arr[], int fi, int li){
    int min_val = arr[fi];
    int min_ind = fi;

    for(int i=min_ind+1;i<li;i++){
        if(arr[i]<min_val){
            min_ind=i;
            min_val=arr[i];
        }
    }
    return min_ind;
}

int main(){
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++){
        int ind = selection_prs(arr,i,n);
        swap_val(arr,i,ind);
    }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;

}