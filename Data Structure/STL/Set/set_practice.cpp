#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string s;
int hv(0),mhv(0);

int checksub(int f, int e){
    set<char> ss;
    for(int i=f;i<=e;i++){
        ss.insert(s[i]);
    }
    if(ss.size() == abs(e-f)+1){
        hv = ss.size();
        if(hv>mhv)
            mhv = hv;
    }
}

int main()
{
    cin >> s;

    for(int i=0;i<s.length();i++)
    {
        for(int j=i;j<s.length();j++){
            checksub(i,j);
        }
    }
    cout << mhv << endl;

}
