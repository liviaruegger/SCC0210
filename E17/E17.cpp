#include <iostream>
#include <algorithm>

using namespace std;

int price[26];

int lcs_value(int i, string str1, string str2, int n, int m)
{
    string lcs;

    int j = 0;
    int checkpoint;
    for (; i < n; i++)
    {
        while (j < m)
        {
            if (str1[i] == str2[j])
            {
                lcs.push_back(str1[i]);
                checkpoint = j;
                i++;
            }

            j++;
        }        

        j = checkpoint;
    }
    
    int value = 0;
    for (char& c : lcs)
        value += price[c - 97];

    return value;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < 26; i++)
        cin >> price[i];

    string str1, str2;
    cin >> str1 >> str2;

    int max_value1[n];
    for (int i = 0; i < n; i++)
        max_value1[i] = lcs_value(i, str1, str2, n, m);

    // int max_value2[m];
    // for (int i = 0; i < m; i++)
    //     max_value1[i] = lcs_value(i, str2, str1, m, n);

    cout << *max_element(max_value1, max_value1 + n);

    return 0;
}