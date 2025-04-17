#include <iostream>
using namespace std;
int sumarray(int arr[], int a);
int main() {
    int arr[5];
    cout << "Enter 5 integers" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    int s=sumarray(arr, 5);
    cout << "Sum of this is :" << s << endl;
}
int sumarray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum;
}

