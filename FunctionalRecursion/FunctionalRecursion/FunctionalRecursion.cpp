/*
use functional recursion to output the sum of all numbers from 1 to n
also factorial
*/

#include <iostream>

// initially we start with sumFunction( 3 )
int sumFunction(int n)
{
    if (n == 0)
    {
        return 0;
    }
    // if i is initially 3
    // sumFunction( 3 ) = 6
    // sumFunction( 2 ) = 3
    // sumFunction( 1 ) = 1
    // sumFunction( 0 ) = 0
    return n + sumFunction(n - 1);
}

int factorial(int n)
{
    // this could be n == 1 to return one iteration earlier since both factorial of 1 and 0 are 1
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n = 3;
    int sum = sumFunction( n );
    std::cout << sum << std::endl;

    int factorialOfN = factorial(n);
    std::cout << factorial << std::endl;

    return 0;
}

