#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Number of processes: "; cin >> n;

    int id[n], at[n], bt[n], ct[n], wt[n], tat[n], order[n], a[n] = {0};

    for (int i = 0; i < n; i++)
    {
        id[i] = i + 1;
        cin >> at[i] >> bt[i];
        order[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (at[order[i]] > at[order[j]] || (at[order[i]] == at[order[j]] && id[order[i]] > id[order[j]]))
            {
                swap(order[i], order[j]);
            }
        }
    }

    int currentTime = 0, totalWT = 0, totalTAT = 0, totalCT = 0;
    int completed = 0;

    while (completed < n)
    {
        int index = -1, minbt = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (!a[order[i]] && at[order[i]] <= currentTime)
            {
                if (bt[order[i]] < minbt)
                {
                    minbt = bt[order[i]];
                    index = order[i];
                }
            }
        }

        if (index == -1)
        {
            currentTime++;
            continue;
        }

        ct[index] = currentTime + bt[index];
        tat[index] = ct[index] - at[index];
        wt[index] = tat[index] - bt[index];

        totalCT += ct[index];
        totalWT += wt[index];
        totalTAT += tat[index];

        currentTime = ct[index];
        a[index] = 1;
        completed++;
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << id[i] << "\t" << at[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << endl;
    }

    cout << "Average Turnaround Time: " << (double)totalTAT / n << endl;
    cout << "Average Waiting Time: " << (double)totalWT / n << endl;

    return 0;
}
