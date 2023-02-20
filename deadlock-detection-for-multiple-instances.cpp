#include <iostream>
using namespace std;
#include <vector>
int n;
int m;

void Safety(vector<vector<int>> allocation, vector<vector<int>> request, vector<int> available, vector<int> processId)
{

    int safe[n];
    int k = 0;
    int completed[n] = {0};
    int finish = 0;

    vector<int> total(m);
    int sumr = 0;
    for (int j = 0; j < m; j++) // j selects resource to do sum of its allocations
    {
        for (int i = 0; i < n; i++)
        {
            sumr += allocation[i][j];
        }
        total[j] = available[j] + sumr;
        sumr = 0;
    }
    while (finish != n)
    {
        int select = -1;
        for (int i = 0; i < n; i++)
        { // traversing the processes
            if (!completed[i])
            {
                int j = 0;
                while (j < m && request[i][j] <= available[j])
                {
                    j++;
                }
                if (j == m)
                { // request satisfied
                    safe[k++] = processId[i];
                    select = i;
                    finish++;
                    completed[i] = 1;
                    for (int j = 0; j < m; j++)
                    {
                        available[j] += allocation[i][j];
                    }
                }
            }
        }
        if (select == -1)
        {
            break;
        }
    }

    int j = 0;
    while (j < m && total[j] == available[j])
    {
        j++;
    }

    if (j == m)
    {
        cout << "The system is in safe state" << endl;
        cout << "The safe sequence is: ";
        for (int k = 0; k < n; k++)
        {
            cout << "P" << safe[k] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "The system is in Deadlock!" << endl;
        cout << "Deadlock processes are:\n";
        for (int i = 0; i < n; i++)
        {
            if (!completed[i])
            {
                cout << "P" << processId[i] << " ";
            }
        }
        cout << "\n";
    }
}

int main()
{

    cout << "Enter no. of processes:" << endl;
    cin >> n;
    cout << "Enter process Ids:" << endl;
    vector<int> processId(n);
    for (int i = 0; i < n; i++)
    {
        cin >> processId[i];
    }
    cout << "Enter no. of type of resources:" << endl;
    cin >> m;
    cout << "Enter no. of allocated resources of each type for " << n << " processes" << endl;
    vector<vector<int>> allocation(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> allocation[i][j];
        }
    }
    cout << "Enter no. of reqested resources of each type for " << n << " processes" << endl;
    vector<vector<int>> request(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> request[i][j];
        }
    }
    cout << "Enter no. of available resources of each type" << endl;
    vector<int> available(m);
    for (int j = 0; j < m; j++)
    {
        cin >> available[j];
    }

    cout << "Processes\tAllocation\tRequest" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << processId[i] << "\t\t";
        for (int j = 0; j < m; j++)
        {
            cout << allocation[i][j] << " ";
        }
        cout << "\t\t";
        for (int j = 0; j < m; j++)
        {
            cout << request[i][j] << " ";
        }

        cout << endl;
    }
    cout << "Available resources: ";
    for (int j = 0; j < m; j++)
    {
        cout << available[j] << " ";
    }
    cout << endl;

    Safety(allocation, request, available, processId);
}