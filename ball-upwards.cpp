struct Ball
{
    static int maxBall(double v0);
};

int Ball::maxBall(double v0)
{
    v0 *= 100./36.;
    int thmax = static_cast<int>(v0/9.81); 
    auto h = [&](const auto& t)
    {
        return t*(v0 - 4.905*t);
    };
    return h(thmax) > h(thmax+1) ? thmax : thmax+1;
}