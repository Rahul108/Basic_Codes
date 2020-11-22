#include<bits/stdc++.h>
using namespace std;

int sum(int arr[],int n){
    int sm(0), ind(0);
    bk:
        sm+=arr[ind];
        ind++;
        if(ind<n)
            goto bk;
    return sm;
}

int main()
{
    int n;
    cin>>n;
    int arr[n+1];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<sum(arr,n);
}
