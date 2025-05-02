#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id, at, bt, ct, wt, tat;
};

int main()
{
    int n;
    cout << "Number of processes: ";
    cin >> n;

    Process* a = new Process[n];

    for (int i = 0; i < n; i++)
        {
            a[i].id = i;
            cout << "Arrival time & Burst time for process " << i + 1 << ": ";
            cin >> a[i].at >> a[i].bt;
        }

    for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
                {
                    if (a[j].at > a[j + 1].at ||
                            (a[j].at == a[j + 1].at && a[j].id > a[j + 1].id))
                        {
                            Process temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;
                        }
                }
        }

    int currentTime = 0, totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++)
        {
            if (currentTime < a[i].at)
                currentTime = a[i].at;
            a[i].ct = currentTime + a[i].bt;
            currentTime = a[i].ct;
            a[i].tat = a[i].ct - a[i].at;
            a[i].wt = a[i].tat - a[i].bt;
            totalWT += a[i].wt;
            totalTAT += a[i].tat;
        }

    for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
                {
                    if (a[j].id > a[j + 1].id)
                        {
                            Process temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;
                        }
                }
        }

    cout << "\nP\tAT\tBT\tCT\tWT\tTAT\n";
    for (int i = 0; i < n; i++)
        {
            cout << "P" << a[i].id + 1 << "\t" << a[i].at << "\t" << a[i].bt << "\t" << a[i].ct << "\t" << a[i].wt << "\t" << a[i].tat << "\n";
        }

    cout << "\nAverage Waiting Time: " << (double)totalWT / n << "\n";
    cout << "Average Turnaround Time: " << (double)totalTAT / n << "\n";
    return 0;
}
