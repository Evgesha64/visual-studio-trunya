#include <iostream>
using namespace std;
void kvadrat(int* arr, int x);




int main()
{
 setlocale(LC_ALL, "ru");
     
 const int x1 = 10;
  
   int arr[x1]{};

    int s;

    cin >> s;
     kvadrat(arr, s);
      for (int i = 0; i < 10; i++)
{
    cout << arr[i] << endl;
}
        
     return 0;

/*


 for (size_t i1 = 0; i1 < x; i1++)
    {
        cout << endl;
        for (size_t i2 = 0; i2 < y; i2++)
        {
            cout << endl;
            for (size_t i3 = 0; i3 < z; i3++)
            {
                cout << p[1];
            }
        }
      

    }
*/
}
void kvadrat(int* arr, int x = 10) {
    for (int i = 0; i < x; i++)
    {  
        arr[i] = 5;
    }
}
