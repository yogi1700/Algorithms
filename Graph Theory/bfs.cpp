#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v,e,a,b;
    cin>>v;
    vector <int> adj[v+1];
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
    queue <int> q; 
    vector <bool> visited(v+1,false);
    vector <int> d(v+1,false);
    int s = 1;
    visited[s] = true;
    d[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        for(int i=0; i<adj[x].size();i++)
        {
            int ver = adj[x][i];
            if(visited[ver] == false)
            {
                visited[ver] = true;
                q.push(ver);
                d[ver] = d[x] + 1;
            }
        }
    }
    cout<<endl;
    for(int i=1; i<= v;i++)
    cout<<d[i]<<" ";
    return 0;
    }