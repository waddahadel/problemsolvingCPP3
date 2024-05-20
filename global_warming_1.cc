#include <bits/stdc++.h>
using namespace std;

#define debug(x) (cerr << #x << ": " << (x) << endl)

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> temperatures(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> temperatures[i];
    }

    vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (temperatures[i] > temperatures[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int longest_lis = *max_element(dp.begin(), dp.end());
    cout << longest_lis << endl;

    return 0;
}