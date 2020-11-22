// Programming Contest Challenge Book - Page 8 (and 25)
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool solve(int, int, vector<int>);
bool solve_r(int, int, vector<int>);
bool solve_r2(int, int, vector<int>);

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;
    vector<int> k;
    for (int i = 0; i < n; ++i) {
        int tmp = 0;
        cin >> tmp;
        k.push_back(tmp);
    }

    // bool winnable = solve(n, m, k);
    // bool winnable = solve_r(n, m, k);
    bool winnable = solve_r2(n, m, k);

    if (winnable)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}

bool solve(int n, int m, vector<int> k)
{
    bool winnable = false;
    for (int a = 0; a < n; ++a)
        for (int b = 0; b < n; ++b)
            for (int c = 0; c < n; ++c)
                for (int d = 0; d < n; ++d) {
                    if (k[a] + k[b] + k[c] + k[d] == m)
                        winnable = true;
                }
    return winnable;
}

bool solve_r(int n, int m, vector<int> k)
{
    sort(k.begin(), k.end());
    for (int a = 0; a < n; ++a)
        for (int b = 0; b < n; ++b)
            for (int c = 0; c < n; ++c) {
                int x = m - k[a] - k[b] - k[c];
                bool winnable = binary_search(k.begin(), k.end(), x);
                if (winnable)
                    return true;
            }
    return false;
}

bool solve_r2(int n, int m, vector<int> k)
{
    vector<int> kk;
    for (int c = 0; c < n; ++c)
        for (int d = 0; d < n; ++d)
            kk.push_back(k[c] + k[d]);
    sort(kk.begin(), kk.end());

    for (int a = 0; a < n; ++a)
        for (int b = 0; b < n; ++b) {
            int x = m - k[a] - k[b];
            bool winnable = binary_search(kk.begin(), kk.end(), x);
            if (winnable)
                return true;
        }
    return false;
}
