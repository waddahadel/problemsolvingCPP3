#include <bits/stdc++.h>
using namespace std;

#define debug(x) (cerr << #x << ": " << (x) << endl)

int main()
{
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;

    vector<vector<int>> tray(h, vector<int>(w));
    vector<vector<int>> prefix_sum(h + 1, vector<int>(w + 1, 0));

    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> tray[i][j];
            prefix_sum[i + 1][j + 1] = prefix_sum[i + 1][j] + prefix_sum[i][j + 1] - prefix_sum[i][j] + tray[i][j];
        }
    }

    int H, W;
    cin >> H >> W;

    bool found = false;
    for (int i = 0; i <= h - H; ++i)
    {
        for (int j = 0; j <= w - W; ++j)
        {
            int sum = prefix_sum[i + H][j + W] - prefix_sum[i][j + W] - prefix_sum[i + H][j] + prefix_sum[i][j];
            if (sum == 0)
            {
                cout << i + 1 << " " << j + 1 << " " << i + H << " " << j + W << endl;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }

    if (!found)
        cout << "-1 -1 -1 -1" << endl;

    return 0;
}