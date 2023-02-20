#include <bits/stdc++.h>
using namespace std;

class processes
{
public:
    int p_id;
    int priority;
    int burst;

    processes(){};
    processes(int a, int b, int c) : p_id(a), priority(b), burst(c){}; //using setters by initilaizing list
};

bool compare(processes a, processes b)
{
    if(a.priority == b.priority)
    {
        return a.burst < b.burst;
    }
    return a.priority > b.priority;
}

int main()
{
    cout << "Priority SCHEDULER \n";
    int n;
    cout << "Enter the no of processeses : " << endl;
    cin >> n;

    cout << "Enter the id of processes followed by its burst time and priority one by one \n";

    vector<processes> p;

    int j = n;
    while (j--)
    {
        processes temp;
        cin >> temp.p_id;
        cin >> temp.burst;
        cin >> temp.priority;
        p.push_back(temp);
    }

    // sorting on the basis of priority
    sort(p.begin(), p.end(), compare); //sorting the vector using the priority of the process

    int wait = 0;
    int burst = p[0].burst;

    vector<int> waiting; // creating the dynamic array of the waiting time of the processes
    waiting.push_back(0); // pushing the values of the process from the back

    for (int i = 1; i < n; i++)
    {
        int w = waiting[i - 1] + p[i - 1].burst; // calculting the waiting time of the processes untill all the process are done
        waiting.push_back(w); // pushing the value of the waiting time into the dynamic array
        wait += w;
        burst += p[i].burst;
    }

    cout<<"\np_id priority burst waiting turnaround\n";
    for (int i = 0; i < n; i++)
    {
        cout<<p[i].p_id<<"      "<<p[i].priority<<"      "<<p[i].burst<<"      "<<waiting[i]<<"      "<<(waiting[i]+p[i].burst)<<endl;
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