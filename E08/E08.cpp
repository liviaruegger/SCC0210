#include <iostream>
#include <stack>

using namespace std;

stack<int> numbers1, numbers2;
stack<char> operators1, operators2;

long maximum()
{
    stack<int> temp;

    int a, b, c;
    char op;

    // Somar:
    while (numbers1.size() >= 2)
    {
        a = numbers1.top();
        numbers1.pop();

        b = numbers1.top();
        numbers1.pop();

        op = operators1.top();
        if (op == '+')
        {
            c = a + b;
            numbers1.push(c);
        }
        else if (op == '*')
        {
            temp.push(a);
            numbers1.push(b);
        }
        operators1.pop();
    }
    
    long max = numbers1.top();
    numbers1.pop();

    // Multiplicar:
    while (!temp.empty())
    {
        max *= temp.top();
        temp.pop();
    }

    return max;
}

int minimum()
{
    stack<int> temp;

    int a, b, c;
    char op;

    // Multiplicar:
    while (numbers2.size() >= 2)
    {
        a = numbers2.top();
        numbers2.pop();

        b = numbers2.top();
        numbers2.pop();

        op = operators2.top();
        if (op == '*')
        {
            c = a * b;
            numbers2.push(c);
        }
        else if (op == '+')
        {
            temp.push(a);
            numbers2.push(b);
        }
        operators2.pop();
    }
    
    int min = numbers2.top();
    numbers2.pop();

    // Somar:
    while (temp.size() >= 1)
    {
        min += temp.top();
        temp.pop();
    }

    return min;
}

void test()
{
    bool is_integer = true;
    char c = '$'; // Inicializando com valor qualquer

    while (c != '\n')
    {
        if (is_integer)
        {
            int number;
            scanf("%d", &number);
            numbers1.push(number);
            numbers2.push(number);
            is_integer = false; // O próximo será operador ou '\n'
        }
        else
        {
            c = getchar();
            if (c == '+' or c == '*')
            {
                operators1.push(c);
                operators2.push(c);
                is_integer = true;
            }
        }
    }

    long max = maximum();
    int min = minimum();

    printf("The maximum and minimum are %ld and %d.\n", max, min);
}

int main()
{
    int n_of_test_cases;
    cin >> n_of_test_cases;

    for (int i = 0; i < n_of_test_cases; i++)
        test();
    
    return 0;
}