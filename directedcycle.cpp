#include<iostream>
#include<vector> 
using namespace std;

int solve(int s,vector<vector<int>> &adj,vector<int> &vis,vector<int> &dfx,vector<int> &path)
{
    vis[s]=1;
    dfx[s]=1;
    path.push_back(s);
    for(auto x : adj[s])
    {
        if(dfx[x]==1)
        {
            path.push_back(x);
            return 1;
        }
        if(vis[x]==1)
            continue;
        if(solve(x,adj,vis,dfx,path))
            return 1;
    }
    dfx[s]=0;
    path.pop_back();
    return 0;
}


int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<vector<int>> adj(n);
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
    }
    vector<int> vis(n,0);
    vector<int> dfx(n,0);
    vector<int> path;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            if(solve(i,adj,vis,dfx,path))
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
        int i=0;
        while(path[i]!=path[m-1])
            i++;
        cout<<m-i<<endl;
        while(i<m)
        {
            cout<<path[i]+1<<" ";
            i++;
        }
        cout<<endl;
    }

}
