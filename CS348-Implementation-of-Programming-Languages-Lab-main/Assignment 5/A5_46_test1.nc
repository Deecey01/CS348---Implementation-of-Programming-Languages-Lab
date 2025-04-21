// test file for basic arithmetic
int main()
{
    int x = 2;
    int y = 3;
    int *ptr = &x;
    y = *ptr * 4;
    y = 4 * *ptr;
    *ptr = 4;
    return 0;
}
