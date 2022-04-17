#include <iostream>
#include <algorithm>

#define MAX_N 20000
#define MAX_M 20000

using namespace std;

int heads[MAX_N];
int knights[MAX_M];

void test(int n, int m)
{   
    int i;
    for (i = 0; i < n; i++)
        cin >> heads[i];
    for (i = 0; i < m; i++)
        cin >> knights[i];

    sort(heads, heads + n);
    sort(knights, knights + m);

    int min_amount_of_gold = 0;
    int remaining_heads = n;

    int j = 0;
    for (i = 0; i < n; i++)
    {
        while (j < m)
        {
            if (knights[j] >= heads[i])
            {
                min_amount_of_gold += knights[j];
                remaining_heads--;
                j++;
                break;
            }

            j++;
        }
    }

    if (remaining_heads > 0)
        cout << "Loowater is doomed!" << endl;
    else
        cout << min_amount_of_gold << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;

    while (!(n == 0 && m == 0))
    {
        test(n, m);
        cin >> n >> m;
    }

    return 0;
}