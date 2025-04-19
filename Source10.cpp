#include <iostream>
#include <fstream>
using namespace std;
void AddRecord();
void VewAllRecord();
void Update();
void DeleteRecord();
void VievRecordbyID();
int main() {
    while (true) {
        int choice = 0;
        cout << "\n Student Managment System\n";
        cout << "1. Add Student Record" << endl;
        cout << "2. View All Student Records" << endl;
        cout << "3. Update One Student Record" << endl;
        cout << "4. Delete Record Student" << endl;
        cout << "5. View Student by id" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1)
        {
            AddRecord();
        }
        else if (choice == 2)
        {
            VewAllRecord();
        }else if(choice == 3)
        {
            Update();
        }
        else if (choice == 4)
        {
            DeleteRecord();
        }
        else if (choice == 5)
        {
            VievRecordbyID();
        }
        else if (choice == 6)
        {
            cout << "Program End" << endl;
            break;
        }
        else
        {
            cout << "Enter a Valid Input." << endl;
        }
    }
    return 0;
}
void AddRecord() {
    ofstream out;
    out.open("student.txt", ios::app);
    if (out)
    {
        int id = 0;
        char name[50]{};
        int age = 0;
        char department[50]{};
        cout << "Enter ID :";
        cin >> id;
        cin.ignore();
        cout << "Enter Name:";
        cin.getline(name, 50);
        cout << "Enter Age :";
        cin >> age;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Incorrect age! Please enter a valid number." << endl;
            cout << "Enter Age :";
            cin >> age;

        }



        cin.ignore();


        cout << "Enter Department :";
        cin.getline(department, 50);

        out << id << ","
            << name << ","
            << age << ","
            << department << endl;
        cout << "Record Inter Successfully" << endl;
        out.close();

    }
}
void VewAllRecord() {
    ifstream in;
    in.open("student.txt");
    if (in)
    {

        int id = 0;
        char name[50]{};
        int age = 0;
        char department[50]{};
        char temp = '\0';
        bool isFound = false;
        
        cout << "\nStored Records:\n";
        cout << "--------------------------\n";
       
        while (in >> id) {

            in.ignore();
            in.getline(name, 50, ',');
            in >> age;

            in >> temp;
            in.getline(department, 50);
            cout << id << "|" << name << "|" << age << "|" << department << endl;
            isFound = true;

        }
        if (!isFound)
        {
            cout << "No Record Found" << endl;
        }
        in.close();
    }
}
void Update() {
    ifstream in;
    ofstream out;

    int id = 0;
    char name[50]{}, department[50]{};
    int age = 0;
    int inputid = 0;
    bool found = false;
    char title[200]{};
    char temp = '\0';
    in.open("student.txt");
    out.open("temp.txt");

    if (in)
    {
        cout << "Enter ID number you want to modify:";
        cin >> inputid;
      
        while (in >> id >> temp) {

          
            in.getline(name, 50, ',');
            in >> age;
            in >> temp;
            in.getline(department, 50);
            if (id == inputid)
            {
                found = true;
                cin.ignore();
                cout << "Enter Name :";
                cin.getline(name, 50);
                cout << "Enter age :";
                cin >> age;
                cin.ignore();
                cout << "Enter Number :";
                cin.getline(department, 50);
                

            }
            out << id << "," << name << "," << age << "," << department << endl;
        }
        if (!found)
        {
            cout << "No Mach ID Found" << endl;
        }
        else
        {
            cout << "ID Number Up Dated Succesfully....." << endl;
        }
        in.close();
        out.close();
    }


    in.open("temp.txt");
    out.open("student.txt");
    if (in)
    {
        
        while (!in.eof()) {
            in >> id;
            in >> temp;
            in.getline(name, 50, ',');
            in >> age;
            in >> temp;
            in.getline(department, 50);
            if (name[0] != '\0' && department[0] != '\0')
            {

                out << id << "," << name << "," << age << "," << department << endl;
            }
        }
    }
    in.close();
    out.close();
    remove("temp.txt");

}
void DeleteRecord() {
    ifstream in;
    ofstream out;

    int id = 0;
    char name[50]{}, department[50]{};
    int inputid = 0;
    bool found = false;
    char title[200]{};
    char temp = '\0';
    int age = 0;
    in.open("student.txt");
    out.open("temp.txt");

    if (in)
    {
        cout << "Enter ID number you want to Delete:";
        cin >> inputid;

        while (!in.eof()) {

            in >> id;
            in >> temp;
            in.getline(name, 50, ',');
            in >> age;
            in >> temp;
            in.getline(department, 50);
            if (id == inputid)
            {
                found = true;
                cout << "Name :" << name << endl;
                cout << "Age :" << age << endl;
                cout << "Department :" << department << endl;


            }
            if (inputid != id) {

                out << id << "," << name << "," << age << "," << department << endl;
            }
        }
        in.close();
        out.close();
    }
    if (found) {
        cout << "Record Deleted Succesfully." << endl;
    }
    else
    {
        cout << "ID Number not Found" << endl;
    }

    in.open("temp.txt");
    out.open("student.txt");
    if (in)
    {
        // in.getline(title, 200);
         //out << title << endl;

        while (!in.eof()) {
            in >> id;
            in >> temp;
            in.getline(name, 50, ',');
            in >> age;
            in >> temp;
            in.getline(department, 50);
            if (name[0] != '\0' && department[0] != '\0')
            {

                out << id << "," << name << "," << age << "," << department << endl;
            }
        }
    }
    in.close();
    out.close();
    remove("temp.txt");
}
void VievRecordbyID() {
    ifstream in;
    in.open("student.txt");
    if (in)
    {

        int id = 0;
        char name[50]{};
        char department[50]{};
        int age = 0;
        char temp = '\0';
        bool isFound = false;
        int inputId = 0;
        char title[200]{};
        cout << "Enter Id You Want to Show:";
        cin >> inputId;
        cout << "\nStored Records:\n";
        cout << "--------------------------\n";



        while (in >> id) {

            in.ignore();
            in.getline(name, 50, ',');
            in >> age;
            in >> temp;
            in.getline(department, 50);
            if (inputId == id)
            {
                isFound = true;
                cout << "ID Found Successfully ...." << endl;
                cout << "Name :" << name << endl;
                cout << "Age :" << age << endl;
                cout << "Number :" << department << endl;


            }

        }
        if (!isFound)
        {
            cout << "No MAch ID Found" << endl;
        }
        in.close();
    }
}




