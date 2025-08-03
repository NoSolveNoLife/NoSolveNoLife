#include <iostream>
#include <cmath>

using namespace std;

int t;

int main() {
    cin >> t;

    while(t--){
        int start, end;
        cin >> start >> end;

        int dist = end - start;  
        int max_ = (int)sqrt(dist);  

        if (max_ == sqrt(dist)) {
            cout << max_ * 2 - 1 << "\n";
        }
        else if (dist <= max_ * max_ + max_) {
            cout << max_ * 2 << "\n";
        }
        else {
            cout << max_ * 2 + 1 << "\n";
        }
    }
}