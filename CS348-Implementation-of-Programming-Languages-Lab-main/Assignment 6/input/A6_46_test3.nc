// Add two numbers from input
int main()
{
    int x;
    int y;
    int z;
    int err;
    x = readInt(&err);
    y = readInt(&err);
    z = x + y;
    printInt(x);
    printStr("+");
    printInt(y);
    printStr(" = ");
    printInt(z);
    return 0;
}