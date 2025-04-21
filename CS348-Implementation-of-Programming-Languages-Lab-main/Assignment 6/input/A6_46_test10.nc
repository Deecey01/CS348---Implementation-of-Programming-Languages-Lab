// Use pointers to swap two numbers
int main(){
    int x = 5;
    int *p = &x;
    int y = 6;
    int *q = &y;
    int t;
    t = *p;
    *p = *q;
    *q = t;
    printStr("After swap:\n");
    printStr("x = ");
    printInt(x);
    printStr(" ");
    printStr("y = ");
    printInt(y);
    return 0;
}