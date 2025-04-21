// test file for arrays
int arr[10];
int main()
{
    int x = 0;
    arr[0] = 10;
    arr[1] = x + arr[0];
    arr[2] = arr[1] + arr[0];
    int ar[2];
    ar[0] = 1;
    ar[1] = arr[2];
    for(x = 0; x < 10; x = x + 1)
    {
        arr[x] = x;
    }
    return 0;
}