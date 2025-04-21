// Testing global arrays

int ar[10]; //global array

int main(){
    ar[0] = 5; //accessing global scope
    ar[1] = 6;
    printStr("Global array:\n");
    printStr("ar[0] = ");
    printInt(ar[0]);
    printStr("\n");

    int ar[5]; // local array
    ar[0] = 1; //accessing local scope
    ar[1] = 2;
    printStr("Local array:\n");
    printStr("ar[0] = ");
    printInt(ar[0]);
    printStr(" ");

}