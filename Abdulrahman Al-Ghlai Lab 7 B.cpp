// Abdulrahman Al-Ghlai w2029025
// Lab Assignment 7 Part B Lab
// July 23, 2023

// C++ code for Lab 7 Part B:


#include <iostream>
#include <cmath>

class MortgageCalculator {
public:
    MortgageCalculator(); // Default constructor

    // Setter functions
    void setLoanAmount(double amount);
    void setAnnualInterestRate(double rate);
    void setLoanYears(int years);

    // Getter functions
    double getMonthlyPayment() const;
    double getTotalAmountPaid() const;

private:
    double loanAmount;
    double annualInterestRate;
    int loanYears;

    double calculateMonthlyPayment() const;
    double calculateTotalAmountPaid() const;
};

MortgageCalculator::MortgageCalculator() {
    loanAmount = 0.0;
    annualInterestRate = 0.0;
    loanYears = 0;
}

void MortgageCalculator::setLoanAmount(double amount) {
    if (amount >= 0.0) {
        loanAmount = amount;
    }
}

void MortgageCalculator::setAnnualInterestRate(double rate) {
    if (rate >= 0.0) {
        annualInterestRate = rate;
    }
}

void MortgageCalculator::setLoanYears(int years) {
    if (years >= 0) {
        loanYears = years;
    }
}

double MortgageCalculator::calculateMonthlyPayment() const {
    if (annualInterestRate == 0 || loanYears == 0) {
        return 0.0;
    }

    double monthlyRate = (annualInterestRate / 12.0) / 100.0;
    double term = pow(1 + monthlyRate, 12 * loanYears);
    double monthlyPayment = (loanAmount * monthlyRate * term) / (term - 1);
    return monthlyPayment;
}

double MortgageCalculator::calculateTotalAmountPaid() const {
    double monthlyPayment = calculateMonthlyPayment();
    double totalAmountPaid = monthlyPayment * 12 * loanYears;
    return totalAmountPaid;
}

double MortgageCalculator::getMonthlyPayment() const {
    return calculateMonthlyPayment();
}

double MortgageCalculator::getTotalAmountPaid() const {
    return calculateTotalAmountPaid();
}

using namespace std;

int main() {
    MortgageCalculator mortgage;

    double loanAmount, annualInterestRate;
    int loanYears;

    // Input loan details
    cout << "Enter the loan amount: $";
    cin >> loanAmount;
    mortgage.setLoanAmount(loanAmount);

    cout << "Enter the annual interest rate (%): ";
    cin >> annualInterestRate;
    mortgage.setAnnualInterestRate(annualInterestRate);

    cout << "Enter the number of years of the loan: ";
    cin >> loanYears;
    mortgage.setLoanYears(loanYears);

    // Calculate and display results
    cout << fixed << showpoint << setprecision(2);
    cout << "Monthly Payment: $" << mortgage.getMonthlyPayment() << endl;
    cout << "Total Amount Paid: $" << mortgage.getTotalAmountPaid() << endl;

    return 0;
}
