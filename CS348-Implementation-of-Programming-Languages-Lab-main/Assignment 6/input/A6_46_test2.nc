// Find max of three numbers
int main()
{
    int x = 2;
    int y = 3;
    int z = 1;
    int m;
    m = x > y ? x : y;
    m = m > z ? m : z;
    printStr("max(");
    printInt(x);
    printStr(", ");
    printInt(y);
    printStr(", ");
    printInt(z);
    printStr(") = ");
    printInt(m);
    return 0;
}