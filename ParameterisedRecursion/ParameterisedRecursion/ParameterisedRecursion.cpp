/*
use parameterised recursion to output the sum of all numbers from 1 to i
*/

#include <iostream>

// initially we start with sumFunction( 3, 0 )
void sumFunction(int i, int sum)
{
    if (i < 1)
    {
        std::cout << sum << std::endl;
        return;
    }
    // if i is initially 3
    // sumFunction( 2, 3 )
    // sumFunction( 1, 5 )
    // sumFunction( 0, 6 )
    sumFunction(i - 1, sum + i);
}

// we start with factorial(3, 1)
int factorial(int i, int fact)
{
    // base case: factorial of 0 and factorial of 1 is 1
    // at this time the value of fact is the fully calculated factorial
    if (i <= 1)
    {
        return fact;
    }
    // factorial ( 2, 3 )
    // factorial ( 1, 6 )
    return factorial(i - 1, fact * i);
}

int main()
{
    int i = 3;
    int sum = 0;
    int fact = 1;
    int resultFactorial = factorial(i, fact);

    sumFunction(i, sum);
    std::cout << resultFactorial << std::endl;

    return 0;
}

