#include<bits/stdc++.h>

using namespace std;

int main()
{
  int T;
  cin>>T;
  while(T--)
  {
    int N,V;
    cin>>N>>V;
    vector<int> adj[N];
    bool vis[N] = {false};

    for(int i=0;i<V;i++)
    {
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
    }
    dfs(0,adj,vis,N)

  }


  return 0;
}

void dfs(int s,std::vector<int> adj[],bool vis[],int N)
{
  vis[s] = true;
  stack <int> s;
  s.push(s);
  while(!s.empty())
  {
    k = s.top()
    vis[k] = true;
    cout<<k<<" ";
    s.pop()
    for(int i=0;i<adj[k].size();i++)
    {
      if(!vis[adj[k][i]])
      {
        vis[adj[k][i]] = true;
        s.push(adj[k][i]);
      }
    }
  }
}
