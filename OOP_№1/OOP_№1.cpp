// OOP_№1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class MyClass
{
public:
	
	int GetX() {
		return x;
	}
	void SetX(int x1) {
		x = x1;
	}
	void SetY(int x1) {
		y = x1;
	}
	void SetZ(int x1) {
		z = x1;
	}
	void sum(){
		cout << x+y+z;
	}
   
private:
 int x,y,z;
};
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
        cout << "Конструктор Point x = " << x << " " << "y = " << y << " " << this << endl;
    }
    void Set(int sx, int sy){
        x = sx;
        y = sy;
    }
    void Print() {
        cout << x << " " << y << endl;
    }
    bool operator == (Point & obekt ) {
        
        return this->x == obekt.x && this->y == obekt.y;

    }
    bool operator != (Point & obekt) {
        return !(this->x == obekt.x && this->y == obekt.y);

        }
    Point& operator ++(int vale) {
        this->x++;
        this->y++;
        return *this;
    }
    Point& operator ++() {
        Point temp(*this);
        this->x++;
        this->y++;
        return temp;
    }
    Point operator +(const Point & obekt) {
        Point temp;
        temp.x = this->x + obekt.x;
        temp.y = this->y + obekt.y;
        return temp;
    }
    ~Point() {
        x = 0;
        y = 0;
        //cout << x << endl << y << endl;
        cout << "Диструктор для Point " << this << endl;
    }
};
class MyClass2 {
private:
    int* data;
    int size;
public:
    MyClass2() { //Конструктор по умолчанию.
        cout << "Конструктор по умолчанию " << this << endl;
    }
    MyClass2(int size) { //Конструктор для создания одномерного динамического массива и его заполнения(только для примера).
        cout << "Конструктор одномерного динамического массива " << this << endl;
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
    MyClass2(const MyClass2 &obekt) { //Конструктора копирования.
        this->size = obekt.size; //Присвоение  значения глобальному size для нового обекта b из обекта a по ссылки obekt.
        this->data = new int[obekt.size];//Зоздание нового одномерного динамического массива для обекта b и заполнение его данными из обекта a.
        for (int i = 0; i < obekt.size; i++)
        {
            this->data[i] = obekt.data[i];
        }
        cout << "Конструктор копирования data " << this << endl;
    }

    MyClass2&  operator = (const MyClass2 &obekt) { //  Конструктор оператора присвоить.
        
        this->size = obekt.size;
        if (this->data!=nullptr)
        {
            delete[] this->data;
        }
        this->data = new int[obekt.size];
        for (int i = 0; i < obekt.size; i++)
        {
            this->data[i] = obekt.data[i];
        }
        cout << "Конструктор оператора = " << this << endl;

       
       return *this;
    }
   
    ~MyClass2() {//Диструктор чтоб всё почистить. 

        delete[] data;
        cout << "Диструктор для data " << this << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
	//MyClass kord;
	//kord.SetX(2);
	//kord.SetY(4);
	//kord.SetZ(8);
	//kord.sum();
    //MyClass2 a(8);
    // MyClass2 b(1);
    // MyClass2 с(2);
    // с = b = a;
    Point a, b, c;
    b.Set(5, 4);
    a.Set(5, 4);
    c.Set(5, 4);

    c = a + b;
    ++c;
     bool rezult =  a == b;
    cout << rezult << endl;
     c.Print();
} 