#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int remaining_coins = n;

    int i;
    for (i = 0; remaining_coins > 0; i++)
    {
        int j;
        for (j = 0; j < i + 1; j++)
        {
            if (remaining_coins > 0) remaining_coins--;
            else break;
        }
        
        if (!remaining_coins)
        {
            if (j == i + 1) i++;
            break;
        }
    }

    cout << i << endl;

    return 0;
}