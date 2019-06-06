int cycle(int n)
{  
    if(n%2 == 0 || n%5 == 0)
        return -1;
    
    int currentRest{10 - (10/n)*n};
    int counter{1};
    
    while(currentRest!=1) 
    {
        currentRest = 10*currentRest - (10*currentRest/n)*n;
        ++counter;
    }
    return counter;
}