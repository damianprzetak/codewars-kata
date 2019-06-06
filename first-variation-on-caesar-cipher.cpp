#include <iostream>
#include <string>
#include <vector>
#include <cmath>

class CaesarCipher
{
  public:
    static std::vector<std::string> movingShift(const std::string &s, int shift);
    static std::string demovingShift(std::vector<std::string> &s, int shift);
};

std::vector<std::string> CaesarCipher::movingShift(const std::string & s, int shift)
{
	std::string res = s;
	for (auto &ch : res) 
    {
		if (shift > 26) shift = 1;
		if (isalpha(ch)) {
			if ((ch + shift > 122 && ch > 96) || (ch + shift > 90 && ch < 91 && ch > 64)) 
                { 
                    ch -= 26; 
                }
			ch += shift;
		}
		shift++;
	}
	int acc = ceil(double(res.size())/double(5));
	
    std::vector<std::string> result = 
        { 
            std::string( res.begin(), res.begin() + acc ),
            std::string( res.begin() + acc, res.begin() + 2 * acc ),
            std::string( res.begin() + 2 * acc, res.begin() + 3 * acc ),
            std::string( res.begin() + 3 * acc, res.begin() + 4 * acc ),
            std::string( res.begin() + 4 * acc, res.end() )
        };
    return result;
}

std::string CaesarCipher::demovingShift(std::vector<std::string>& s, int shift)
{
	std::string res = s[0] + s[1] + s[2] + s[3] + s[4];
	for (auto &ch : res) {
		if (shift > 26) shift = 1;
		if (isalpha(ch)) 
        {
			if ((ch - shift < 97 && ch > 96) || (ch - shift < 65)) 
                {
                    ch += 26; 
                }
			ch -= shift;
		}
		shift++;
	}
	return res;
}