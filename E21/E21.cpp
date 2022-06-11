#include <iostream>

using namespace std;

int main()
{
    int t, n;
    cin >> t;

    for (int i = 0; i < t; i++) // Para cada querry
    {
        cin >> n;

        int divisible = 0;
        int remainder_1 = 0;
        int remainder_2 = 0;
        
        long x;

        for (int j = 0; j < n; j++) // Para cada número na querry
        {
            cin >> x;

            if      (x % 3 == 0) divisible++;
            else if (x % 3 == 1) remainder_1++;
            else if (x % 3 == 2) remainder_2++;
        }

        if (remainder_1 > remainder_2)
        {
            divisible   += remainder_2;
            remainder_1 -= remainder_2;
            remainder_2  = 0;
            
            divisible += remainder_1 / 3;
        }
        else if (remainder_2 >= remainder_1)
        {
            divisible   += remainder_1;
            remainder_2 -= remainder_1;
            remainder_1  = 0;

            divisible += remainder_2 / 3;
        }
        
        cout << divisible << endl;
    }
    
    return 0;
}