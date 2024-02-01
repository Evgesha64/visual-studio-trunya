#include <iostream>
using namespace std;
int Y = 0;
int N = 0;
void test(const int x2, const int y2) {
    int Y = 0;
    int N = 0;
    for (int x1 = 0; x1 < 9; x1++)
    {
        cout << endl;
        for (int y1 = 0; y1 < 9; y1++)
        {
            if (((x1 + 1) == x2 && (y1 + 2) == y2) || ((y1 + 1) == y2 && (x1 + 2) == x2) || ((x1 - 1) == x2 && (y1 - 2) == y2) || ((y1 - 1) == y2 && (x1 - 2) == x2) || ((x1 + 1) == x2 && (y1 - 2) == y2) || ((y1 + 1) == y2 && (x1 - 2) == x2) || ((x1 - 1) == x2 && (y1 + 2) == y2) || ((y1 - 1) == y2 && (x1 + 2) == x2))
            {
                Y++;
                cout << "\033[1;32m1 \033[0m";
            }
            else {
                N++;
                cout << "0 ";
            }
        }
    }
    cout << endl;
    cout << "YES " << Y << endl << "NO " << N << endl;
}
void test2(const int x2, const int y2) {
    int Y = 0;
    int N = 0;
    for (int x1 = 0; x1 < 9; x1++)
    {
        cout << endl;
        for (int y1 = 0; y1 < 9; y1++)
        {

            if ((x1 < x2 || x1 > x2) && y1 == y2)
            {
                Y++;
                cout << "\033[1;32m1 \033[0m";
            }
            else if ((y1 > y2 || y1 < y2) && x1 == x2)
            {
                Y++;
                cout << "\033[1;32m1 \033[0m";
            }
            else {
                int a = x2 - x1;
                int b = y2 - y1;
                if (a < 0) { a *= -1; }
                if (b < 0) { b *= -1; }
                if (a == b) {
                    cout << "\033[1;32m1 \033[0m";
                    Y++;
                }
                else {
                    N++;
                    cout << "0 ";
                }
            }
        }
    }
    cout << endl;
    cout << "YES " << Y << endl << "NO " << N << endl;
}
int main() {
    //test(1, 2, 3, 4);
    for (int i = 0; i < 9; i++)
    {
        cout << endl;
        for (int i1 = 0; i1 < 9; i1++)
        {
            cout << i  << i1 << " ";
        }
    }
    cout << endl;
   
    test(4, 4);
    test2(4, 4);
   
    
   
}