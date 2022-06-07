#include <iostream>

#define MAX 3000

using namespace std;

int n, m;
string str1, str2;
int memo[MAX][MAX];

int length_of_LCS(int i, int j)
{
    // Caso base: chegou ao fim de uma das strings
    if (i >= n || j >= m) return 0;

    // Caso base: valor já foi calculado
    if (memo[i][j] != -1) return memo[i][j];

    int curr_len = max(length_of_LCS(i + 1, j), length_of_LCS(i, j + 1));

    if (str1[i] == str2[j])
        curr_len = max(curr_len, 1 + length_of_LCS(i + 1, j + 1));

    // Terminou a recursão -> registra o valor calculado
    memo[i][j] = curr_len;

    return curr_len;
}

string recover_LCS()
{
    string LCS;
    
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (memo[i][j] == memo[i + 1][j])
        {
            i++;
        }
        else if (memo[i][j] == memo[i][j + 1])
        {
            j++;
        }
        else // memo[i][j] == 1 + memo[i + 1][j + 1]
        {
            LCS.push_back(str1[i]);
            i++;
            j++;
        }
    }

    return LCS;
}

int main()
{
    cin >> str1 >> str2;

    n = str1.length();
    m = str2.length();

    // Inicializa a matriz que guardará os valores já calculados
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            memo[i][j] = -1;

    // Constrói a matriz memo[MAX][MAX]
    length_of_LCS(0, 0);

    cout << recover_LCS() << endl;

    return 0;
}