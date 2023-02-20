// Optimal page replacement


#include <bits/stdc++.h>
using namespace std;

bool search(int key, vector<int> &fr)
{
    for (int i = 0; i < fr.size(); i++)
    {
        if (fr[i] == key)
            return true;
    }

    return false;
}

int predict(int pg[], vector<int> &fr, int pn, int index)
{
    int res = -1, farthest = index;
    for (int i = 0; i < fr.size(); i++)
    {
        int j;
        for (j = index; j < pn; j++)
        {
            if (fr[i] == pg[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        // If a page is never referenced in future return it.
        if (j == pn)
            return i;
    }

    // If all of the frames were not in future,
    // return any of them, we return 0. Otherwise
    // we return res.
    return (res == -1) ? 0 : res;
}

void optimalPage(int pg[], int pn, int fn)
{
    vector<int> fr;

    int hit = 0;
    for (int i = 0; i < pn; i++)
    {

        // Page found in a frame : HIT
        if (search(pg[i], fr))
        {
            hit++;
            continue;
        }

        // If there is space available in frames.
        if (fr.size() < fn)
            fr.push_back(pg[i]);

        // Find the page to be replaced.
        else
        {
            int j = predict(pg, fr, pn, i + 1);
            fr[j] = pg[i];
        }
    }
    cout << "No. of hits = " << hit << endl;
    cout << "No. of misses = " << pn - hit << endl;
}

int main()
{
    cout << "Enter the length of refrence string : ";
    int len;
    cin >> len;

    int *string = new int[len];

    cout << "Enter the refrence string \n";
    for (int i = 0; i < len; i++)
    {
        cin >> string[i];
    }

    cout << "Enter the no of frames in the main memory: " << endl;
    int no_frames;
    cin >> no_frames;

    optimalPage(string, len, no_frames);
    return 0;
}

