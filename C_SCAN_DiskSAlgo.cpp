#include <bits/stdC++.h>
using namespace std;
int main()
{
    int n, head, diskSize = 199;
    vector <int> requests;
    cout << "Enter number of disk requests: ";
    cin >> n;
    cout << "Enter the disk requests:";
    
    for (int i = 0; i < n; i++)
    {
        int req;
        cin >> req;
        requests.push_back(req);
    }
    cout << "Enter initial head position: ";
    cin >> head;
    sort(requests.begin(), requests.end());
    int totalMovement = 0;
    int current = head;
    for (int i = 0; i < n; i++)
    {
        if (requests[i] >= head)
        {
            totalMovement += (requests[i] - current);
            current = requests[i];
        }
    }

    totalMovement +=  diskSize - current;
    current = 0;
    totalMovement += diskSize;
    for (int i = 0; i < n; i++)
    {
        if (requests[i] < head)
        {
            totalMovement += (requests[i] - current);
            current = requests[i];
        }
    }
    cout << "Total Head Movement: "<<totalMovement<<endl;
        return 0;
}