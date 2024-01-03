#include <iostream>
#include <stdio.h> 
#include <time.h> 
using namespace std;

class Point {
private:
    int x;
    int y; 
public:
    Point() {
        x = 0;
        y = 0;
        cout << "Конструктор Point x = 0 y = 0 " << this << endl;
    } 
    Point(int valueX, int valueY) {
        x = valueX;
        y = valueY;
        cout << "Конструктор Point x = "  << x << " " << "y = "<< y << " " << this << endl;
    }
    void Print (){
        cout << x << endl << y << endl;
    }
    ~Point() {
         x = 0;
        y = 0;
        //cout << x << endl << y << endl;
        cout << "Диструктор для Point " << this << endl;
    }
};

class MyClass {
    private:
        int* data;
        int size;
    public:
        MyClass(int size) { //Конструктор для создания одномерного динамического массива и его заполнения(только для примера).
            cout << "Конструктор "<< this << endl;
            this->size = size;
            data = new int[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = i;
            }
        }
        void print() {//Метод print.
            for (int i = 0; i < size; i++)
            {
                cout << data[i] << endl;
            }
        }
        MyClass(const MyClass& obekt) { //Конструктора копирования.
            this->size = obekt.size; //Присвоение  значения глобальному size для нового обекта b из обекта a по ссылки obekt.
            this->data = new int[obekt.size];//Зоздание новогоодномерного динамического массива для обекта b и заполнение его данными из обекта a.
            for (int i = 0; i < obekt.size; i++)
            {
                this->data[i] = obekt.data[i];
            }
            cout << "Конструктор копирования data " << this << endl;
        }
        ~MyClass() {//Диструктор чтоб всё почистить. 

            delete[] data;
            cout << "Диструктор для data " << this << endl;
        }
};
void Foo(Point value) {
    cout << "Функция Foo " << endl;

}
Point Foo2() {
    
        cout << "Функция Foo2 " << endl;
        Point tt(2,3);
        return tt;
}
int main()
{    
    setlocale(LC_ALL, "ru");
   //Point a(3,4);
   //a.Print();
   //Point b(a);
  // MyClass a(5); //Создание обекта  
   
   //MyClass b(a);//Копирование обекта с использованием конструктора копирования.
   // b.print();
   //Foo2();
 
}