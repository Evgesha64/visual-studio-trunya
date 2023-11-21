

#include <iostream>
using namespace std;

void foo1(void *a) {

    //cout << "foo1 = "<< a << endl ;
     *a *2;
}

void foo2(void *a) {

    //cout << "foo2 = "<< a;
     *a * 2;
}



    int main()
{
        float* a;
        *a = 3.24535;
       void(*voidPointor[2])(void *a);
         voidPointor[0] = foo1;
         cout << voidPointor[0](a) << endl;
         voidPointor[1] = foo2;
         cout << voidPointor[1](a) << endl;

} 