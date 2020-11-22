#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> gl;
    for(int i=0;i<5;i++)
        gl.push_back(i);
    for(auto i=gl.begin(); i!= gl.end(); i++)
        cout << *i << endl;
    cout << endl;
    for(auto i=gl.begin();i!=gl.end();i++)
        cout << *i << endl;
    cout << endl;
    for(auto i=gl.rbegin();i!=gl.rend();i++)
        cout << *i << endl;
    cout << endl;
    for(auto i=gl.crbegin();i!=gl.crend();i++)
        cout << *i << endl;

}