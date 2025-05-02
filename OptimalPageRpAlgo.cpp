#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, frames;

    cout << "Enter length of reference string: ";
    cin >> n;
    int ref[n];
    cout << "Enter reference string: ";
    for(int i = 0; i < n; i++) cin >> ref[i];

    cout << "Enter number of frames: ";
    cin >> frames;

    int mem[frames];
    int hits = 0, misses = 0;

    for(int i = 0; i < frames; i++) {
        mem[i] = -1;
    }

    cout << "\nPage Replacement Process:\n";
    cout << "Reference\tMemory State\t\tResult\n";
    cout << "--------\t" << string(frames*7-1, '-') << "\t\t------\n";

    for(int i = 0; i < n; i++) {
        bool found = false;

        for(int j = 0; j < frames; j++) {
            if(mem[j] == ref[i]) {
                hits++;
                found = true;
                break;
            }
        }

        if(!found) {
            misses++;
            int replace_pos = -1;
            bool has_empty_slot = false;

            for(int j = 0; j < frames; j++) {
                if(mem[j] == -1) {
                    replace_pos = j;
                    has_empty_slot = true;
                    break;
                }
            }

            if(!has_empty_slot) {
                int farthest = -1, farthest_pos = -1;
                for(int j = 0; j < frames; j++) {
                    int next_use = -1;
                    for(int k = i + 1; k < n; k++) {
                        if(ref[k] == mem[j]) {
                            next_use = k;
                            break;
                        }
                    }
                    if(next_use == -1) {
                        farthest_pos = j;
                        break;
                    }
    
                    if(next_use > farthest) {
                        farthest = next_use;
                        farthest_pos = j;
                    }
                }
                replace_pos = farthest_pos;
            }

            mem[replace_pos] = ref[i];
        }

        cout << setw(5) << ref[i] << "\t\t";
        for(int j = 0; j < frames; j++) {
            if(mem[j] == -1) cout << "[N] ";
            else cout << "[" << mem[j] << "] ";
        }
        cout << "\t\t" << (found ? "HIT" : "MISS") << endl;
    }

    float hit_rate = (float)hits/n * 100;
    float miss_rate = (float)misses/n * 100;

    cout << "\nFinal Results:\n";
    cout << "Total Hits: " << hits << endl;
    cout << "Total Misses: " << misses << endl;
    cout << fixed << setprecision(2);
    cout << "Hit Rate: " << hit_rate << "%" << endl;
    cout << "Miss Rate: " << miss_rate << "%" << endl;

    return 0;
}