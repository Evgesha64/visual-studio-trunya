#include <iostream>
using namespace std;
int main() {
    int arr[3]{};

    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    for (int i1 = 0; i1 < 3; i1++) {
        for (int i = 0; i < 2; i++) {
            if (arr[i] <= arr[i + 1]) {
                int b = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = b;

            }
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";

    }

    return 0;
}