#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int points[n][3];
    for (int i = 0; i < n; i++)
        cin >> points[i][0] >> points[i][1] >> points[i][2];

    int max_points[n][3];
    for (int i = 0; i < 3; i++)
        max_points[0][i] = points[0][i];

    for (int i = 1; i < n; i++)
    {
        max_points[i][0] = points[i][0] + max(max_points[i - 1][1], max_points[i - 1][2]);
        max_points[i][1] = points[i][1] + max(max_points[i - 1][0], max_points[i - 1][2]);
        max_points[i][2] = points[i][2] + max(max_points[i - 1][0], max_points[i - 1][1]);
    }

    cout << *max_element(max_points[n - 1], max_points[n - 1] + 3) << endl;

    return 0;
}