#include <iostream>
using namespace std;
void printarray(int arr[], int a);
int main() {
    int arr[5];
    cout << "Enter 5 integers" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    printarray(arr, 5);
}
void printarray(int arr[], int a) {
    for (int i = 0; i < a; i++)
        cout <<"Element at postion"<<i<<"="<< arr[i] << " "<<endl;
    cout << endl;
}
