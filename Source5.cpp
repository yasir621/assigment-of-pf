#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main() {
    int arr[5];
    cout << "Enter 5 integers" << endl;
    for (int i = 0; i < 5; i++)
            {
                cin >> arr[i];
            }
    int s=findMax(arr, 5);
     cout << "Maximum element: " <<s << endl;
    return 0;
}
