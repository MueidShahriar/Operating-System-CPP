#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter number of memory blocks: ";
    cin >> m;
    int blockSize[m];
    bool blockUsed[m] = {false};
    cout << "Enter size of each block:\n";
    for (int i = 0; i < m; i++)
    {
        cout << "Block " << i + 1 << ": ";
        cin >> blockSize[i];
    }

    cout << "\nEnter number of processes: ";
    cin >> n;
    int processSize[n];
    cout << "Enter size of each process:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process " << i + 1 << ": ";
        cin >> processSize[i];
    }

    int allocation[n];
    int internalFrag[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
        internalFrag[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!blockUsed[j] && blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                internalFrag[i] = blockSize[j] - processSize[i];
                blockSize[j] -= processSize[i];
                blockUsed[j] = true;
                break;
            }
        }
    }

    cout << "\nProcess No\tProcess Size\tBlock No\n";
    int totalInternal = 0;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
            totalInternal += internalFrag[i];
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }

    int totalExternal = 0;
    for (int i = 0; i < m; i++)
    {
        if (!blockUsed[i])
        {
            totalExternal += blockSize[i];
        }
    }

    cout << "\nTotal Internal Fragmentation: " << totalInternal << "KB" << endl;
    cout << "Total External Fragmentation: " << totalExternal << "KB" << endl;

    return 0;
}