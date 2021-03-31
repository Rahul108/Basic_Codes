#include<bits/stdc++.h>
using namespace std;

vector<int> edge[100],cost[100];
const int infinity = 100000000;

int bfs(int source,int destination) {
  int d[100];
  for(int i=0;i<100;i++)
        d[i]=infinity;

  queue<int> q;
  q.push(source);
  d[source] = 0;

  while(!q.empty())
  {
      int u=q.front();
      q.pop();
      for(int i=0;i<edge[u].size();i++)
      {
          int v = edge[u][i];
          if(d[v] > d[u] + cost[u][i])
          {
              d[v] = d[u] + cost[u][i];
              q.push(v);
          }
      }
  }

return d[destination];
}


int main()
{
    int a,b;
    cin>>a>>b;
    bfs(a,b);
}
