import Foundation

// Exercise 1

func checkNumberE3(_ num: Int) {
    if num > 0 {
        print("E1. \(num) is positive")
    } else if num < 0 {
        print("E1. \(num) is negative")
    } else {
        print("E1. \(num) is zero")
    }
}

checkNumberE3(5)
checkNumberE3(-3)
checkNumberE3(0)

print()

// Exercise 2

func checkNumberE2(_ num: Int) {
    if num > 0 {
        if num > 100 {
            print("E2. \(num) is a large positive")
        } else if num > 10 {
            print("E2. \(num) is a medium positive")
        } else {
            print("E2. \(num) is a small positive")
        }
    } else if num < 0 {
        if num < -100 {
            print("E2. \(num) is a large negative")
        } else if num < -10 {
            print("E2. \(num) is a medium negative")
        } else {
            print("E2. \(num) is a small negative")
        }
    } else {
        print("E2. \(num) is zero")
    }
}

checkNumberE2(150)
checkNumberE2(50)
checkNumberE2(5)
checkNumberE2(0)
checkNumberE2(-5)
checkNumberE2(-50)
checkNumberE2(-150)

print()

// Exercise 3

func printNumbers() {
    print("E3. For-In loop:", terminator: " ")
    for i in 1...10 {
        print(i, terminator: " ")
    }
    print()

    print("E3. While Loop:", terminator: " ")
    var j = 11
    while j <= 20 {
        print(j, terminator: " ")
        j += 1
    }
    print()

    print("E3. Repeat-While Loop:", terminator: " ")
    var k = 21
    repeat {
        print(k, terminator: " ")
        k += 1
    } while k <= 30
    print()
}

printNumbers()

print()

// Exercise 4

func simulateATM() {
    var balance = 1000.0
    var exit = false

    repeat {
        print("ATM Menu")
        print("1. Check Balance")
        print("2. Deposit Money")
        print("3. Withdraw Money")
        print("4. Exit")
        print("Enter your choice (1-4): ", terminator: "")

        if let choice = readLine() {
            switch choice {
                case "1":
                    print("Your balance is: $\(balance)")
                case "2":
                    print("Enter amount to deposit: $", terminator: "")
                    if let amount = readLine(), let depositAmount = Double(amount) {
                        if depositAmount <= 0 {
                            print("Invalid amount.")
                            break
                        }

                        balance += depositAmount
                        print("Deposited: $\(depositAmount)")
                        print("New balance: $\(balance)")
                    } else {
                        print("Invalid amount.")
                    }
                case "3":
                    print("Enter amount to withdraw: $", terminator: "")
                    if let amount = readLine(), let withdrawAmount = Double(amount) {
                        if withdrawAmount <= balance && withdrawAmount > 0 {
                            balance -= withdrawAmount
                            print("Withdrawn: $\(withdrawAmount)")
                            print("New balance: $\(balance)")
                        } else if withdrawAmount <= 0 {
                            print("Invalid amount.")
                        } else {
                            print("Insufficient funds.")
                        }
                    } else {
                        print("Invalid amount.")
                    }
                case "4":
                    print("Exiting ATM. Thank you!")
                    exit = true
                default:
                    print("Invalid choice. Please try again.")
            }
        }

        print()
    } while !exit
}

simulateATM()

print()

// Exercise 5

func containsPattern(_ password: String, pattern: String) -> Bool {
    guard let regex = try? NSRegularExpression(pattern: pattern) else { return false }
    let range = NSRange(password.startIndex..., in: password)
    return regex.firstMatch(in: password, range: range) != nil
}

func verifyPasswordReqs(_ password: String) -> Bool {
    let minLength = 8
    let uppercaseRegex = ".*[A-Z].*"
    let lowercaseRegex = ".*[a-z].*"
    let digitRegex = ".*[0-9].*"
    let specialCharRegex = ".*[!@#$%^&*()_+\\-=\\[\\]{};':\"\\\\|,.<>\\/?].*"

    let hasUppercase = containsPattern(password, pattern: uppercaseRegex)
    let hasLowercase = containsPattern(password, pattern: lowercaseRegex)
    let hasDigit = containsPattern(password, pattern: digitRegex)
    let hasSpecialChar = containsPattern(password, pattern: specialCharRegex)
    let longEnough = password.count >= minLength

    return hasUppercase && hasLowercase && hasDigit && hasSpecialChar && longEnough
}

print("E5. Password verification:")
print(verifyPasswordReqs("Password123!")) // true
print(verifyPasswordReqs("password123!")) // false
