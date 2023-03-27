int myfact(int num)
{
    int fact = 1;
    for(int x=1; x<=num; x++)
    {
        fact=fact*x;
    }
    return fact;
}
