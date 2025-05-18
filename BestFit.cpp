#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter number of memory blocks: ";
    cin >> m;
    int blockSize[m], originalBlockSize[m];

    cout << "Enter size of each block:\n";
    for (int i = 0; i < m; i++)
    {
        cin >> blockSize[i];
        originalBlockSize[i] = blockSize[i];
    }

    cout << "\nEnter number of processes: ";
    cin >> n;
    int processSize[n];
    cout << "Enter size of each process:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> processSize[i];
    }

    int allocation[n], internalFrag[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
        internalFrag[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            internalFrag[i] = blockSize[bestIdx] - processSize[i];
            blockSize[bestIdx] -= processSize[i];
        }
    }

    cout << "\n\tBest Fit Allocation";
    cout << "\nProcess No\tProcess Size\tBlock No\n";
    int totalInternal = 0;
    bool hasInternal = false, hasExternal = false;

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
            totalInternal += internalFrag[i];
            if (internalFrag[i] > 0)
                hasInternal = true;
        }
        else
        {
            cout << "Not Allocated";
            hasExternal = true;
        }
        cout << endl;
    }

    int totalExternal = 0;
    if (hasExternal)
    {
        for (int i = 0; i < m; i++)
        {
            totalExternal += blockSize[i];
        }
    }

    if (hasInternal)
        cout << "\nTotal Internal Fragmentation: " << totalInternal << "KB" << endl;

    if (hasExternal)
        cout << "Total External Fragmentation: " << totalExternal << "KB" << endl;
        else
        cout << "No External Fragmentation" << endl;

    return 0;
}
