#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// #define INT_MAX 100000;

int xb, yb, xt, yt;

int fun(vector<vector<int>> &dp, int N, int M, int k)
{
    int msum = INT_MAX;
    for (int i = 0; i <= N - k; i++)
    {
        for (int j = 0; j <= M - k; j++)
        {
            int sum = dp[i + k][j + k] - dp[i + k][j] - dp[i][j + k] + dp[i][j];
            if (sum < msum)
            {
                msum = sum;
                if (msum <= 1)
                {
                    xb = i + k;
                    yb = j + 1;
                    xt = i + 1;
                    yt = j + k;
                }
            }
        }
    }
    return msum;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    /* input */
    
    int N, M;
    cin >> N >> M;

    vector<vector<int>> A(N, vector<int>(M, 0));

    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int x, y;
        cin >> x >> y;
        A[x - 1][y - 1] = 1;
    }

    vector<vector<int>> dp(1001, vector<int>(1001, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + A[i - 1][j - 1];
        }
    }
    int l = 1, r = min(M, N);
    int ones;
    while (l < r)
    {
        int mid = (l + r) / 2;
        ones = fun(dp, N, M, mid);
        if (ones > 1)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << xb << " " << yb << " " << xt << " " << yt << endl;
    return 0;
}