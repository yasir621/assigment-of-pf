#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void addPlayer();
void viewAllPlayers();
void searchPlayer();
void updateStats();
void deletePlayer();

int main() {
    int c;
    do {
        cout << "------- PSL MANAGEMENT SYSTEM -----" << endl;
        cout << "1. Add Player Record" << endl;
        cout << "2. View All Player Records" << endl;
        cout << "3. Search Player by Name" << endl;
        cout << "4. Update Player Stats" << endl;
        cout << "5. Delete Player Record" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> c;

        if (c == 1) addPlayer();
        if (c == 2) viewAllPlayers();
        if (c == 3) searchPlayer();
        if (c == 4) updateStats();
        if (c == 5) deletePlayer();
        else if (c != 6) cout << "Invalid optionn"<<endl;
    } while (c != 6);

    return 0;
}

void addPlayer() {
    string name, team, role;
    int runs, wickets;

    cout << "Enter Player Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Team Name: ";
    getline(cin, team);
    cout << "Enter Role (Batsman/Bowler/All-rounder): ";
    getline(cin, role);
    cout << "Enter Total Runs: ";
    cin >> runs;
    cout << "Enter Total Wickets: ";
    cin >> wickets;

    ofstream fout("players.txt", ios::app);
    fout << name << "," << team << "," << role << "," << runs << "," << wickets << endl;
    fout.close();
}

void viewAllPlayers() {
    ifstream file("players.txt");
    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    string line;
    cout << "Name\t\tTeam\t\tRole\t\tRuns\tWickets" << endl;
    cout << "------------------------------------------------------------------" << endl;
    while (getline(file, line)) {
        size_t pos = 0;
        string data[5];
        int i = 0;
        while ((pos = line.find(",")) != string::npos && i < 5) {
            data[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        if (i < 5)
            data[i] = line;

        cout << data[0] << "\t\t" << data[1] << "\t\t" << data[2] << "\t" << data[3] << "\t" << data[4] << endl;
    }
    file.close();
}

void searchPlayer() {
    string name;
    cout << "Enter Player Name you want to search: ";
    cin.ignore();
    getline(cin, name);
    ifstream fin("players.txt");
    string line;
    bool found = false;

    while (getline(fin, line)) {
        int pos = 0;
        string data[5];
        int i = 0;
        while ((pos = line.find(",")) != string::npos && i < 5) {
            data[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        if (i < 5)
            data[i] = line;

        if (name == data[0]) {
            cout << "Player found!" << endl;
            cout << "Name: " << data[0] << endl;
            cout << "Team: " << data[1] << endl;
            cout << "Role: " << data[2] << endl;
            cout << "Runs: " << data[3] << endl;
            cout << "Wickets: " << data[4] << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Player not found.....!" << endl;
    }
    fin.close();
}

void updateStats() {
    string name;
    cout << "Enter Player Name: ";
    cin.ignore();
    getline(cin, name);

    ifstream fin("players.txt");
    ofstream fout("temp.txt");
    if (!fin) {
        cout << "Error in opening file" << endl;
        return;
    }

    string line;
    bool updated = false;

    while (getline(fin, line)) {
        int pos = 0;
        string data[5];
        int i = 0;
        while ((pos = line.find(",")) != string::npos && i < 5) {
            data[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        if (i < 5)
            data[i] = line;

        if (data[0] == name) {
            cout << "Update Total Runs: ";
            cin >> data[3];
            cout << "Update Total Wickets: ";
            cin >> data[4];
            updated = true;
        }

        fout << data[0] << "," << data[1] << "," << data[2] << "," << data[3] << "," << data[4] << endl;
    }

    fin.close();
    fout.close();

    if (updated) {
        remove("players.txt");
        rename("temp.txt", "players.txt");
        cout << "Record updated successfully........!" << endl;
    }
    else {
        remove("temp.txt");
        cout << "Player not found........!" << endl;
    }
}

void deletePlayer() {
    string name;
    cout << "Enter the Player Name: ";
    cin.ignore();
    getline(cin, name);

    ifstream fin("players.txt");
    ofstream fout("temp.txt");
    string line;
    bool deleted = false;

    while (getline(fin, line)) {
        size_t pos = 0;
        string data[5];
        int i = 0;
        while ((pos = line.find(",")) != string::npos && i < 5) {
            data[i++] = line.substr(0, pos);
            line.erase(0, pos + 1);
        }
        if (i < 5)
            data[i] = line;

        if (data[0] != name) {
            fout << data[0] << "," << data[1] << "," << data[2] << "," << data[3] << "," << data[4] << endl;
        }
        else {
            deleted = true;
        }
    }

    fin.close();
    fout.close();

    if (deleted) {
        remove("players.txt");
        rename("temp.txt", "players.txt");
        cout << "Data deleted successfully......!" << endl;
    }
    else {
        remove("temp.txt");
        cout << "Player not found." << endl;
    }
}
