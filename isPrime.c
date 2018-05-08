#include <stdio.h>
#include <stdbool.h>
#include <math.h>


//Returns "Segmentation fault: 11" with negative numbers
int isPrime(unsigned long long int number)
{
    if(number == 1 || number == 4)
        return 0;
    else if(number == 2 || number == 3 || number == 5)
        return 1;
    
    int size = sqrt(number / 2) + 1;
    unsigned long long int primes[size]; primes[0] = 2; primes[1] = 3;

    bool bPrime;
    int index = 1;
    for(int i = 5; i <= sqrt(number); i += 2)
    {
        bPrime = true;
        for(int temp = 0; primes[temp] <= sqrt(i); ++temp)
        {
            if(number % primes[temp] == 0)
            {
                bPrime = false;
                break;
            }
        }
        if(bPrime)
        {
            ++index;
            primes[index] = i;
        }
    }
    for(int i = 0; i <= index; ++i)
    {
        if(number % primes[i] == 0)
            return 0;
    }
    return 1;
}
