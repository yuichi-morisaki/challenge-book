// Programming Contest Challenge Book - Page 21
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    int result = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            for (int k = j+1; k < n; ++k) {
                int perimeter = a[i] + a[j] + a[k];
                int longest = max(a[i], max(a[j], a[k]));
                if (perimeter > 2 * longest && perimeter > result)
                    result = perimeter;
            }
    cout << result << '\n';

    return 0;
}
