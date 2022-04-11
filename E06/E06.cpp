#include <iostream>
#include <queue>

using namespace std;

void test(int n)
{
    priority_queue<int, vector<int>, greater<int>> numbers;

    int aux;
    for (int i = 0; i < n; i++)
    {
        cin >> aux;
        numbers.push(aux);
    }

    int a, b, total_cost = 0;
    while (numbers.size() >= 2)
    {
        a = numbers.top();
        numbers.pop();
        
        b = numbers.top();
        numbers.pop();
        
        aux = a + b;
        numbers.push(aux);
        total_cost += aux;
    }

    cout << total_cost << endl;
}

int main()
{
    int n;
    cin >> n;

    while (n != 0)
    {
        test(n);
        cin >> n;
    }

    return 0;
}