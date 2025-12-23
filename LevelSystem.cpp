// Created by: Saleh-STR-Creator
// Feature: Advanced Leveling & XP System for Strategic Games

#include <iostream>
#include <string>

using namespace std;

class PlayerLevel System {
public:
    string creator = "Saleh-STR-Creator";
    int xp = 0;
    int level = 1;

    // دالة إضافة الخبرة وترقية المستوى
    void gainXP(int amount) {
        xp += amount;
        if (xp >= 100) {
            level++;
            xp = 0;
            cout << "Congratulations! Level Up to: " << level << endl;
        }
    }
};

int main() {
    cout << "System Security Active - Verified by " << "Saleh-STR-Creator" << endl;
    return 0;
}
