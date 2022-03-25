#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n_tests;
    cin >> n_tests;
    
    stack<int> s;
    
    for (int i = 0; i < n_tests; i++)
    {
        int stack_size;
        cin >> stack_size;
        
        for (int j = 0; j < stack_size; j++)
        {
            int x;
            cin >> x;
            
            s.push(x);
        }
        
        while (!s.empty())
        {
            cout << s.top() << endl;
            s.pop();
        }
        
        if (i < n_tests - 1) cout << endl;
    }

    return 0;
}