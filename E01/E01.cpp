#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    map<string,string> names;
    
    for (int i = 0; i < n; i++)
    {
        string name, ip;
        cin >> name >> ip;

        names[ip] = name;
    }
    
    for (int i = 0; i < m; i++)
    {
        string command, _ip;
        cin >> command >> _ip;

        string ip = _ip;
        ip.pop_back();

        string output = command + " " + _ip + " #" + names[ip] + "\n";
        cout << output;
    }

    return 0;
}