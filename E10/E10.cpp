#include <iostream>

using namespace std;

void check_grid(char **original, char **copy, char *word, int index, int i, int j, bool *found_word);
char **copy_grid(char **original_grid);

int n, m;
int k;

int main()
{
    cin >> n >> m;
    getchar(); // Consome o '\n'

    char **grid = (char **) malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        grid[i] = (char *) malloc(m * sizeof(char));
        
        for (int j = 0; j < m; j++)
            scanf("%c", &grid[i][j]);
        
        getchar(); // Consome o '\n'
    }

    cin >> k;
    getchar(); // Consome o '\n'

    char *word = (char *) malloc(k * sizeof(char));
    for (int i = 0; i < k; i++)
        scanf("%c", &word[i]);
    
    bool found_word = false;
    char **copy = NULL;
    check_grid(grid, copy, word, 0, 0, 0, &found_word);

    if (found_word) printf("Yes\n");
    else printf("No\n");

    return 0;
}

void check_grid(char **original, char **copy, char *word, int index, int i, int j, bool *found_word)
{
    if (!copy) // É a primeira chamada
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                copy = copy_grid(original);
                check_grid(original, copy, word, index + 1, i, j, found_word);
            }
        }
    }

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
        
        char **new_copy = copy_grid(copy);
        check_grid(original, new_copy, word, index + 1, i - 1, j, found_word); // Cima (i - 1, j)
        
        new_copy = copy_grid(copy);
        check_grid(original, new_copy, word, index + 1, i + 1, j, found_word); // Baixo (i + 1, j)
        
        new_copy = copy_grid(copy);
        check_grid(original, new_copy, word, index + 1, i, j - 1, found_word); // Esquerda (i, j - 1)
        
        new_copy = copy_grid(copy);
        check_grid(original, new_copy, word, index + 1, i, j + 1, found_word); // Direita (i, j + 1)
    }
}

char **copy_grid(char **original_grid)
{
    char **copy = (char **) malloc(n * sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        copy[i] = (char *) malloc(m * sizeof(char));

        for (int j = 0; j < m; j++)
            copy[i][j] = original_grid[i][j];
    }

    return copy;
}