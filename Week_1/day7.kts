println()

// Exercise 1

fun checkNumber(num: Int) {
    if (num > 0) {
        println("E1. $num is positive")
    } else if (num < 0) {
        println("E1. $num is negative")
    } else {
        println("E1. $num is zero")
    }
}

checkNumber(5)
checkNumber(-3)
checkNumber(0)

println()

// Exercise 2

fun checkNumberWithWhen(num: Int) {
    when {
        num > 0 -> println("E2. $num is positive")
        num < 0 -> println("E2. $num is negative")
        else -> println("E2. $num is zero")
    }
}

checkNumberWithWhen(5)
checkNumberWithWhen(-3)
checkNumberWithWhen(0)

println()

// Exercise 3

fun printEvenNumbersFromList(numbers: List<Int>) {
    for (number in numbers) {
        if (number % 2 == 0) {
            println("E3. $number is even")
        }
    }
}

printEvenNumbersFromList(listOf(1, 2, 3, 4, 5, 6))
printEvenNumbersFromList(listOf(7, 8, 9, 10, 11, 12))

println()

// Exercise 4

fun countdown(num: Int) {
    for (i in num downTo 1) {
        println("$i...")
    }

    println("Liftoff!")
}

countdown(10)

println()

// Exercise 5
fun fibonacciSeries(n: Int) {
    var a = 0
    var b = 1

    println("E5. The first $n Fibonacci numbers are: ")
    print("$a ")
    var count = 1
    while (count < n) {
        val c = a + b
        a = b
        b = c
        print("$a ")
        count++
    }
    println()
}

fibonacciSeries(10)

tailrec fun fibonacciTailRecursion(n: Int, a: Int = 0, b: Int = 1) {
    if (n == 0) return
    print("$a ")
    fibonacciTailRecursion(n - 1, b, a + b)
}

println("E5-C. The first 20 Fibonacci numbers using tail recursion:")
fibonacciTailRecursion(20)
