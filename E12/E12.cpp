#include <bits/stdc++.h>

using namespace std;

void test(bool *passed, vector<int> a, int prettiness)
{
    int sum = accumulate(a.begin(), a.end(), 0);
    
    // Caso base 1
    if (sum == prettiness)
    {
        *passed = true;
        return;
    }

    // Caso base 2
    if (a.size() <= 1)
        return;

    int max = *max_element(a.begin(), a.end());
    int min = *min_element(a.begin(), a.end());
    int mid = (max + min) / 2;

    // Caso base 3
    if ((int)count(a.begin(), a.end(), mid) == (int)a.size())
        return;

    vector<int> left;
    vector<int> right;

    for (auto & element : a) 
    {
        if (element <= mid) left.push_back(element);
        else right.push_back(element);
    }

    test(passed, left, prettiness);
    test(passed, right, prettiness);
}

int main()
{
    vector<int> a;
    
    int n_test_cases;
    cin >> n_test_cases;
    
    for (int t = 0; t < n_test_cases; t++) // Cada caso teste
    {
        int n, q;
        cin >> n >> q;

        int temp;
        for (int i = 0; i < n; i++) // Lê array
        {
            cin >> temp;
            a.push_back(temp);
        }

        int prettiness;
        for (int i = 0; i < q; i++) // Cada teste de beleza
        {
            cin >> prettiness;

            bool passed = false;
            test(&passed, a, prettiness);

            if (passed) cout << "Yes" << endl;
            else cout << "No" << endl;
        }

        a.clear();
    }

    return 0;
}