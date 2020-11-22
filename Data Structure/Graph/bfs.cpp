#include<bits/stdc++.h>
using namespace std;

//MARCOS://N
typedef     long long int ll;
typedef     pair<int, int> pii;
typedef     vector<int> vi;
typedef     vector<vi> vvi;
typedef     vector<bool> vp;

#define     MAX            1000001
#define     x              first
#define     y              second
#define     present(c,x)   ((c).find(x) != (c).end())
#define     cpresent(c,x)  (find(all(c),x) != c.end())
#define     sz(a)          int((a).size())
#define     pb             push_back
#define     all(c)         (c).begin(),(c).end()
#define     tr(c,i)        for(typeof(c).begin() i=(c).begin(); i!=(c).end(); i++)
#define     mem(p)         memset(p,0,sizeof(p))
#define     memf(p)        memset(p,0x3f,sizeof(p))
#define     memn(p)        memset(p,-1,sizeof(p))
#define     Complete       ios_base::sync_with_stdio(0);
#define     Asshole        cin.tie(NULL);


//cin.ignore(numeric_limits<streamsize>::max(), '\n') //ignore spaces, use new line as delimiter;


//ll a[MAX],k(0);
/*
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
*/

vp v;
vvi g;

void edge(int a, int b){
    g[a].pb(b);
    g[b].pb(a);
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    v[u]=true;

    while(!q.empty()){
        int f=q.front();
        q.pop();
        cout<<f<<" ";

        for(int i=0;i<g[f].size();i++){
            if(v[g[f][i]]==false){
                q.push(g[f][i]);
                v[g[f][i]]=true;
            }
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    v.assign(n,false);
    g.assign(n,vector<int>());

    int a,b;

    for(int i=0;i<e;i++){
        cin>>a>>b;
        edge(a,b);
    }

    for(int i=0;i<n;i++){
        if(!v[i])
            bfs(i);
    }

    return 0;
}
