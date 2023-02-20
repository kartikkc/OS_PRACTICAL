#include <bits/stdc++.h>
using namespace std;

class processes
{
public:
    int p_id;
    int burst;

    processes(){};
    processes(int a, int b) : p_id(a), burst(b){};
};

bool compare(processes a, processes b) // comparison based on the basis of burst time so no need of 'if' condition to check if two process have same values
{
    return a.burst < b.burst;
}

int main()
{
    cout << "SJF SCHEDULER \n";
    int n;
    cout << "Enter the no of processeses : " << endl;
    cin >> n;

    cout << "Enter the id of processes followed by its burst time one by one \n";

    vector<processes> p;

    int j = n; // total number of process = j;
    while (j--)
    {
        processes temp;
        cin >> temp.p_id;
        cin >> temp.burst;
        p.push_back(temp);
    }

    // sorting on the basis of arrival
    sort(p.begin(), p.end(), compare);

    int wait = 0;
    int burst = p[0].burst;

    vector<int> waiting;
    waiting.push_back(0);

    for (int i = 1; i < n; i++)
    {
        int w = waiting[i - 1] + p[i - 1].burst;
        waiting.push_back(w);
        wait += w;
        burst += p[i].burst;
    }

    cout << "\np_id burst waiting turnaround\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].p_id << "      " << p[i].burst << "      " << waiting[i] << "      " << (waiting[i] + p[i].burst) << endl;
    }

    cout << "\nTotal waiting time : " << wait << endl;
    cout << "Total tunaround time : " << burst + wait << endl;
    cout << "Average waiting time : " << (double)wait / n << endl;
    cout << "Average tunaround time : " << ((double)burst + (double)wait) / n << endl;

    return 0;
}

/*
1 5 1
2 10 5
3 2 1
4 9 3
5 2 4
*/