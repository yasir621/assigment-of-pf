#include<iostream>
using namespace std;
void reverse(int arr[]);
int main()
{
	int ar[7];
	cout << "enter 7 numbers" << endl;
	for (int i = 0; i < 7; i++)
	{
		cin >> ar[i];
	}

	reverse(ar);
	return 0;
}
void reverse(int arr[]) {
	for (int i = 6; i < 0; i--)
	{
		cout << "reversed array is" << arr[i];
	}
}