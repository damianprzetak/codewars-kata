#include <string>
#include <vector>

std::string range_extraction(std::vector<int> args) 
{
	args.push_back(args[0]);
	std::vector<int>::iterator ptrBegin{args.begin()} , ptrEnd{args.begin()};
	std::string result{""};
	int k{-1};
	for (; ptrEnd != args.end(); ++ptrEnd) 
    {
		if (*ptrBegin == (*ptrEnd) - k-1) 
        {
			k++;
		}
		else 
        {
			result += (std::to_string(*ptrBegin));
			if (k == 1 ) 
            {
				result+=",";
				result+=(std::to_string(*(ptrEnd - 1)));
			}
			else if (k > 1) 
            {
				result+="-";
				result+=(std::to_string(*(ptrEnd - 1)));
			}
			result+=",";
			k = 0;
			ptrBegin = ptrEnd;
		}
	}
	result.erase(result.end()-1);
	return result;
};