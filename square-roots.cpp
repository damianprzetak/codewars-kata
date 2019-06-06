#include <string>

std::string simplify(int n)
{
    if (std::sqrt(n) - static_cast<int>(std::sqrt(n)) == 0) 
    {
		return std::to_string(static_cast<int>(std::sqrt(n)));
	}
	else 
    {
		for (int i{ n / 2 }; i >= 4; --i) 
        {
			if (n%i == 0 && std::sqrt(i) - static_cast<int>(std::sqrt(i)) == 0) 
            {
				return std::to_string(static_cast<int>(std::sqrt(i))) + " sqrt " + std::to_string(n / i);
			}
		}
	}
	return "sqrt " + std::to_string(n);
}

int desimplify(std::string s)
{
	auto _sqrt = std::find(s.rbegin(), s.rend(), 's');
	int value{};
	auto loop = [](auto _Begin, auto _Last, int counter = 0, int value=0) 
    {
		for (auto it = _Begin; it < _Last; ++it, ++counter) 
        {
		    value += (static_cast<int>(*it) - 48) * std::pow(10, counter);
	    }
		return value;
	};

	if (_sqrt == s.rend())                      // "2" 
    { 
		value = loop(s.rbegin(), s.rend());
		return value*value;
	}
	else if (_sqrt == s.rend()-1)               // "sqrt 2"
    {
        value = loop(s.rbegin(), _sqrt - 4);
		return value;
	}
	else                                        // "2 sqrt 2"
    {                                      
		value = loop(_sqrt + 2, s.rend());
		return value*value*loop(s.rbegin(),_sqrt-4);
	}
}