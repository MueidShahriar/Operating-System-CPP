#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id, arrival, burst, remaining, completion, turnaround, waiting, response = -1;
};

int main()
{
    int n, quantum;
    cout << "Number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> quantum;

    vector<Process> p(n);
    for (int i = 0; i < n; i++)
    {
        p[i].id = i + 1;
        cout << "Enter Arrival time & Burst time for P" << i + 1 << ": ";
        cin >> p[i].arrival >> p[i].burst;
        p[i].remaining = p[i].burst;
    }

    sort(p.begin(), p.end(), [](Process a, Process b)
         { return a.arrival < b.arrival || (a.arrival == b.arrival && a.id < b.id); });

    queue<int> q;
    int currentTime = 0, totalWT = 0, totalTAT = 0, completed = 0, i = 0;

    while (completed < n)
    {
        while (i < n && p[i].arrival <= currentTime)
            q.push(i++);
        if (q.empty())
        {
            currentTime = p[i].arrival;
            continue;
        }

        int index = q.front();
        q.pop();
        if (p[index].response == -1)
            p[index].response = currentTime - p[index].arrival;

        currentTime += min(quantum, p[index].remaining);
        p[index].remaining -= min(quantum, p[index].remaining);

        while (i < n && p[i].arrival <= currentTime)
            q.push(i++);
        if (p[index].remaining > 0)
            q.push(index);
        else
        {
            p[index].completion = currentTime;
            p[index].turnaround = p[index].completion - p[index].arrival;
            p[index].waiting = p[index].turnaround - p[index].burst;
            totalTAT += p[index].turnaround;
            totalWT += p[index].waiting;
            completed++;
        }
    }

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (auto &pr : p)
        cout << "P" << pr.id << "\t" << pr.arrival << "\t" << pr.burst << "\t"
             << pr.completion << "\t" << pr.turnaround << "\t" << pr.waiting << "\t" << pr.response << endl;

    cout << "\nAverage Turnaround Time: " << (double)totalTAT / n << endl;
    cout << "Average Waiting Time: " << (double)totalWT / n << endl;

    return 0;
}