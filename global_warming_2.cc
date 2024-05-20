#include <bits/stdc++.h>
using namespace std;

#define debug(x) (cerr << #x << ": " << (x) << endl)

int longestIncreasingSubsequence(const vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> temperatures(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> temperatures[i];
    }

    int maxLIS = longestIncreasingSubsequence(temperatures);

    // Consider cheating
    for (int i = 0; i < n; ++i)
    {
        temperatures[i] += x;
    }

    int result = max(maxLIS, longestIncreasingSubsequence(temperatures));
    cout << result << endl;

    return 0;
}