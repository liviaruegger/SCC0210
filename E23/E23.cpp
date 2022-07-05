#include <iostream>
#include <vector>

using namespace std;

vector<int> found_pattern_index;

void kmp_pre_process(int *b, char *pattern, int pattern_size)
{
    int i = 0, j = -1;
    b[0] = -1;

    while (i < pattern_size)
    {
        while (j >= 0 && pattern[i] != pattern[j]) j = b[j];

        i++; j++;
        b[i] = j;
    }
}

void kmp_search(int *b, char *pattern, char *text, int pat_size, int text_size)
{
    int i = 0, j = 0;

    while (i < text_size)
    {
        while (j >= 0 && text[i] != pattern[j]) j = b[j];
        
        i++; j++;

        if (j == pat_size)
        {
            found_pattern_index.push_back(i - j + 1);
            j = b[j];
        }
    }
}

void test_case()
{
    found_pattern_index.clear();

    string text_str, pattern_str;
    cin >> text_str >> pattern_str;

    // string object to (char *)
    char *text = &text_str[0];
    char *pattern = &pattern_str[0];

    int b_size = pattern_str.size();
    int b[b_size];

    kmp_pre_process(b, pattern, pattern_str.size());
    kmp_search(b, pattern, text, pattern_str.size(), text_str.size());

    if (found_pattern_index.empty())
    {
        cout << "Not Found\n\n";
        return;
    }

    cout << found_pattern_index.size() << endl;
    for (int i : found_pattern_index)
        cout << i << " ";
    cout << "\n\n";
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) test_case();

    return 0;
}