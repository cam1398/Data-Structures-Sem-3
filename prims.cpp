#include<bits/stdc++.h>
using namespace std;
#define v 5
int findmin(bool mstset[],int dist[])
{
int mini=999,min_index;
for(int i=0;i<v;i++)
{
if(mstset[i]==false && dist[i]<mini)
{
mini=dist[i];
min_index=i;
}

}return min_index;
}
void prims(int graph[v][v])
{
int dist[v];
bool mstset[v];int parent[v];
for(int i=0;i<v;i++)
{
mstset[i]=false;
dist[i]=999;
}
parent[0]=-1;
dist[0]=0;
for(int i=0;i<v-1;i++)
{
int u=findmin(mstset,dist);
mstset[u]=true;
for(int l=0;l<v;l++)
{
if(mstset[l]==false &&graph[u][l] && graph[u][l]<dist[l] )
{
parent[l]=u;
dist[l]=graph[u][l];
}

}
}cout<<"Edge \t Weight"<<endl;
for(int i=1;i<v;i++)
{cout<<parent[i]<<"-"<<i<<"\t"<<graph[i][parent[i]]<<endl;
}
}
int main()
{
/* Let us create the following graph
        2 3
    (0)--(1)--(2)
    | / \ |
    6| 8/ \5 |7
    | /     \ |
    (3)-------(4)
            9         */
int graph[v][v] = {{0, 2, 0, 6, 0},
                    {2, 0, 3, 8, 5},
                    {0, 3, 0, 0, 7},
                    {6, 8, 0, 0, 9},
                    {0, 5, 7, 9, 0}};

    // Print the solution
    prims(graph);

    return 0;
}
