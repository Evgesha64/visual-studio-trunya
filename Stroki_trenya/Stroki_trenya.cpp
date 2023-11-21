
#include <string>
#include <iostream>
 using namespace std;

 void strizmen(char *str) {

	 str[2] = 'f';
 }

int main()
{
	setlocale(LC_ALL, "ru");
	char simvol_arr[] = {'H','e','l','l','o','\0'};
	cout << strlen(simvol_arr) << "\n";
	cout << simvol_arr << "\n";
	int d = -33;
	string str1[5];
	str1[0] = "Привет";
	str1[1] = "b";
	str1[2] = "c";
	string str2 = "мир";
	string str3 = str1[0] + " " + str2 + str1[1]+ str1[2];
	cout << str3 << "\n";
}
/*for (int i = 0; i < 255; i++)
	{
		cout << "code = " << i << "\tchar = " << (char)i << endl;
	}
	char str0[255]{} ;
	char str1[255] = "Hello";
	char str2[255] = "Hello";
	cout << str1 << endl;
	strizmen(str1);
    cout << str1 << endl;
    strcat(str0, str1);
	strcat(str0, str2);
    cout << str0 << endl;*/