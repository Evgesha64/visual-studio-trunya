
#include <mainLib.h>

using namespace std;

int main()
{
	
	MyClass a;
	string input1;

	cout << "Введите любое слово:" << endl;
    cin >> input1;

	a.setMain(input1);
	cout << "Вы ввели слово ";
	a.getMain();
	cin >> input1;
	return 0;
}


