#include <iostream>

using namespace std;

int longest_prefix_suffix(string s)
{
    int n = s.length();

    int lps[n];
    lps[0] = 0;

    int len = 0;
    int i = 1;

    while (i < n)
    {
        if (s[i] == s[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps[n - 1];
}

void test_case()
{
    string pattern;
    int n_times;

    cin >> pattern >> n_times;
    int size = pattern.size();

    int lps = longest_prefix_suffix(pattern);
    int middle = size - (2 * lps);

    cout << (n_times * middle) + ((n_times + 1) * lps) << endl;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) test_case();

    return 0;
}