

// test file for relational operators and logical operators
int main()
{
    int x = 5;
    int y = 7;
    int z;
    if(x>y)
    {
        z = 1;
    }
    else if (x<y)
    {
        z = 2;
    }
    else if (x>=y)
    {
        z = 3;
    }
    else if (x<=y)
    {
        z = 4;
    }
    else if (x==y)
    {
        z = 5;
    }
    else if (x!=y)
    {
        z = 6;
    }
    else if((x>=2) || y<3)
    {
        z = 7;
    }
    else if(x!= 0 && y != 0)
    {
        z = 8;
    }
    return 0;
}