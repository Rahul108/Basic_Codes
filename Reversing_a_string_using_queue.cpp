#include<bits/stdc++.h>
using namespace std;

void rev_queue(queue<char>& s){
    if(s.empty())
        return;
    char data=s.front();
    s.pop();
    rev_queue(s);
    s.push(data);
}

int main()
{
    string s;
    cin>>s;
    queue<char> q;
    for(int i=0;i<s.length();i++)
        q.push(s[i]);
    rev_queue(q);
    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }
}
