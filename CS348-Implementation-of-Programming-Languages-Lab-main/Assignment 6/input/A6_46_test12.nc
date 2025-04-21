// check for the use of ! in if statements
int main(){
    int x;
    int y;
    int err;

    printStr("This test is to check for the use of ! in if statements\n");
    printStr("Enter two numbers: ");

    x = readInt(&err);
    y = readInt(&err);

    if (x != y){
        printStr("x != y");
    }
    if (x == y){
        printStr("x == y");
    }
    if (x > y){
        printStr("x > y");
    }
    if (x < y){
        printStr("x < y");
    }
    if (x >= y){
        printStr("x >= y");
    }
    if (x <= y){
        printStr("x <= y");
    }
    if (x != y){
        printStr("x != y");
    }
    if (!(x == y)){
        printStr("!(x == y)");
    }
    if (!(x > y)){
        printStr("!(x > y)");
    }
    if (!(x < y)){
        printStr("!(x < y)");
    }
    if (!(x >= y)){
        printStr("!(x >= y)");
    }
    if (!(x <= y)){
        printStr("!(x <= y)");
    }
    if (!(x != y)){
        printStr("!(x != y)");
    }
    return 0;
}