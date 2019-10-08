#include<bits/stdc++.h>
using namespace std;
class graph{
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
adj[v].push_back(w);}

void dfsutil(int s,bool visi[])
{
visi[s]=true;
cout<<s<<' ';
for(auto i=adj[s].begin();i!=adj[s].end();i++)
if(!visi[*i])
dfsutil(*i,visi);

}

void dfs(int s)
{
bool *visited=new bool[v];
for(int i=0;i<v;i++)
visited[i]=0;
dfsutil(s,visited);
}


};

int main()
{
graph g(4);
 g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.dfs(2);

    return 0;
}

