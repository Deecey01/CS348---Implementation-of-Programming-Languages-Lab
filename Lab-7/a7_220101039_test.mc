// a7_220101039_test.mc - Test file for microC compiler
// This file tests all lexical rules of microC

/* This is a multi-line comment
   that should be ignored by the compiler */
// This is a single-line comment

// Testing declarations with different types
integer testInt;
float testFloat;
char testChar;
bool testBool;

// Forward declarations
void testFunction();

// Testing a simple function
integer factorial(integer n)
begin
    // Testing keywords inside functions
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
end

// Testing array declaration and usage
integer main()
begin
    // Testing identifiers
    integer identifier;
    integer abc123;
    integer x;
    integer longIdentifierName;
    integer A_B_C;

    // Testing array
    integer arr[10];
    integer i;
    integer result;
    
    // Testing constants
    // Integer constants
    i = 123;
    i = 0;
    i = 9876;

    // Floating constants
    float f;
    f = 123.456;
    f = .123;
    f = 123.;
    f = 1e10;
    f = 1.2e-5;
    f = 3.14E+2;

    // Character constants
    char c;
    c = 'a';
    c = '\n';
    c = '\t';
    c = '\'';
    c = '\\';

    // String literals
    testFunction("Hello, World!");
    testFunction("String with \"quotes\" inside");
    testFunction("String with \n newline");
    testFunction("Empty string");

    // Initialize array
    for (i = 0; i < 10; i = i + 1)
        arr[i] = i;
    
    // Calculate factorial of 5
    result = factorial(5);
    
    // Conditional expression
    integer max;
    max = (arr[3] > arr[5]) ? arr[3] : arr[5];
    
    // Testing pointers
    integer *ptr;
    ptr = &arr[0];
    
    // Testing operators
    i = i + 1;
    i = i - 1;
    i = i * 2;
    i = i / 2;
    i = i % 2;
    
    // Testing logical operators
    if ((result > 0) && (max < 100))
        return 1;
    else
        return 0;
end

// Dummy implementation 
void testFunction(char* str)
begin
    // Testing while and do
    integer count;
    /*you
    are dumb*/
    count = 0;
    while (count < 5)
        count = count + 1;
    
    do
        count = count - 1;
    while (count > 0);
end