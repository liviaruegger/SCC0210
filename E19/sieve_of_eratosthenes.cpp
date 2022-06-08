#include <iostream>
#include <bitset>
#include <cmath>

#define MAX 1000000000
#define ll long long

using namespace std;

bitset<MAX> is_prime;

void remove_multiples_until(int N)
{
    is_prime.set(); // Seta todos os bits para 1
    
    is_prime.reset(0);
    is_prime.reset(1);

    for (ll n = 2; n < sqrt(N) + 1; n++)
    {
        if (is_prime.test(n))
        {
            for (ll j = 2 * n; j < N; j += n)
            {
                is_prime.reset(j);
            }
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    
    remove_multiples_until(n + 1);
    
    string result;

    if (is_prime.test(n)) result = "YES";
    else result = "NO";

    cout << result;

    return 0;
}