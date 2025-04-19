#include <iostream>
using namespace std;
void copyarray(int spoint[], int dpoint[] , int);
int main() {
	const int size = 9;
	int arr1[size] = { 1,2,3,4,5,6,7,8,9, };
	int arr2[size] = { 0 };
	copyarray(arr1, arr2, size);
	cout << "Arr2 :";
	for (int i = 0; i < size; i++)
	{
		cout << arr2[i] << " ";
	}

	return 0;
}
void copyarray(int spoint[], int dpoint[] , int size) {   
	for (int i = 0; i < size; i++)
	{
		dpoint[i] = spoint[i];
	}
}