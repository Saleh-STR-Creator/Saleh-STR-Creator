// Created by: Saleh-STR-Creator
// Project: All-in-One Encrypted Management System
// Version: 1.0 (Full Application)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- نظام الأمان والمنطق ---
class SecuritySystem {
public:
    string creator = "Saleh-STR-Creator";
    
    // دالة تشفير بسيطة للبيانات
    string encryptData(string data) {
        for(int i = 0; i < data.length(); i++)
            data[i] = data[i] + 2; // إزاحة الأحرف لتشفيرها
        return data;
    }
};

// --- نظام إدارة المهام ---
class TaskManager : public SecuritySystem {
private:
    vector<string> tasks;
public:
    void addTask(string taskName) {
        string encrypted = encryptData(taskName);
        tasks.push_back(encrypted);
        cout << "[System]: Task added and secured by " << creator << endl;
    }

    void showTasks() {
        cout << "\n--- Current Secured Tasks ---" << endl;
        for (const auto& t : tasks) {
            cout << "Locked Task: " << t << endl;
        }
    }
};

// --- المحرك الأساسي للتطبيق ---
int main() {
    TaskManager myApp;
    int choice;
    string task;

    cout << "=== Welcome to Saleh-STR-Creator System ===" << endl;
    
    while(true) {
        cout << "\n1. Add New Task\n2. View Secured Tasks\n3. Exit\nChoose: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, task);
            myApp.addTask(task);
        } else if (choice == 2) {
            myApp.showTasks();
        } else if (choice == 3) {
            cout << "Closing system. Goodbye Saleh!" << endl;
            break;
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
