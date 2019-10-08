#include<bits/stdc++.h>
using namespace std;
/*class graph{
int v;
list<int> *adj;
public:
graph(int v)
{
this->v=v;
adj=new list<int>[v];
}
void addEdge(int v,int w)
{
adj[v].push_back(w);}*/
#define v 9
int mindis(int dist[],bool sptset[])
{
int mini=999,min_index;
for(int i=0;i<v;i++)
{

if(sptset[i]==false && dist[i]<=mini)
{mini=dist[i];
min_index=i;
}}
return min_index;
}

void dijkstra(int graph[v][v],int s)
{
bool sptset[v];
int dist[v];
for(int i=0;i<v;i++)
{
sptset[i]=false;
dist[i]=999;
}
dist[s]=0;
for(int k=0;k<v-1;k++)
{
int u=mindis(dist,sptset);
sptset[u]=true;
for(int l=0;l<v;l++)
if(!sptset[l] && graph[u][l]&&dist[u]!=999 && dist[u]+graph[u][l]<dist[l])
dist[l]=dist[u]+graph[u][l];
}

for(int i=0;i<v;i++)
{
cout<<i<<"\t\t"<<dist[i] <<endl;
}
}




int main()
{
   /* Let us create the example graph discussed above */
   int graph[v][v] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}
