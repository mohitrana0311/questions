#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        map<pair<int, int>, int> mp;
        vector<pair<int, int>> rare(k);
        for (int i = 0; i < k; i++)
        {
            cin >> rare[i].first;
            cin >> rare[i].second;
            rare[i].first--;
            rare[i].second--;
            mp[rare[i]]++;
        }

        vector<vector<int>> roads(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> roads[i][j];
            }
        }

        int res = 1e9;
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (roads[i][j] == 1 && !mp.count({i, j}))
                {
                    vector<vector<bool>> visited(n, vector<bool>(n, false));
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    int ans = 0;
                    int cnt = 0;
                    while (!q.empty())
                    {
                        int x = q.size();
                        while (x--)
                        {
                            auto it = q.front();
                            q.pop();
                            int p1 = it.first;
                            int q1 = it.second;
                            if (mp.count({p1, q1}))
                                cnt++;
                            for (int k = 0; k < 4; k++)
                            {
                                int i1 = p1 + dir[k][0];
                                int j1 = q1 + dir[k][1];
                                if (i1 >= 0 && j1 >= 0 && i1 < n && j1 < n && !visited[i1][j1] && roads[i1][j1] == 1)
                                {
                                    visited[i1][j1] = true;
                                    q.push({i1, j1});
                                }
                            }
                        }
                        if (cnt == k)
                        {
                            res = min(res, ans);
                            break;
                        }
                        ans++;
                    }
                }
            }
        }

        cout << res << endl;
    }
}