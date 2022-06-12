#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long x_1, x, prev;
    cin >> x_1;
    x = x_1;

    set<long> dist;

    for (int i = 0; i < n - 1; i++)
    {
        prev = x;
        cin >> x;

        dist.insert(x - prev);
    }

    long total_dist = x - x_1;
    long min_dist = *dist.begin();

    for (auto i : dist)
    {
        if (i % min_dist != 0) min_dist = __gcd(min_dist, i);
    }

    long n_trees = (total_dist / min_dist) + 1;
    cout << n_trees - n;

    return 0;
}