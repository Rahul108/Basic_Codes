#include<bits/stdc++.h>
using namespace std;

void prime_factor(int n){
    for(int i=2;i<=n;i++){
        if(n%i==0){
            cout<<i<<endl;
            prime_factor(n/i);
            break;
        }

    }
}

int main()
{
    int n;
    cin>>n;
    prime_factor(n);
}
