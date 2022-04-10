#include <bits/stdc++.h>

using namespace std;

void new_test_case(string aux);
bool sort_by_first(const pair<int, string> &a, const pair<int, string> &b);
bool sort_by_second(const pair<int, string> &a, const pair<int, string> &b);

int main()
{
    string aux;
    getline(cin, aux);

    while (aux.compare("0") != 0)
    {
        new_test_case(aux);
        getline(cin, aux);
    }

    return 0;
}

void new_test_case(string aux)
{
    map<string, int> projects;
    map<string, string> students;
    string project;

    while (aux.compare("1") != 0)
    {
        if (isupper(aux[0])) // É nome de projeto
        {
            project = aux;
            projects[project] = 0;
        }
        else if (islower(aux[0])) // É nome de estudante
        {
            if (students.find(aux) == students.end()) // Não está no mapa
            {
                students[aux] = project;
                projects[project]++;
            }
            else if (students[aux] != "removed" && students[aux] != project)
            {
                projects[students[aux]]--;
                students[aux] = "removed";
            }
        }

        getline(cin, aux);
    }

    // Realizar contagem a partir do mapa
    int vector_size = projects.size();
    pair<int, string> counting_vector[vector_size];

    int j = 0;
    for (map<string, int>::iterator i = projects.begin(); i != projects.end(); ++i)
    {
        counting_vector[j].first = i->second;
        counting_vector[j].second = i->first;
        j++;
    }

    // Ordenar
    sort(counting_vector, counting_vector + vector_size, sort_by_second);
    stable_sort(counting_vector, counting_vector + vector_size, sort_by_first);

    // Imprimir resultados
    for (int k = 0; k < vector_size; k++)
        cout << counting_vector[k].second << " " << counting_vector[k].first << endl;
}

bool sort_by_first(const pair<int, string> &a, const pair<int, string> &b)
{
    return (a.first > b.first);
}

bool sort_by_second(const pair<int, string> &a, const pair<int, string> &b)
{
    return (a.second < b.second);
}