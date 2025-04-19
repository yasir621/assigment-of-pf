#include <iostream>
using namespace std;
void printch(char str[]);
int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);
    printch(str);
    return 0;
}
void printch(char str[]) {
    for (int i = 0; str[i] != '\0'; i++)
        cout <<"Character on line"<<i<<"="<< str[i] << endl;
}

