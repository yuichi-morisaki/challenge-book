// Programming Contest Challenge Book - Page 23
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int L = 0;
    int n = 0;
    cin >> L >> n;
    vector<int> x;
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }

    int min_t = 0;
    int max_t = 0;
    for (int i = 0; i < n; ++i) {
        min_t = max(min_t, min(x[i], L-x[i]));
        max_t = max(max_t, max(x[i], L-x[i]));
    }

    cout << min_t << '\n'
         << max_t << '\n';

    return 0;
}
