#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> vector_t;
typedef vector<vector_t> matrix_t;

int n, m;
int k;

matrix_t copy_grid(matrix_t original_grid)
{
    vector_t row(m);
    matrix_t copy;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            row[j] = original_grid[i][j];
        copy.push_back(row);
    }

    return copy;
}

void _check_grid(matrix_t copy, vector_t word, int index, int i, int j, bool *found_word)
{
    char c;
    if (index < k && i >= 0 && i < n && j >= 0 && j < m) c = word[index];
    else return;

    if (c == '.') return;

    if (index == k - 1) // Último caractere da palavra
    {
        if (copy[i][j] == c)
        {
            *found_word = true;
            return;
        }
    }

    if (copy[i][j] == c)
    {
        copy[i][j] = '.';
        
        _check_grid(copy_grid(copy), word, index + 1, i - 1, j, found_word); // Cima (i - 1, j)
        _check_grid(copy_grid(copy), word, index + 1, i + 1, j, found_word); // Baixo (i + 1, j)
        _check_grid(copy_grid(copy), word, index + 1, i, j - 1, found_word); // Esquerda (i, j - 1)
        _check_grid(copy_grid(copy), word, index + 1, i, j + 1, found_word); // Direita (i, j + 1)
    }
}

void check_grid(matrix_t original, vector_t word, bool *found_word)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            _check_grid(copy_grid(original), word, 0, i, j, found_word);
    }
}

int main()
{
    cin >> n >> m;
    getchar(); // Consome o '\n'

    vector_t row(m);
    matrix_t grid;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            scanf("%c", &row[j]);
        grid.push_back(row);
        
        getchar(); // Consome o '\n'
    }

    cin >> k;
    getchar(); // Consome o '\n'

    vector_t word(k);
    for (int i = 0; i < k; i++)
        scanf("%c", &word[i]);

    bool found_word = false;
    check_grid(grid, word, &found_word);

    if (found_word) printf("Yes\n");
    else printf("No\n");

    return 0;
}