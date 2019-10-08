#include<bits/stdc++.h>
using namespace std;
#define v 4
#define INF 99999
void printsol(int dist[][v]);
void floyd(int graph[][v])
{
int dist[v][v];
for(int i=0;i<v;i++)
{
for(int j=0;j<v;j++)
{
dist[i][j]=graph[i][j];
}
}
for(int k=0;k<v;k++)
for(int i=0;i<v;i++)
for(int j=0;j<v;j++)
if(dist[i][k]+dist[k][j]<dist[i][j])
dist[i][j]=dist[i][k]+dist[k][j];
printsol(dist);
}
void printsol(int dist[][v])
{
for(int i=0;i<v;i++)
{for(int j=0;j<v;j++)
{if(dist[i][j]== INF )
cout<<"INF"<<"\t";
else cout<<dist[i][j]<<' ';
}cout<<endl;
}}
int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[v][v] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

    // Print the solution
    floyd(graph);
    return 0;
}
