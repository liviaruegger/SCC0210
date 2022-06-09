#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    long n;
    cin >> n;

    vector<long> divisors;

    for (long i = 1; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            divisors.push_back(n / i);
        }
    }

    sort(divisors.begin(), divisors.end());

    for (auto i: divisors)
        cout << i << ' ';

    return 0;
}