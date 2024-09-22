// Abdulrahman Al-Ghlai w2029025
// Lab Assignment 7 Part A Lab
// July 23, 2023

// C++ code for Lab 7 Part A:


#include <iostream>
#include <string>

using namespace std;

class memberType {
public:
    memberType(); // Default constructor
    memberType(const string& name, int memberId, int numBooksBought, double amountSpent); // Parameterized constructor

    // Getter functions
    string getName() const;
    int getMemberId() const;
    int getNumBooksBought() const;
    double getAmountSpent() const;

    // Setter functions
    void setName(const string& name);
    void setMemberId(int memberId);
    void setNumBooksBought(int numBooksBought);
    void setAmountSpent(double amountSpent);

    // Other member functions
    void showInfo() const;

private:
    string name;
    int memberId;
    int numBooksBought;
    double amountSpent;
};

// Default constructor
memberType::memberType() {
    name = "";
    memberId = 0;
    numBooksBought = 0;
    amountSpent = 0.0;
}

// Parameterized constructor
memberType::memberType(const string& name, int memberId, int numBooksBought, double amountSpent) {
    this->name = name;
    this->memberId = memberId;
    this->numBooksBought = numBooksBought;
    this->amountSpent = amountSpent;
}

// Getter functions
string memberType::getName() const {
    return name;
}

int memberType::getMemberId() const {
    return memberId;
}

int memberType::getNumBooksBought() const {
    return numBooksBought;
}

double memberType::getAmountSpent() const {
    return amountSpent;
}

// Setter functions
void memberType::setName(const string& name) {
    this->name = name;
}

void memberType::setMemberId(int memberId) {
    this->memberId = memberId;
}

void memberType::setNumBooksBought(int numBooksBought) {
    this->numBooksBought = numBooksBought;
}

void memberType::setAmountSpent(double amountSpent) {
    this->amountSpent = amountSpent;
}

// Show member information
void memberType::showInfo() const {
    cout << "Name: " << name << endl;
    cout << "Member ID: " << memberId << endl;
    cout << "Number of books bought: " << numBooksBought << endl;
    cout << "Amount spent: $" << amountSpent << endl;
}

int main() {
    // Create memberType objects
    memberType member1("John Doe", 1001, 5, 75.0);
    memberType member2;

    // Show initial member information
    cout << "Member 1 info:" << endl;
    member1.showInfo();
    cout << endl;

    cout << "Member 2 info (default values):" << endl;
    member2.showInfo();
    cout << endl;

    // Update member information
    member2.setName("Alice Smith");
    member2.setMemberId(1002);
    member2.setNumBooksBought(8);
    member2.setAmountSpent(120.5);

    // Show updated member information
    cout << "Member 2 info (updated values):" << endl;
    member2.showInfo();

    return 0;
}
