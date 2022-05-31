#include <iostream>
#include <vector>

using namespace std;

typedef vector<long int> vector_t;
typedef vector<vector_t> matrix_t;

int main()
{
    int n, w;
    cin >> n >> w;

    int value[n];
    int weight[n];
    for (int i = 0; i < n; i++)
        cin >> weight[i] >> value[i];

    vector_t row(w + 1);
    matrix_t max_value;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
            row[j] = 0;
        max_value.push_back(row);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (weight[i] <= j)
                max_value[i + 1][j] = max(max_value[i][j], max_value[i][j - weight[i]] + value[i]);
            else
                max_value[i + 1][j] = max_value[i][j];
        }
    }

    cout << max_value[n][w] << endl;

    return 0;
}