#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Psize, Fsize;
    cout << "Size of page: ";
    cin >> Psize;

    int page[Psize];
    cout << "Enter page: ";
    for (int i = 0; i < Psize; i++)
    {
        cin >> page[i];
    }

    cout << "Number of frames: ";
    cin >> Fsize;

    int frames[Fsize], queue[Fsize], front = 0, rear = 0, m = 0, h = 0;

    for (int i = 0; i < Fsize; i++)
    {
        frames[i] = -1;
    }

    cout << "\nProcess Table:\n";
    cout << "Page\t";
    for (int i = 0; i < Fsize; i++)
        cout << "Frame" << i + 1 << "\t";
    cout << "Hit/Miss\n";
    cout << "------------------------------------------\n";

    for (int i = 0; i < Psize; i++)
    {
        int cpage = page[i];
        bool hit = false;

        for (int j = 0; j < Fsize; j++)
        {
            if (frames[j] == cpage)
            {
                hit = true;
                h++;
                break;
            }
        }

        if (hit)
        {
            cout << cpage << "\t";
            for (int j = 0; j < Fsize; j++)
                if (frames[j] != -1)
                    cout << frames[j] << "\t";
                else
                    cout << "-\t";
            cout << "Hit\n";
            continue;
        }

        m++;

        bool inserted = false;
        for (int j = 0; j < Fsize; j++)
        {
            if (frames[j] == -1)
            {
                frames[j] = cpage;
                queue[rear] = j;
                rear = (rear + 1) % Fsize;
                inserted = true;
                break;
            }
        }

        if (!inserted)
        {
            int replace_index = queue[front];
            frames[replace_index] = cpage;
            queue[rear] = replace_index;
            rear = (rear + 1) % Fsize;
            front = (front + 1) % Fsize;
        }

        cout << cpage << "\t";
        for (int j = 0; j < Fsize; j++)
            if (frames[j] != -1)
                cout << frames[j] << "\t";
            else
                cout << "-\t";
        cout << "Miss\n";
    }

    float hit_percent = (float)h / Psize * 100;
    float miss_percent = (float)m / Psize * 100;

    cout << "\nResults:\n";
    cout << "Total Page Hits: " << h << endl;
    cout << "Total Page Faults: " << m << endl;
    cout << "Hit Percentage: " << hit_percent << "%" << endl;
    cout << "Miss Percentage: " << miss_percent << "%" << endl;
    return 0;
}
