#include <iostream>
using namespace std;
int main() {
    int N = 1, S = 0, s =0;

    while (N != 0) {

        cin >> N;
        if (N < S && N > s) {
            s = N;

        }
        if (N > S) {

            S = N;
        }

    }
    cout << s;


    return 0;
}