#include <iostream>
using namespace std;
void paldrom(char[]);
int main() {
	char input[100]{};
	cout << "Enter Word :";
	cin >> input;
	paldrom(input);
	return 0;
}
void paldrom(char arr[]) {
	int length = 0;
	bool isPalendrom = true;
	while (arr[length] != '\0') {
		length++;
	}
	int a = length - 1;
	for (int i = 0; i < length/2; i++)
	{
		if (arr[i] != arr[a])
		{
			isPalendrom = false;
			break;
		}
		a--;

	}
	if (isPalendrom)
	{
		cout << "This is a Palindrom" << endl;
	}
	else
	{
		cout << "This is Not palindrom" << endl;
	}
}