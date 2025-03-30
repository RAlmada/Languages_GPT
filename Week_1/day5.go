package main

import "fmt"

func main() {
	// Exercise 1
	checkNumberE1(10)
	checkNumberE1(-5)
	checkNumberE1(0)

	fmt.Println()

	// Exercise 2
	checkNumberE2(150)
	checkNumberE2(50)
	checkNumberE2(5)
	checkNumberE2(0)
	checkNumberE2(-5)
	checkNumberE2(-50)
	checkNumberE2(-150)

	fmt.Println()

	// Exercise 3
	printNumbersE3()

	fmt.Println()

	// Exercise 4
	simulateATM()
}

func checkNumberE1(value int) {
	switch {
	case value < 0:
		fmt.Printf("E1. %d is a negative number\n", value)
	case value == 0:
		fmt.Printf("E1. %d is zero\n", value)
	case value > 0:
		fmt.Printf("E1. %d is a positive number\n", value)
	}
}

func checkNumberE2(value int) {
	if value < 0 {
		switch {
		case value < -100:
			fmt.Printf("E2. %d is a large negative number\n", value)
		case value < -10:
			fmt.Printf("E2. %d is a medium negative number\n", value)
		default:
			fmt.Printf("E2. %d is a small negative number\n", value)
		}
	} else if value > 0 {
		switch {
		case value > 100:
			fmt.Printf("E2. %d is a large positive number\n", value)
		case value > 10:
			fmt.Printf("E2. %d is a medium positive number\n", value)
		default:
			fmt.Printf("E2. %d is a small positive number\n", value)
		}
	} else {
		fmt.Printf("E2. %d is zero\n", value)
	}
}

func printNumbersE3() {
	fmt.Print("E3. Basic For Loop: ")
	for i := 1; i <= 10; i++ {
		fmt.Printf("%d ", i)
	}
	fmt.Println()

	fmt.Print("E3. For as While Loop: ")
	j := 11
	for j <= 20 {
		fmt.Printf("%d ", j)
		j++
	}
	fmt.Println()

	fmt.Print("E3. Infinite For Loop: ")
	k := 21
	for {
		if k > 30 {
			break
		}
		fmt.Printf("%d ", k)
		k++
	}
	fmt.Println()
}

func simulateATM() {
	balance := 1000.0 // Initial Balance

ATM_LOOP:
	for {
		fmt.Println("ATM Menu:")
		fmt.Println("1. Check Balance")
		fmt.Println("2. Deposit Money")
		fmt.Println("3. Withdraw Money")
		fmt.Println("4. Exit")
		fmt.Print("Select an option (1-4): ")

		var option int
		fmt.Scan(&option)

		switch option {
		case 1: // Check Balance
			fmt.Printf("Your current balance is: $%.2f\n", balance)
		case 2: // Deposit Money
			var deposit float64
			fmt.Print("Enter amount to deposit: $")
			fmt.Scan(&deposit)

			switch {
			case deposit <= 0:
				fmt.Println("Deposit amount must be positive.")
			default:
				balance += deposit
				fmt.Printf("Successfully deposited $%.2f. New balance: $%.2f\n", deposit, balance)
			}
		case 3: // Withdraw Money
			var withdraw float64
			fmt.Print("Enter amount to withdraw: $")
			fmt.Scan(&withdraw)

			switch {
			case withdraw <= 0:
				fmt.Println("Withdraw amount must be positive.")
			case withdraw > balance:
				fmt.Printf("Insufficient funds. Your current balance is: $%.2f\n", balance)
			default:
				balance -= withdraw
				fmt.Printf("Successfully withdrew $%.2f. New balance: $%.2f\n", withdraw, balance)
			}
		case 4: // Exit
			fmt.Println("Exiting ATM. Thank you!")
			break ATM_LOOP
		default:
			fmt.Println("Invalid option. Please select a valid option (1-4).")
		}

		fmt.Println()
	}
}
