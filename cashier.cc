#include <bits/stdc++.h>
using namespace std;

#define debug(x) (cerr << #x << ": " << (x) << endl)

int main()
{
    int C, N;
    cin >> C >> N;

    vector<int> coins(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> coins[i];
    }

    vector<int> dp(C + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= C; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[C] == INT_MAX)
    {
        cout << "impossible" << endl;
    }
    else
    {
        cout << dp[C] << endl;
    }

    return 0;
}