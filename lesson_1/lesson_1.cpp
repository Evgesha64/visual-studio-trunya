
#include <iostream>
using namespace std;

void arrGenerstor(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
	}
}

void arrPublic(int* const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int size = 10;
	int* MyArr1 = new int(size);
	int* MyArr2 = new int(size);
	arrGenerstor(MyArr1,size);
	arrPublic(MyArr1, size);

}
