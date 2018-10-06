#include <bits/stdc++.h>
using namespace std;
vector <int> adj[100];
vector <int> visited(100,0);
void dfs(int s)
{
    visited[s] = 1;
    cout<<s<<" ";
    for(int i=0 ; i<adj[s].size();i++)
    {
        if(visited[adj[s][i]] == 0)
        dfs(adj[s][i]);
    }
}
int main()
{
    int v,e,a,b;
    cin>>v;
    cin>>e;
    while(e--)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=v;i++)
    {
        cout<<"Adjacency list of "<<i<<" : ";
        for(int j=0;j<adj[i].size();j++)
        {
            if(j!=adj[i].size()-1)
               cout<<adj[i][j]<<"->";
            else
               cout<<adj[i][j]<<endl;
        }
    }
    dfs(1);
    return 0;
    }