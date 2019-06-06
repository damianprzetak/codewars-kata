#include <cmath>

class DigPow
{
public:
  static int digPow(int n, int p) 
    {
        int number = n;
        int temp = 10;
        int size = 1;
        int power = 1;

        while(temp < number)
        {
            temp*=10;
            ++size;
            }
        int *digits = new int[size]; 
        for(int i{}; i<size-1; ++i) 
        {
            power=std::pow(10, size-i-1);
            digits[i] = number/power;
            number-=digits[i]*power;
            }
        digits[size-1] = number;

        int sumary = 0;
        for(int i{}; i<size; ++i)
        {
            sumary += std::pow(digits[i], p+i);
        }

        return sumary%n!=0 ? -1 : sumary/n;
    }
};