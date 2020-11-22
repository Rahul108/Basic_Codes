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


#define V 9


int minDistance(int dist[], bool sptSet[]){
    int min=INT_MAX;
    int min_index;
    for(int i=0;i<V;i++){
        if(sptSet[i]==false && dist[i]<=min){
            min=dist[i];
            min_index=i;
        }
    }
    return min_index;
}

void printSolutions(int dist[]){
    for(int i=0;i<V;i++){
        cout<<i<<"  "<<dist[i]<<endl;
    }
}

void dijkstra(int graph[V][V], int src){
    int dist[V];
    bool sptSet[V];

    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
        sptSet[i]=false;
    }

    dist[src]=0;

    for(int i=0;i<V-1;i++){
        int u=minDistance(dist,sptSet);
        sptSet[u]=true;
        for(int j=0;j<V;j++){
            if(!sptSet[j] && graph[i][j] && dist[i]!=INT_MAX && (dist[i]+graph[i][j]<dist[j]) )
                dist[j]=dist[i]+graph[i][j];
        }
    }
    printSolutions(dist);
}

int main(){
    int graph[V][V]={   { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 }     };

    dijkstra(graph,0);

    return 0;
}
