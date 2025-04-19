#include <iostream>
#include <fstream>
using namespace std;

void countWords(const char file[]) {
    ifstream fin("read.txt");
    string word;
    int wordCount = 0;

    if (!fin) {
        cout << "Unable to open file." << endl;
        return;
    }

    while (fin >> word) {
        wordCount++;
    }

    fin.close();
    cout << "Total words in file: " << wordCount << endl;
}

int main() {
    char fileName[100];
    cout << "Enter file name: ";
    cin >> fileName;

    countWords(fileName);

    return 0;
}
