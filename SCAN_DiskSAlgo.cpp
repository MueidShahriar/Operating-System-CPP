#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, headnum, disk = 199;
    int request[100];
    cout << "Enter number of disk requests: ";
    cin >> n;
    cout << "Enter the disk requests:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> request[i];
    }
    cout << "Enter initial head position: ";
    cin >> headnum;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (request[j] > request[j + 1])
            {
                int temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }
    
    int totalmove = 0;
    int current = headnum;
    for (int i = 0; i < n; i++)
    {
        if (request[i] >= headnum)
        {
            totalmove += (request[i] - current);
            current = request[i];
        }
    }
    totalmove += (disk - current);
    current = disk;
    for (int i = n - 1; i >= 0; i--)
    {
        if (request[i] < headnum)
        {
            totalmove += (current - request[i]);
            current = request[i];
        }
    }
    cout << "Total Head Movement: " << totalmove << endl;
    return 0;
}