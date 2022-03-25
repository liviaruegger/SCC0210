#include <iostream>
#include <queue>

using namespace std;

void test(int n_jobs, int my_job);

int main()
{
    int n_tests;
    cin >> n_tests;
    
    for (int i = 0; i < n_tests; i++)
    {
        int n_jobs, my_job;
        cin >> n_jobs >> my_job;
        test(n_jobs, my_job);
    }

    return 0;
}

void test(int n_jobs, int my_job)
{
    int total_time = 0;
    
    queue<int> q;
    priority_queue<int> p;
        
    for (int j = 0; j < n_jobs; j++)
    {
        int priority;
        cin >> priority;
        
        q.push(priority);
        p.push(priority);
    }
        
    bool printed_my_job = false;
    while (!printed_my_job)
    {
        if (q.front() == p.top())
        {
            if (my_job == 0) printed_my_job = true;
            
            q.pop();
            p.pop();
            total_time++;
        }
        else
        {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        
        if (my_job == 0) my_job = q.size() - 1;
        else my_job--;
    }
    
    cout << total_time << endl;
}