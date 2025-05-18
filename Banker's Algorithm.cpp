#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m = 3;
    cout << "Enter number of processes: ";
    cin >> n;

    int MaxNeed[5][3], AllocatedResources[5][3], CurrentResourceNeed[5][3];

    cout << "\nAllocation Matrix:\n";
    for(int i = 0; i < n; i++)
        {
            cout << "P" << i << ": ";
            for(int j = 0; j < m; j++)
                cin >> AllocatedResources[i][j];
        }

    cout << "\nMaximum Matrix:\n";
    for(int i = 0; i < n; i++)
        {
            cout << "P" << i << ": ";
            for(int j = 0; j < m; j++)
                cin >> MaxNeed[i][j];
        }

    int total[3] = {0, 0, 0};
    int available[3];

    for(int j = 0; j < m; j++)
        {
            int sum = 0;
            for(int i = 0; i < n; i++)
                sum += AllocatedResources[i][j];
               available[j] = total[j] - sum;
        }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            CurrentResourceNeed[i][j] = MaxNeed[i][j] - AllocatedResources[i][j];

    bool finish[10] = {false};
    int safeSequence[10];
    int work[3];

    for(int i = 0; i < m; i++)
        work[i] = available[i];

    cout << "\nAvailable Resources: ";
    for(int i = 0; i < m; i++)
        cout << available[i] << " ";
    cout << endl;

    int count = 0;
    while(count < n)
        {
            bool found = false;
            for(int p = 0; p < n; p++)
                {
                    if(!finish[p])
                        {
                            bool possible = true;
                            for(int j = 0; j < m; j++)
                                {
                                    if(CurrentResourceNeed[p][j] > work[j])
                                        {
                                            possible = false;
                                            break;
                                        }
                                }

                            if(possible)
                                {
                                    for(int j = 0; j < m; j++)
                                        work[j] += AllocatedResources[p][j];
                                    safeSequence[count] = p;
                                    finish[p] = true;
                                    count++;
                                    found = true;
                                }
                        }
                }

            if(!found)
                {
                    cout << "System is in DEADLOCK state!" << endl;
                    return 0;
                }
        }

    cout << "System is in SAFE state.\n\nSafe sequence is: ";
    for(int i = 0; i < n; i++)
    cout << "P" << safeSequence[i] << " ";
    cout << endl;
    return 0;
}
