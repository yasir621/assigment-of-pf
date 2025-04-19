#include <iostream>
#include <fstream>
#include<string>
using namespace std;
void save(string s);
int main() {
    string s;
    cout << "Enter text to save: ";
    getline(cin, s);
    save(s);
    return 0;
}
void save(string s) {
    ofstream fout("output.txt");
    if (fout.is_open()) {
        fout << s;
        fout.close();
        cout << "Text saved to output.txt" << endl;
    }
    else {
        cout << "Error opening file." << endl;
    }
}
 