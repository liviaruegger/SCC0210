#include <iostream>
#include <set>

using namespace std;

void test_case()
{
    int n_snowflakes;
    cin >> n_snowflakes;

    int stream[n_snowflakes];
    for (int i = 0; i < n_snowflakes; i++)
        cin >> stream[i];

    set<int> snowflakes;

    int largest = 0;
    int begin = 0;
    int end = 0;

    while (end < n_snowflakes)
    { 
        while (end < n_snowflakes && !snowflakes.count(stream[end]))
        {
            snowflakes.insert(stream[end]);
            end++;
        }

        largest = max(largest, end - begin);

        while (snowflakes.count(stream[end]))
        {
            snowflakes.erase(stream[begin]);
            begin++;
        }
    }

    cout << largest << endl;
}

int main()
{
    int n_test_cases;
    cin >> n_test_cases;

    for (int i = 0; i < n_test_cases; i++)
        test_case();

    return 0;
}