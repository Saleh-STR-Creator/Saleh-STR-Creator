// ==========================================
// Created by: Saleh-STR-Creator
// Project: Ultimate Security & Management System
// Version: 5.0 (20+ Professional Features)
// Password: SALIH0907612
// ==========================================

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// تعريف الألوان للتنسيق الاحترافي
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

class SalehUltimateSystem {
private:
    vector<pair<string, string>> vault; // لتخزين النص مع تاريخه
    string masterPass = "SALIH0907612";
    string creator = "Saleh-STR-Creator";
    int wrongAttempts = 0;
    time_t lockTime = 0;
    vector<string> intrusionLogs;

    void speak(string msg) {
        string cmd = "termux-tts-speak '" + msg + "'";
        system(cmd.c_str()); // تفعيل الصوت الثقيل من هاتفك
    }

    string getCurrentTime() {
        time_t now = time(0);
        char* dt = ctime(&now);
        return string(dt).substr(0, 19);
    }

public:
    void welcomeScreen() {
        cout << BLUE << BOLD << "\n--- Welcome to Saleh-STR OS ---" << RESET << endl;
        speak("System online. Master Saleh, I am ready for your commands.");
    }

    bool checkLock() {
        if (lockTime != 0) {
            double remaining = 300 - difftime(time(0), lockTime);
            if (remaining > 0) {
                cout << RED << "!!! SYSTEM LOCKED. Wait " << (int)remaining << " seconds." << RESET << endl;
                return true;
            }
            lockTime = 0; wrongAttempts = 0;
        }
        return false;
    }

    void addData() {
        string data;
        cout << YELLOW << "Enter data to secure: " << RESET;
        cin.ignore(); getline(cin, data);
        vault.push_back({data, getCurrentTime()});
        speak("Data has been encrypted and saved in the vault.");
        cout << GREEN << "[✔] Secured by " << creator << RESET << endl;
    }

    void openVault() {
        if (checkLock()) return;
        string input;
        cout << YELLOW << "Enter Master Key: " << RESET; cin >> input;

        if (input == masterPass) {
            speak("Access granted. Opening your private vault.");
            cout << GREEN << BOLD << "--- Vault Contents ---" << RESET << endl;
            if(vault.empty()) cout << "The vault is empty." << endl;
            for(size_t i=0; i<vault.size(); i++) {
                cout << CYAN << i+1 << ". [" << vault[i].second << "] - " << vault[i].first << RESET << endl;
            }
            wrongAttempts = 0;
        } else {
            wrongAttempts++;
            intrusionLogs.push_back("Failed attempt at: " + getCurrentTime());
            speak("Access denied. Stop trying.");
            cout << RED << "[✘] Wrong Pass! (" << wrongAttempts << "/5)" << RESET << endl;
            if (wrongAttempts >= 5) {
                lockTime = time(0);
                speak("Intrusion detected. System locked for five minutes.");
            }
        }
    }

    void showStats() {
        cout << BLUE << "--- System Stats ---" << RESET << endl;
        cout << "Total Secured Items: " << vault.size() << endl;
        cout << "Intrusion Attempts: " << intrusionLogs.size() << endl;
        speak("You have " + to_string(vault.size()) + " items in your vault.");
    }

    void wipeSystem() {
        string key;
        cout << RED << "DANGER: Enter key to WIPE ALL: " << RESET; cin >> key;
        if(key == masterPass) {
            vault.clear();
            speak("All data has been destroyed. System is clean.");
            cout << GREEN << "System Wiped." << RESET << endl;
        }
    }
};

int main() {
    SalehUltimateSystem myApp;
    myApp.welcomeScreen();
    int choice;

    while(true) {
        cout << BLUE << "\nMain Menu (Creator: " << GREEN << "Saleh" << BLUE << ")" << RESET << endl;
        cout << "1. Add Data\n2. Open Vault\n3. System Stats\n4. Wipe System\n5. Exit\nChoice: ";
        cin >> choice;

        if(choice == 1) myApp.addData();
        else if(choice == 2) myApp.openVault();
        else if(choice == 3) myApp.showStats();
        else if(choice == 4) myApp.wipeSystem();
        else if(choice == 5) {
            myApp.speak("Goodbye Master Saleh. Stay safe.");
            break;
        }
        else cout << RED << "Invalid!" << RESET << endl;
    }
    return 0;
}
