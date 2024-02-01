
#include <iostream>
using namespace std;

class Point {
private:
   
public:
    int a;
};
struct Point1 {
    int r; // Компонента красного цвета
    int g; // Компонента зеленого цвета
    int b; // Компонента синего цвета
        
      void setRGB (int r1, int g1, int b1) {
           this->r = r1;
           this->g = g1;
           this->b = b1;
        }
      void printRGB() {
          cout << r << endl;
          cout << g << endl;
          cout << b << endl;
       }
    }; 

int main()
{
   
    Point1 a[4] = {};
    a[0].setRGB(2, 3, 3);
    a[0].printRGB();
    cout << a[0].b << endl;


    }