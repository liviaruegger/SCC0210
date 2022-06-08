#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int n)
{
    if (n == 1) return false;
    if (n == 2) return true;

    for (int i = 2; i < sqrt(n) + 1; i++)
    {
        if (n % i == 0) return false;
    }
    
    return true;
}

int main()
{
    long n;
    cin >> n;
    
    string result;
    
    if (is_prime(n)) result = "YES";
    else result = "NO";

    cout << result;

    return 0;
}