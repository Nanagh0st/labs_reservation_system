#include <iostream>
using namespace std;
#include "Identity.h"
#include "globalFile.h"
#include <fstream>
#include <string>
#include "student.h";
#include "teacher.h"
#include "admin.h";

//student submenu
void studentMenu(Identity*& student) {
    while (true) {
        student->operMenu();

        Student* stu = (Student*)student;

        int select = 0;

        cin >> select;

        //Apply resveration
        if (select  == 1) {
            stu->applyorder();
        }

        //Show own order
        else if (select == 2) {
            stu->showMyOrder();
        }

        //Cancel order
        else if (select == 3) {
            stu->cancelOrder();
        }

        //Log out
        else {
            delete student;
            cout << "Log out success" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}


//admin submenu
void adminMenu(Identity*& admin) {
    while (true) {
        admin->operMenu();

        Admin* adm = (Admin*)admin;
        
        int select = 0;

        cin >> select;
        if(select == 1) {
            cout << "Add account" << endl;
            adm->addAccount();
        }
        else if (select  == 2) {
            cout << "Check account" << endl;
            adm->showAccount();
        }
        else if (select == 3) {
            cout << "Check lab" << endl;
            adm->showLab();
        }
        else if (select == 4) {
            cout << "Clear reservation" << endl;
            adm->emptyRecord();
        }
        else {
            delete admin;
            cout << "Log out success" << endl;
            system("pause");
            system("cls");
            return;
        }
            
    }
}

void TeacherMenu(Identity*& teacher) {
    while (true) {
        teacher->operMenu();
        Teacher* tea = (Teacher*)teacher;
        int select = 0;
        cin >> select;
        if (select == 1) {
            tea->showAllOrder();
        }
        else if (select == 2) {
            tea->reviewOrder();
        }
        else {
            delete teacher;
            cout << "Log out success" << endl;
            system("pause");
            system("cls");
            return;
        }
    }
}



void LoginIn(string fileName, int type) {
    Identity* account = NULL;

    ifstream ifs;
    ifs.open(fileName, ios::in);

    if (!ifs.is_open()) {
        cout << "File does not exist" << endl;
        ifs.close();
        return;
    }

    int id = 0; 
    string name;
    string password;

    if (type == 1) {
        cout << "Please enter your student ID" << endl;
        cin >> id;
        
    }
    else if(type == 2) {
        cout << "Please enter your teacher ID" << endl;
        cin >> id;
    }

    cout << "Please enter your user_Id" << endl;
    cin >> name;

    cout << "Please enter your password" << endl;
    cin >> password;

    if (type == 1) {
        int fId;
        string fName;
        string fPassword;
        while (ifs >> fId && ifs >> fName && ifs >> fPassword) {

            if (id == fId && name == fName && password == fPassword) {
                cout << "Student login success" << endl;
                system("pause");
                system("cls");
                account = new Student(id, name, password);

                studentMenu(account);
                return;

            }
        }
    }
    else if (type == 2) {
        int fId;
        string fName;
        string fPassword;
        while (ifs >> fId && ifs >> fName && ifs >> fPassword) {

            if (id == fId && name == fName && password == fPassword) {
                cout << "Teacher login success" << endl;
                system("pause");
                system("cls");
                account = new Teacher(id, name, password);
                TeacherMenu(account);

                return;

            }
        }

    }
    else if (type == 3) {
        string fName;
        string fPassword;
        while (ifs >> fName && ifs >> fPassword) {

            if (name == fName && password == fPassword) {
                cout << "Admin login success" << endl;
                system("pause");
                system("cls");
                account = new Admin(name, password);

                adminMenu(account);

                return;

            }
        }

    }
    cout << "Login failed" << endl;

    system("pause");
    system("cls");
    return;
}


int main()
{
    cout<< "----------- Welcome to Lab Resveration System -----------"<<endl;
    int select;
    while (true) {
        cout << "Please enter your identity" << endl;
        cout << "1. Students" << endl;
        cout << "2. Teachers" << endl;
        cout << "3. Administrator" << endl;
        cout << "0. Exit" << endl;
        cout << "Please enter your choice:";
        cin >> select;
        switch (select) {
        case 1:
            LoginIn(STUDENT_FILE, 1);
            break;
        case 2:
            LoginIn(TEACHER_FILE, 2);
            break;
        case 3:
            LoginIn(ADMIN_FILE, 3);
            break;
        case 0:
            cout << "Thanks using the system" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "Sorry, error with your choice" << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}

