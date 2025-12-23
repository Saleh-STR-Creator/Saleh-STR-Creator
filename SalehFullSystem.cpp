// Created by: Saleh-STR-Creator
// Project: Secure Task Manager - Ultimate Edition
// Access Password: SALIH0907612

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- نظام الأمان والمنطق ---
class SecuritySystem {
public:
    string creator = "Saleh-STR-Creator";
    
    // خوارزمية تشفير البيانات
    string encryptData(string data) {
        for(int i = 0; i < data.length(); i++)
            data[i] = data[i] + 2; 
        return data;
    }
};

// --- نظام إدارة المهام المحمي ---
class TaskManager : public SecuritySystem {
private:
    vector<string> tasks;
    string masterPass = "SALIH0907612"; // كلمة المرور الجديدة الخاصة بك

public:
    void addTask(string taskName) {
        tasks.push_back(encryptData(taskName));
        cout << "[System]: Data encrypted and locked by " << creator << endl;
    }

    void showTasks() {
        string input;
        cout << "\n[Security] Enter Password to View: ";
        cin >> input;

        if (input == masterPass) {
            cout << "--- Access Granted ---" << endl;
            if(tasks.empty()) cout << "The vault is empty." << endl;
            for (const auto& t : tasks) {
                cout << ">> Locked Task: " << t << endl;
            }
        } else {
            cout << "!!! Wrong Password! Access Denied !!!" << endl;
        }
    }

    void clearAllData() {
        string input;
        cout << "\n[WARNING] Enter Password to WIPE ALL DATA: ";
        cin >> input;

        if (input == masterPass) {
            tasks.clear();
            cout << "[System]: All data has been permanently deleted." << endl;
        } else {
            cout << "[System]: Unauthorized attempt! Action canceled." << endl;
        }
    }
};

// --- المحرك الأساسي للتطبيق ---
int main() {
    TaskManager myApp;
    int choice;
    string t;

    while(true) {
        cout << "\n===============================" << endl;
        cout << "   Saleh-STR-Creator System    " << endl;
        cout << "===============================" << endl;
        cout << "1. Add Encrypted Task\n2. View Secured Tasks\n3. Wipe All Data\n4. Exit\nChoice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "Enter task: ";
            cin.ignore();
            getline(cin, t);
            myApp.addTask(t);
        } else if(choice == 2) {
            myApp.showTasks();
        } else if(choice == 3) {
            myApp.clearAllData();
        } else if(choice == 4) {
            cout << "Exiting... Stay secure, Saleh!" << endl;
            break;
        } else {
            cout << "Invalid Option!" << endl;
        }
    }
    return 0;
}

