#include <bits/stdc++.h>
using namespace std;

class process
{
public:
    int p_id;
    int arrival;
    int burst;
    int b_store;
    int a_store;
    int comp;
    int wait;
    int turn;

    process(){};
    process(int a, int b, int c) : p_id(a), arrival(b), burst(c), b_store(c){};

    void getData()
    {
        turn = comp - a_store;
        wait = turn - b_store;
    }
};

class compare
{
public:
    bool operator()(process a, process b)
    {
        if (a.arrival == b.arrival)
        {
            return a.burst > b.burst;
        }
        return a.arrival > b.arrival;
    }
};

void print(process a)
{
    cout << "Pid " << a.p_id << endl;
    cout << "burst " << a.burst << endl;
    cout << "arr " << a.arrival << endl;
}

int main()
{
    // disable default
    ios_base::sync_with_stdio(false); // toggles on or off the synchronization of all C++ standard streams with their corresponding standard C streams,
    cin.tie(NULL);                    // if it is called before the program performs its first input or output operation.

// set our properties
#ifndef IO_FROM_FILE // checks if the same thing is declared before somewhere even in the librarires that are included.
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    // start of program
    cout << "Round robin SCHEDULER \n";
    int n, t;

    cout << "Enter the no of processes : " << endl;
    cin >> n;
    cout << "Enter the time quantum of the CPU : " << endl;
    cin >> t;

    cout << "Enter the id of process followed by its burst time and arrival time one by one \n";

    vector<process> p;

    int j = n;
    while (j--)
    {
        process temp;
        cin >> temp.p_id;
        cin >> temp.burst;
        cin >> temp.arrival;
        temp.b_store = temp.burst;
        temp.a_store = temp.arrival;
        p.push_back(temp);

        // print(temp);
    }

    // init minHeap(descending-order sorting) so that processes are sorted on the basis of their arrival time
    priority_queue<process, vector<process>, compare> qt; 

    // push all the elements into minHeap
    for (int i = 0; i < p.size(); i++)
    {
        qt.push(p[i]);
    }

    long long int time = qt.top().arrival;

    p.clear();

    while (!qt.empty())
    {
        process f = qt.top();
        qt.pop();

        if (f.burst <= t)
        {
            time += f.burst;
            f.burst = 0;

            // setting its completion time
            f.comp = time;

            // generating reqired data
            f.getData();

            // push f into a array to store the data
            p.push_back(f);
        }
        else
        {
            time += t;
            f.burst -= t;
            f.arrival = time;
            qt.push(f);
        }
    }

    // now vector p have proccesses in order of their completion
    long long int waiting = 0;
    long long int turnaround = 0;

    for (int i = 0; i < p.size(); i++)
    {
        turnaround += p[i].turn;
        waiting += p[i].wait;
    }

    cout << "\np_id arrival burst waiting turn comp\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].p_id << "      " << p[i].a_store << "      " << p[i].b_store << "      " << p[i].wait << "      " << p[i].turn << "      " << p[i].comp << endl;
    }

    cout << "\nTotal waiting time : " << waiting << endl;
    cout << "Total tunaround time : " << turnaround << endl;
    cout << "Average waiting time : " << (double)waiting / n << endl;
    cout << "Average tunaround time : " << ((double)turnaround) / n << endl;

    return 0;
}

/*
1 5 1
2 10 5
3 2 1
4 9 3
5 2 4
*/

/*
1 5 0
2 1 1
3 2 1
4 10 5
5 1 9

*/