#include <iostream>
#include <vector>

using namespace std;

void _subsets(vector<int>& original, vector<vector<int>>& res, vector<int>& subset, int index)
{
    res.push_back(subset);

    for (int i = index; i < (int)original.size(); i++)
    {
        subset.push_back(original[i]);
        _subsets(original, res, subset, i + 1);
        subset.pop_back();
    }
}

// Retorna um vetor com todos os subsets do array original
vector<vector<int>> subsets(vector<int>& original)
{
    vector<int> subset;
    vector<vector<int>> res;

    int index = 0;
    _subsets(original, res, subset, index);
 
    return res;
}

int main()
{
    vector<int> nums;

    int n, num;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        nums.push_back(num);
    }

    vector<vector<int>> res = subsets(nums);

    int sum = 0;

    for (int i = 0; i < (int)res.size(); i++)
    {
        int temp = 0;

        for (int j = 0; j < (int)res[i].size(); j++)
            temp = temp ^ res[i][j];

        sum += temp;
    }

    cout << sum << endl;

    return 0;
}