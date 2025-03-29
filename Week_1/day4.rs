//! ```cargo
//! [dependencies]
//! rand = "0.8"
//! ```

use rand::Rng;
use std::io::{self, Write};

fn main() {
    // Exercise 1
    check_number_e1(10);
    check_number_e1(-5);
    check_number_e1(0);

    println!();

    // Exercise 2
    check_number_e2(150);
    check_number_e2(50);
    check_number_e2(5);
    check_number_e2(0);
    check_number_e2(-5);
    check_number_e2(-50);
    check_number_e2(-150);

    println!();

    // Exercise 3
    for_loop_e3();
    while_loop_e3();
    loop_e3();

    println!();

    // Exercise 4
    simulate_atm_e4();

    println!();

    // Exercise 5
    guessing_game_e5();
}

fn check_number_e1(value: i32) {
    match value {
        x if x > 0 => println!("E1. {} is positive", x),
        x if x < 0 => println!("E1. {} is negative", x),
        _ => println!("E1. {} is zero", value)
    };
}

fn check_number_e2(value: i32) {
    if value > 0 {
        match value {
            x if x >= 100 => println!("E2. {} is a large positive number", x),
            x if x >= 10 => println!("E2. {} is a medium positive number", x),
            _ => println!("E2. {} is a small positive number", value),
        };
    } else if value < 0 {
        match value {
            x if x <= -100 => println!("E2. {} is a large negative number", x),
            x if x <= -10 => println!("E2. {} is a medium negative number", x),
            _ => println!("E2. {} is a small negative number", value),
        };
    } else {
        println!("E2. {} is zero", value);
    }
}

fn for_loop_e3() {
    print!("E3. For Loop: ");
    for i in 1..=10 {
        print!("{} ", i);
    }
    println!();
}

fn while_loop_e3() {
    let mut i = 11;
    print!("E3. While Loop: ");
    while i <= 20 {
        print!("{} ", i);
        i += 1;
    }
    println!();
}

fn loop_e3() {
    let mut i = 21;
    print!("E3. Loop: ");
    loop {
        if i > 30 {
            break;
        }
        print!("{} ", i);
        i += 1;
    }
    println!();
}

fn simulate_atm_e4() {
    let mut balance = 1000.0; // Initial balance

    loop {
        println!("ATM Menu:");
        println!("1. Check Balance");
        println!("2. Deposit Money");
        println!("3. Withdraw Money");
        println!("4. Exit");
        print!("Please select an option (1-4): ");
        io::stdout().flush().unwrap();

        let mut choice = String::new();
        io::stdin().read_line(&mut choice).expect("Failed to get option.");

        let choice: u32 = match choice.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Invalid input. Please enter a number between 1 and 4.");
                continue;
            }
        };

        match choice {
            1 => println!("Your balance is: ${:.2}", balance),
            2 => {
                print!("Enter amount to deposit: ");
                io::stdout().flush().unwrap();
                let mut deposit = String::new();
                io::stdin().read_line(&mut deposit).expect("Failed to read deposit amount.");
                let deposit: f64 = match deposit.trim().parse() {
                    Ok(num) => num,
                    Err(_) => {
                        println!("Invalid input. Please enter a valid number.");
                        continue;
                    }
                };

                match deposit {
                    x if x > 0.0 => {
                        balance += x;
                        println!("Deposited ${:.2}. New balance: ${:.2}", x, balance);
                    },
                    _ => println!("Invalid deposit amount. Please enter a positive number."),
                };
            },
            3 => {
                print!("Enter amount to withdraw: ");
                io::stdout().flush().unwrap();
                let mut withdraw = String::new();
                io::stdin().read_line(&mut withdraw).expect("Failed to read withdraw amount.");
                let withdraw: f64 = match withdraw.trim().parse() {
                    Ok(num) => num,
                    Err(_) => {
                        println!("Invalid input. Please enter a valid number.");
                        continue;
                    }
                };

                match withdraw {
                    x if x > 0.0 && x <= balance => {
                        balance -= x;
                        println!("Withdrew ${:.2}. New balance: ${:.2}", x, balance);
                    },
                    x if x > balance => println!("Insufficient funds. Your balance is only ${:.2}", balance),
                    _ => println!("Invalid withdraw amount. Please enter a positive number."),
                };
            },
            4 => {
                println!("Exiting ATM. Thank you!");
                break;
            },
            _ => println!("Invalid option. Please select a number between 1 and 4."),
        };

        println!();
    }
}

fn guessing_game_e5() {
    let mut rng = rand::thread_rng();
    let answer: i32 = rng.gen_range(1..=100);
    let mut attempts = 10;

    println!("E5. Guessing Game: You have {} attempts to guess the number between 1 and 100.", attempts);

    while attempts > 0 {
        print!("Enter your guess: ");
        io::stdout().flush().unwrap();

        let mut guess = String::new();
        io::stdin().read_line(&mut guess).expect("Failed to read guess.");
        let guess: i32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Invalid input. Please enter a number between 1 and 100.");
                continue;
            }
        };

        match guess {
            x if x < 1 || x > 100 => {
                println!("Invalid guess. Please enter a number between 1 and 100.");
                continue;
            },
            x if x == answer => {
                println!("Congratulations! You guessed the correct number in {} guesses", 10 - attempts + 1);
                break;
            },
            x if x < answer => {
                attempts -= 1;
                println!("Too low! You have {} attempts left.", attempts);
            },
            x if x > answer => {
                attempts -= 1;
                println!("Too high! You have {} attempts left.", attempts);
            },
            _ => unreachable!(),
        };

        println!();
    }
}
