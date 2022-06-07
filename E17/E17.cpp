#include <iostream>

#define MAX_N 2000
#define MAX_M 2000

using namespace std;

int n, m;
int price[26];
string str1, str2;

int values[MAX_N][MAX_M];

int most_expensive_subseq(int i, int j)
{
    // Caso base: chegou ao fim de uma das strings
    if (i >= n || j >= m) return 0;

    // Caso base: valor já foi calculado
    if (values[i][j] != -1) return values[i][j];

    int value;
    if (str1[i] == str2[j])
        value = price[str1[i] - 97] + most_expensive_subseq(i + 1, j + 1);
    else
        value = max(most_expensive_subseq(i, j + 1), most_expensive_subseq(i + 1, j));

    // Terminou a recursão -> registra o valor calculado
    values[i][j] = value;

    return value;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < 26; i++)
        cin >> price[i];

    cin >> str1 >> str2;

    // Inicializa a matriz que guardará os valores já calculados
    for (int i = 0; i < MAX_N; i++)
        for (int j = 0; j < MAX_M; j++)
            values[i][j] = -1;

    cout << most_expensive_subseq(0, 0);

    return 0;
}