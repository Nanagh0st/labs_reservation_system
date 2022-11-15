#include "student.h";

Student::Student() {

}

//Argument constructor(student_id, user_name, password)
Student::Student(int id, string User_Name, string Password) {

    //Initial attribute
	this->User_Id = id;
	this->User_Name = User_Name;
	this->Password = Password;

    //Acquire lab information
    ifstream ifs;
    ifs.open(LAB_FILE, ios::in);

    Lab l;
    while (ifs >> l.computer_id && ifs >> l.max_num) {
        hash_lab[l.computer_id] = l.max_num;
    }
    ifs.close();
}

void Student::operMenu() {
    cout << "Welcome student: " << this->User_Name << " " << "login!" << endl;
    cout << "---------------------------------------------" << endl;
    cout << "                                             " << endl;
    cout << "                1.Apply reservation              " << endl;
    cout << "                                             " << endl;
    cout << "                2.Check my reservation             " << endl;
    cout << "                                             " << endl;
    cout << "                3.Cancel reservation                 " << endl;
    cout << "                                             " << endl;
    cout << "                0.Log out              " << endl;
    cout << "                                             " << endl;
    cout << "---------------------------------------------" << endl;
    cout << "Please select:" << endl;
}

void Student::applyorder() {
    
    cout << "Lab opening time are from Monday to Friday!" << endl;
    cout << "Please enter your request date: " << endl;
    cout << "1. Monday" << endl;
    cout << "2. Tuesday" << endl;
    cout << "3. Wednesday" << endl;
    cout << "4. Thursday" << endl;
    cout << "5. Friday" << endl;

    int date;
    int interval;
    int room;
    while (true) {
        cin >> date;
        if (date >= 1 && date <= 5) {
            break;
        }
        cout << "Error, please enter again" << endl;
    }

    cout << "Please enter your request time interval: " << endl;
    cout << "1. Morning" << endl;
    cout << "2. Afternoon" << endl;
    while (true) {
        cin >> interval;
        if (interval >= 1 && interval <= 2) {
            break;
        }
        cout << "Error, please enter again" << endl;
    }

    cout << "Please enter your request lab room: " << endl;
    for (auto l : hash_lab) {
        cout << l.first << " lab have available number: " << l.second << endl; 
    }
    while (true) {
        cin >> room;
        if (hash_lab.count(room)) {
            break;
        }
        cout << "Error, please enter again" << endl;
    }

    cout << "Request success! Application in progress" << endl;
    ofstream ofs;
    ofs.open(ORDER_FILE, ios::app);

    ofs << "date: " << date << " ";
    ofs << "interval: " << interval << " ";
    ofs << "student_id" << this->User_Id << " ";
    ofs << "student_name" << this->User_Name << " ";
    ofs << "status: " << 1 << endl;
     
    ofs.close();

    system("pause");
    system("cls");
     
}

void Student::showMyOrder() {
    OrderFile of;

    if (of.size == 0) {
        cout << "No reservation  record" << endl;
        system("pause");
        system("cls");
        return;
    }

    for (int i = 0; i < of.size; i++) {
        if (atoi(of.order_data[i]["student_id"].c_str()) == this->User_Id) {
            cout << "Reservation  time: Day " << of.order_data[i]["date"];
            cout << "Time interval: " << (of.order_data[i]["interval"] == "1" ? "Morning" : "Afternoon");
            cout << "Lab: " << of.order_data[i]["room_id"];
            string status = "Status: ";
            if (of.order_data[i]["status"] == "1") {
                status += "Reviewing";
            }
            else if (of.order_data[i]["status"] == "2") {
                status += "Success";
            }
            else if (of.order_data[i]["status"] == "-1") {
                status += "Deny";
            }
            else {
                status += "Reservation cancel";
            }
            cout << status << endl;
        }
    }
    system("pause");
    system("cls");
}


void Student::cancelOrder() {
    OrderFile of;
    if (of.size == 0) {
        cout << "No reservation record" << endl;
        system("pause");
        system("cls");
        return;
    }
    
    cout << "Please enter the reservation that need to be canceled" << endl;
    vector<int> v;
    int index = 1;
    

    for (int i = 0; i < of.size; i++) {

        //Determine corresponding student ID
        if (atoi(of.order_data[i]["student_id"].c_str()) == this->User_Id) {

            //Determine corresponding status of resveration
            if (of.order_data[i]["status"] == "1" || of.order_data[i]["status"] == "2") {
                v.push_back(i);
                cout << index++ << ". ";
                cout << "Resveration date: Day " << of.order_data[i]["date"];
                cout << "Time interval: "<< (of.order_data[i]["interval"] == "1" ? "Morning" : "Afternoon");
                cout << "Lab: " << of.order_data[i]["room_id"];
                string status = "Status: ";
                if (of.order_data[i]["status"] == "1") {
                    status += "Reviewing";
                }
                else if (of.order_data[i]["status"] == "2") {
                    status += "Success";
                }
                cout << status << endl;
            }
        }
    }
    cout << "Please enter the reservation need to cancel, 0 represent exit" << endl;
    int select = 0;

    while (true) {
        cin >> select;

        if (select >= 0 && select <= v.size()) {
            if (select == 0) {
                break;
            }
            else {
                of.order_data[v[select - 1]]["status"] = "0";

                of.updateFile();
                cout << "Cancel success" << endl;
                break;
            }
        }

        cout << "Error, pleaser enter again" << endl;
    }
    system("pause");
    system("cls");
}

