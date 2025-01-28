package main

import "fmt"

func fib(n int) int {
    if n == 0 {
        return 0
    }
    if n == 1 {
        return 1
    }

    prev1, prev2 := 0, 1
    for i := 2; i <= n; i++ {
        current := prev1 + prev2
        prev1 = prev2
        prev2 = current
    }
    return prev2
}

func main() {
    fmt.Println(fib(10)) // Output: 55
}
