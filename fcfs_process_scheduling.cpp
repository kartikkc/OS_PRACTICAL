#include <bits/stdc++.h>
using namespace std;

class processes
{
public:
    int p_id;
    int arrival;
    int burst;

    processes(){}; //constructor initialisation
    processes(int a, int b, int c) : p_id(a), arrival(b), burst(c){}; //initialization list is used to make it look cool and shorten the code
};

bool test(processes a, processes b) //testing the arrival time of the processes and then comparing their burst times to schedule accordingly
{
    if (a.arrival == b.arrival)
    {
        return a.burst < b.burst;
    }
    return a.arrival < b.arrival;
}

int main()
{
    cout << "FCFS SCHEDULER \n";
    int n;
    cout << "Enter the no of processes : " << endl;
    cin >> n;

    cout << "Enter the id of processes followed by its burst time and arrival one by one \n";

    vector<processes> p; // creating an dynamic array of the processes arrived

    int j = n;
    while (j--) // creating a loop for scheduling all the process in the vector
    {
        processes temp;  // creating a class of every process to get the details necessary to schedule process
        cin >> temp.p_id;
        cin >> temp.burst;
        cin >> temp.arrival;
        p.push_back(temp);
    }

    // sorting on the basis of arrival
    sort(p.begin(), p.end(), test); //sorting the vector

    int wait = 0; 
    int burst = p[0].burst;

    vector<int> waiting;
    waiting.push_back(0); // pushes back the into the vector from the back or -1 index.

    for (int i = 1; i < n; i++)
    {
        int w = waiting[i - 1] + p[i - 1].burst;
        waiting.push_back(w);
        wait += w;
        burst += p[i].burst;
    }

    cout << "\np_id arrival burst waiting turnaround\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].p_id << "      " << p[i].arrival << "      " << p[i].burst << "      " << waiting[i] << "      " << (waiting[i] + p[i].burst) << endl;
    }

    cout << "\nTotal waiting time : " << wait << endl;
    cout << "Total tunaround time : " << burst + wait << endl;
    cout << "Average waiting time : " << (double)wait / n << endl;
    cout << "Average tunaround time : " << ((double)burst + (double)wait) / n << endl;

    return 0;
}
// processes == process
// test == compare
/*
1 5 1
2 10 5
3 2 1
4 9 3
5 2 4
*/