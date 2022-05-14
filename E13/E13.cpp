#include <iostream>

using namespace std;

int cost(int *stones, int n1, int n2)
{
    return abs(stones[n1] - stones[n2]);
}

int main()
{
    int n;
    cin >> n;

    int *stones = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        cin >> stones[i];

    int opt[n];

    opt[0] = 0;
    opt[1] = abs(stones[0] - stones[1]);

    for (int i = 2; i < n; i++)
        opt[i] = min(opt[i - 1] + cost(stones, i - 1, i), opt[i - 2] + cost(stones, i - 2, i));

    cout << opt[n - 1] << endl;

    free(stones);

    return 0;
}