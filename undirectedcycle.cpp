#include <iostream>
#include <vector>
using namespace std;


int solve(int s,int p,vector<vector<int>> &adj,vector<int> &vis,vector<int> &path)
{
    vis[s]=1;
    path.push_back(s);

    for(auto x : adj[s])
    {
        if(x==p)
            continue;
        if(vis[x]!=0)
        {
            path.push_back(x);
            return 1;
        }
        if(solve(x,s,adj,vis,path))
            return 1;
    }
    path.pop_back();
    return 0;

}

int main()
{
    int n;
    cin>>n;
    int e;
    cin>>e;

    vector<vector<int>> adj(n);
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x;
        cin>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }

    vector<int> vis(n,0);
    vector<int> path;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            if(solve(i,i,adj,vis,path))
            {
                break;
            }
        }
    }

    if(path.size()==0)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        int m = path.size();
        int p = path[m-1];
        int i=0;
        while(path[i]!=p)
        {
            i++;
        }
        cout<<m-i<<endl;
        while(i<m)
        {
            cout<<path[i]+1<<" ";
            i++;
        }
        cout<<endl;
    }

}
