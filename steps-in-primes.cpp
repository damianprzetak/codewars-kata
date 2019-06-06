struct StepInPrimes
{
	static std::pair<long long, long long> step(int g, long long m, long long n) 
    {
		auto isPrime = [&m](int x) 
        {
			for (int i(2); i*i <= m+x; i++) 
            {
				if ((m+x)%i == 0)
				    return false;
			}
			return true;
		};

		for (; m != n; m++) 
        {
			if (m == 2 || m % 2 != 0) 
            {
				if (isPrime(0) && isPrime(g)) 
                {
					return { m, m+g };
				}
			}
		}
		return { 0,0 };
	};
};