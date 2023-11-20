
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

void arrCopi(int* arr1, int* const arr2,const int size)
{
	delete[] arr1;
	arr1 = new int[size];
	for (int i = 0; i < size; i++)
	{
		arr1[i] = arr2[i];

	}
}

int main()
{
	int size = 10;
	int* MyArr1 = new int(size);
	int* MyArr2 = new int(size);
	
	arrGenerstor(MyArr1, size);
	arrGenerstor(MyArr2, size);
	arrPublic(MyArr1, size);
	arrPublic(MyArr2, size);

	
	//arrCopi(MyArr1, MyArr2, size);

	//arrPublic(MyArr2, size);

	delete[] MyArr1;
	delete[] MyArr2;
}
