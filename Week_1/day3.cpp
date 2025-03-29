#include <iostream>

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
	
}
