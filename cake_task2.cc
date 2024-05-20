#include <bits/stdc++.h>
using namespace std;

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

    int H;
    cin >> H;

    int max_width = 0;
    int max_i = -1, max_j = -1;
    for (int i = 0; i <= h - H; ++i)
    {
        int width = 0;
        for (int j = 0; j < w; ++j)
        {
            if (prefix_sum[i + H][j + 1] - prefix_sum[i][j + 1] - prefix_sum[i + H][j] + prefix_sum[i][j] == 0)
            {
                width++;
                if (width > max_width)
                {
                    max_width = width;
                    max_i = i;
                    max_j = j - width + 1;
                }
            }
            else
            {
                width = 0;
            }
        }
    }

    if (max_i == -1)
    {
        cout << "-1 -1 -1 -1" << endl;
    }
    else
    {
        cout << max_i + 1 << " " << max_j + 1 << " " << max_i + H << " " << max_j + max_width << endl;
    }

    return 0;
}