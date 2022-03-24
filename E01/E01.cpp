/**
 * @file   E01.cpp
 * @author Ana Lívia Ruegger Saldanha (N.USP 8586691)
 * @brief  SCC0210 - Laboratório de Algoritmos Avançados I
 *         Exercício 01: Aquecendo os motores
 *         
 * @date   2022-03-22
 * 
 */

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