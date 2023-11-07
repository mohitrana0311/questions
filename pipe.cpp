#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int  t;
	cin>>t;
	vector<vector<int>>dirj = {{} , {-1 , 1 } ,{} , {-1 , 1} , {1} , {1} , {-1} , {-1}};
	vector<vector<int>>diri = {{} , {-1 , 1} , {-1, 1} , {} ,  {-1} , {1} , {1} , {-1}};
	while(t--)
	{
		int n , m , r , c , l;
		cin>>n>>m>>r>>c>>l;
		vector<vector<int>>mat(n , vector<int>(m));
		for(int i = 0; i< n; i++)
		{
			for(int j = 0; j< m; j++)
			cin>>mat[i][j];
		}
		int res = 0 ;
		queue<pair<int,int>> q;
		vector<vector<bool>>visited(n , vector<bool>(m , false));
		
		if(mat[r][c] != 0)
		{
			q.push({r , c});
	 		visited[r][c]= true;
		}
		
		while(!q.empty() && l)
		{
			int p = q.size();
			res = res + p ;
			while(p--)
			{
				auto it = q.front();
				q.pop();
				int i = it.first;
				int j = it.second;
				
				int x = mat[i][j];
				for(auto a : diri[x])
				{
					int i1 = i+a;
					int j1 = j;
					if(i1>=0 && i1<n && mat[i1][j1] != 0 && !visited[i1][j1])
					{
						for(auto g : diri[mat[i1][j1]])
						{
							if(g== -a)
							{
							  visited[i1][j1]= true;
								q.push({i1 , j1});
								break;
							}
						}
						
					}
				}
				for(auto a : dirj[x])
				{
					int i1 = i;
					int j1 = j+a;
					if(j1>=0 && j1<m && mat[i1][j1] != 0 && !visited[i1][j1])
					{
						for(auto g : dirj[mat[i1][j1]])
						{
							if(g == -a)
							{
							  visited[i1][j1]= true;
								q.push({i1 , j1});
								break;
							}
						}
					}
				}
			}
			l--;
		}
 	 cout << res << endl;
	}
	return 0;
}