struct add
{
    int result{};
    add(const int n) : result{n} {}
    
    add operator()(const int n)
    {
        return add(result+n);
    }
    
    operator int()
    {
        return result;
    }
    
    friend bool operator==(const int& lhs, const add& rhs)
    {
        return lhs == rhs.result;
    }
};