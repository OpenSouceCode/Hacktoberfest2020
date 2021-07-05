// Author Apoorv Jain(ajtheb)
#include <bits/stdc++.h>
using namespace std;

struct Edge{
  int left,right,weight;
};
struct Nodes{
  int V,E;
  struct Edge* edge;
};

int main()
{
  int v,e;
  cin>>v>>e;

  struct Nodes* graph=new Nodes;
  graph->V=v;
  graph->E=e;
  graph->edge= new Edge[e];

  for(int i=0;i<e;i++)
  {
    int x,y,z;
    cin>>x>>y>>z;
    graph->edge[i].left=x;
    graph->edge[i].right=y;
    graph->edge[i].weight=z;
  }

  int dist[v];

  for (int i = 0; i < v; i++)
      dist[i] = INT_MAX;
  dist[0] = 0;

  for (int i = 1; i <= v - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = graph->edge[j].left;
            int v = graph->edge[j].right;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int u = graph->edge[i].left;
        int v = graph->edge[i].right;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            printf("Negative edge");
            break;
        }
    }
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < v; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
    return 0;
}
