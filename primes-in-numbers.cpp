#include <string>

class PrimeDecomp
{
public:
    static std::string factors(int lst)
    {
        std::string res{};
        int counter{}, multiplier{2};
        do
        {
            if(lst%multiplier == 0)
            {
                lst/=multiplier;
                ++counter;
            }
            else
            {
                if(counter)
                    displayPrimes(res, counter, multiplier);
                counter = 0;
                ++multiplier;
            }
        } while(lst >= multiplier);
        displayPrimes(res, counter, multiplier);
        return res;
    };
    
private:
    static void displayPrimes(std::string& res, int& counter, int& multiplier)
    {
         res+= counter > 1 ? "(" + std::to_string(multiplier) + "**" + std::to_string(counter) + ")" 
                                      : "(" + std::to_string(multiplier) + ")";
    }
};