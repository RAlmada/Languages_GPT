#include <iostream>
#include <limits>
#include <random>

using namespace std;

void checkSignE1(int value) {
	cout << "E1. Value [" << value << "] is ";
	if (value == 0) {
		cout << "ZERO" << endl;
	} else if (value > 0) {
		cout << "POSITIVE" << endl;
	} else {
		cout << "NEGATIVE" << endl;
	}
}

void checkNumberE2(int value) {
	cout << "E2. Value [" << value << "] is ";
	if (value == 0) {
		cout << "ZERO" << endl;
	} else if (value > 0) {
		if (value < 10) {
			cout << "POSITIVE SMALL" << endl;
		} else if (value < 100) {
			cout << "POSITIVE MEDIUM" << endl;
		} else {
			cout << "POSITIVE LARGE" << endl;
		}
	} else {
		if (value > -10) {
			cout << "NEGATIVE SMALL" << endl;
		} else if (value > -100) {
			cout << "NEGATIVE MEDIUM" << endl;
		} else {
			cout << "NEGATIVE LARGE" << endl;
		}
	}
}

void printNumbersUsingFor() {
	cout << "E3. Numbers from 1 to 10 using for loop: ";

	for (int i = 1; i <= 10; i++) {
		cout << i << " ";
	}

	cout << endl;
}

void printNumbersUsingWhile() {
	cout << "E3. Numbers from 11 to 20 using while loop: ";
	
	int i = 11;
	while (i <= 20) {
		cout << i++ << " ";
	}

	cout << endl;
}

void printNumbersUsingDoWhile() {
	cout << "E3. Numbers from 21 to 30 using do-while loop: ";

	int i = 21;
	do {
		cout << i++ << " ";
	} while (i <= 30);

	cout << endl;
}

void simulateATM() {
	bool active = true;
	double balance = 1000.0; // Initial balance

	while (active) {
		int option;
		cout << "ATM Menu:" << endl;
		cout << "1. Check Balance" << endl;
		cout << "2. Withdraw Money" << endl;
		cout << "3. Deposit Money" << endl;
		cout << "4. Exit" << endl;
		cout << "Select an option: ";
		cin >> option;

		if (cin.fail()) {
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			cout << "Invalid input! Please enter a valid option." << endl;
			cout << endl;
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		switch (option) {
			case 1:
				cout << "Your balance is: $" << balance << endl;
				break;

			case 2:
				double withdrawAmount;
				cout << "Enter amount to withdraw: $";
				cin >> withdrawAmount;

				if (withdrawAmount > balance) {
					cout << "Insufficient funds!" << endl;
				} else if (withdrawAmount <= 0) {
					cout << "Invalid amount!" << endl;
				} else {
					balance -= withdrawAmount;
					cout << "Withdrawal successful! New balance: $" << balance << endl;
				}

				break;
			
			case 3:
				double depositAmount;
				cout << "Enter amount to deposit: $";
				cin >> depositAmount;

				if (depositAmount <= 0) {
					cout << "Invalid amount!" << endl;
				} else {
					balance += depositAmount;
					cout << "Deposit successful! New balance: $" << balance << endl;
				}

				break;

			case 4:
				active = false;
				cout << "Exiting ATM. Thank you!" << endl;
				break;
		}

		cout << endl;
	}
}

void guessingGame() {
	random_device rd;
	mt19937 gen(rd());

	uniform_int_distribution<int> distrib(1, 100);
	int answer = distrib(gen);
	int guess;

	do {
		cout << "E5. Guess the number (1-100): ";
		cin >> guess;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! Please enter a number." << endl;
			continue;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (guess < answer) {
			cout << "Too low! Try again." << endl;
		} else if (guess > answer) {
			cout << "Too high! Try again." << endl;
		} else {
			cout << "Congratulations! You guessed the number!" << endl;
		}
	} while (guess != answer);
}

int main() {
	// E1. Check if a number is positive, negative or zero
	checkSignE1(-100);
	checkSignE1(1000);
	checkSignE1(0);
	checkSignE1(-0);

	cout << endl;

	// E2. Extend it to classif as large, small, or medium numbers
	checkNumberE2(-1000);
	checkNumberE2(-100);
	checkNumberE2(-10);
	checkNumberE2(-1);
	checkNumberE2(0);
	checkNumberE2(1);
	checkNumberE2(10);
	checkNumberE2(100);
	checkNumberE2(1000);

	cout << endl;

	// E3. Print numbers from 1 to 10 using all three loop types (for, while, do-while)
	printNumbersUsingFor();
	printNumbersUsingWhile();
	printNumbersUsingDoWhile();

	cout << endl;

	// E4. Simulate a simple ATM withdrawal system with conditionals and loops.
	simulateATM();

	cout << endl;

	// E5. Implement a number guessing game where the user guesses a random number (1-100)
	guessingGame();
}
