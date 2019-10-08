#include<bits/stdc++.h>
using namespace std;
int bellman(int g[20][20],int V,int E,int edge[20][2])
{int s;
int i,u,v,dist[20],parent[20],f;
for(int i=0;i<V;i++)
{dist[i]=999;
parent[i]=-1;
}
cout<<"source :"<<endl;
cin>>s;
dist[s-1]=0;
for(int i=0;i<V-1;i++)
{
for(int k=0;k<E;k++)
{
u=edge[k][0],v=edge[k][1];
if(dist[u]+g[u][v]<dist[v])
dist[v]=dist[u]+g[u][v];

}
}
for(int k=0;k<E;k++)
{u=edge[k][0],v=edge[k][1];
if(dist[u]+g[u][v]<dist[v])
f=0;}
if(f)
{

for(int i=0;i<V;i++)
cout<<"Vertex :"<<i+1<<"Distance :"<<dist[i]<<"Parent :"<<parent[i]+1<<endl;
return f;
}
}
int main()
{
    int V,edge[20][2],G[20][20],i,j,k=0;
    cout<<"Enter no. of vertices: ";
    cin>>V;
    cout<<"Enter graph in matrix form:";
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
        {
            cin>>G[i][j];
            if(G[i][j]!=0)
                edge[k][0]=i,edge[k++][1]=j;
        }

    if(bellman(G,V,k,edge))
        cout<<"No negative weight cycle";
    else
    cout<<"Negative weight cycle exists";
    return 0;}
