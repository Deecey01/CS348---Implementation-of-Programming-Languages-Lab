int arr[10]; // Sorted array to search
// A recursive binary search function. It returns location of x
// in given array arr[l..r] is present, otherwise -1
int binarySearch(int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;
        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;
        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(l, mid - 1, x);
        // Else the element can only be present in right subarray
        return binarySearch(mid + 1, r, x);
    }
    // We reach here when element is not present in array
    return -1;
}
int main()
{
    int n = 5; // Number of elements
    arr[0] = 2;
    arr[1] = 3;
    arr[2] = 4;
    arr[3] = 10;
    arr[4] = 40;
    int x = 10; // Key to search
    int result = binarySearch(0, n - 1, x);
    if (result == -1)
        printStr("Element is not present in array");
    else
    {
        printStr("Element is present at index ");
        printInt(result);
    }
    return 0;
}