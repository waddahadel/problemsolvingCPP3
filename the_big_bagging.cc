#include <bits/stdc++.h>
using namespace std;

#define debug(x) (cerr << #x << ": " << (x) << endl)

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> wine_per_day(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> wine_per_day[i];
    }

    vector<int> max_bottles(n, 0);

    // Calculate the maximum number of bottles that can be obtained starting from each day
    for (int i = n - 1; i >= 0; --i)
    {
        max_bottles[i] = wine_per_day[i];
        if (i + m < n)
        {
            max_bottles[i] += max_bottles[i + m];
        }
        if (i + 1 < n)
        {
            max_bottles[i] = max(max_bottles[i], max_bottles[i + 1]); // Corrected line
        }
    }

    vector<int> best_days;
    int current_day = 0;

    // Find the sequence of days to ask for wine to maximize the total number of bottles
    while (current_day < n)
    {
        int max_bottles_day = max_bottles[current_day];
        int best_day = current_day;
        // Look for the next best day within the next m days
        for (int i = current_day + 1; i < min(n, current_day + m); ++i)
        {
            if (max_bottles[i] > max_bottles_day)
            {
                max_bottles_day = max_bottles[i];
                best_day = i;
            }
        }
        best_days.push_back(best_day + 1); // Add 1 to convert 0-based index to 1-based index
        current_day = best_day + m;        // Move to the next valid starting day for asking wine
    }

    // Output the result
    cout << max_bottles[0] << " " << best_days.size() << endl;
    for (int day : best_days)
    {
        cout << day << " ";
    }
    cout << endl;

    return 0;
}
