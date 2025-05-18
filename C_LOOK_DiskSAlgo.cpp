#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of track: "; cin>>n;

    int req[100];
    cout<<"Enter the track: ";
    for(int i=0; i<n; i++) {
        cin>>req[i];
    }
    int head;
    cout<<"Enter head position: "; cin>>head;

    int Size;
    cout<<"Enter total disk size : ";  cin>>Size;

    string dir;
    cout<<"Towards (low/high): ";
    cin>>dir;

    int low[100], high[100];
    int l= 0, r= 0;
    int seekCount= 0;
    int sequence[200], s = 0;

    for (int i=0; i<n; i++) {
        if (req[i]<head)
            low[l++] = req[i];
        else
            high[r++] = req[i];
    }

    if (dir == "low")
        low[l++] = 0;


    sort(low, low + l);
    sort(high, high + r);

    if (dir == "low") {
        for (int i = 0; i < l; i++) {
            sequence[s++] = low[i];
            seekCount += abs(head - low[i]);
            head = low[i];
        }
        for (int i = 0; i < r; i++) {
            sequence[s++] = high[i];
            seekCount += abs(head - high[i]);
            head = high[i];
        }
    } 
    else {
        for (int i = 0; i < r; i++) {
            sequence[s++] = high[i];
            seekCount += abs(head - high[i]);
            head = high[i];
        }
        for (int i = 0; i < l; i++) {
            sequence[s++] = low[i];
            seekCount += abs(head - low[i]);
            head = low[i];
        }
    }
    cout << "Head Movement Sequence: ";
    for (int i = 0; i < s; i++)
        cout << sequence[i] << " ";
    cout << "\nTotal Head Movement = " << seekCount << endl;

    return 0;
}