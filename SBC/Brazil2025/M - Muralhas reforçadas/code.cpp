#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;
    cin >> n >> k;
    vector<ll> v(n);

    int min_index;
    ll min_value = LLONG_MAX;

    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        v[i] = x;
        if (x < min_value)
        {
            min_value = x;
            min_index = i;
        }
    }

    ll new_min_value = min_value + k;
    int index = min_index;
    for (int i = min_index + 1; i < min_index + k; i++)
    {
        if (i < 0 || i >= n)
            break;

        int diff = i - min_index;
        if (v[i] < new_min_value)
        {
            if (v[min_index] + (k - diff) > v[i])
            {
                index = i;
                new_min_value = v[min_index] + (k - diff);
            }
        }
    }

    ll add = k;
    for (int i = index; i > index - k; i--)
    {
        if (i < 0 || i >= n)
            break;

        v[i] += add--;
    }

    ll res = *min_element(v.begin(), v.end());

    cout << res << endl;
    return 0;
}