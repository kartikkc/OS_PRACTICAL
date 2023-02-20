// LRU = least recently used

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the length of refrence string : ";
    int len;
    cin >> len;

    int string[len];

    cout << "Enter the refrence string \n";
    for (int i = 0; i < len; i++)
    {
        cin >> string[i];
    }

    cout << "Enter the no of frames in the main memory: " << endl;
    int no_frames;
    cin >> no_frames;

    deque<int> q(no_frames);
    int count = 0;
    int page_faults = 0;
    deque<int>::iterator itr;
    q.clear();

    for (int i : string)
    {
        itr = find(q.begin(), q.end(), i);
        if (!(itr != q.end()))
        {
            ++page_faults;

            // Check if the set can hold equal pages
            if (q.size() == no_frames)
            {
                q.erase(q.begin());
                q.push_back(i);
            }
            else
            {
                q.push_back(i);
            }
        }
        else
        {
            q.erase(itr);
            q.push_back(i);
        }
    }

    cout << "No. of hits = " << len - page_faults << endl;
    cout << "No. of misses = " << page_faults << endl;
}
