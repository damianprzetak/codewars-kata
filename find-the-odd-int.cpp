#include <vector>

int findOdd(const std::vector<int>& arg)
{
    std::vector<int> numbers{ arg };
	std::sort(numbers.begin(), numbers.end());
	int counter{1};
	for (int i{ 1 }; i < numbers.size(); ++i) 
    {
		if (numbers.at(i - 1) == numbers.at(i))
			counter++;
		else if (counter % 2 == 1)
			return numbers.at(i - 1);
		else
			counter = 1;
	}
	return numbers.back();
}