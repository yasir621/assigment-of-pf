#include <iostream>
using namespace std;
int countVovals(const char* str);
int main() {
    char str[50];
    cout << "Enter the character" << endl;
    cin.getline(str, 50);
    int e = countVovals(str);
    cout << "Total voval is:" << e << endl;
}
int countVovals(const char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'|| ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            count++;
    }
    return count;
}


