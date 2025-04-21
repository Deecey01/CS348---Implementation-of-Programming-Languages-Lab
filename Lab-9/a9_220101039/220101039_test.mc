/* 220101039_test.mc */

/* Global variable declarations */
integer globalVar;
float globalFloat = 3.14;
integer globalArray[10];
integer *globalPtr;

/* Function declarations */
void printArray(integer arr[10], integer size);
integer factorial(integer n);
float computeAverage(integer values[10], integer count);

/* Function to test expressions and loops */
integer factorial(integer n) 
begin
    integer result = 1;
    integer i = 1;
    
    /* Testing while loop and arithmetic expressions */
    while (i <= n) 
    begin
        result = result * i;
        i = i + 1;
    end
    
    return result;
end

/* Function to test arrays and loops */
void printArray(integer arr[10], integer size) 
begin
    integer i = 0;
    
    /* Testing do-while loop */
    do 
    begin
        /* Testing array access and assignment */
        globalVar = arr[i];
        i = i + 1;
    end while (i < size);
end

/* Function to compute average of array elements */
float computeAverage(integer arr[10], integer count) 
begin
    integer sum = 0;
    integer i = 0;
    
    while (i < count) 
    begin
        sum = sum + arr[i];
        i = i + 1;
    end
    
    return sum / count;
end

/* Main function to test conditional statements */
void main() 
begin
    /* Declaration with initialization */
    integer x = 10;
    integer y = 20;
    integer z;
    float result;
    integer numbers[10];
    integer *ptr;
    
    /* Testing address-of and dereference operators */
    ptr = &x;
    *ptr = 15;
    
    /* Testing assignment and arithmetic expressions */
    z = x + y * 2;
    z = z - 5;
    
    /* Testing relational and logical expressions */
    if (x > 0 && y < 30) 
    begin
        z = x * y;
    end 
    else 
    begin
        z = x + y;
    end
    
    /* Testing nested if-else */
    if (z > 100) 
    begin
        if (x == 15) 
        begin
            z = z + 10;
        end 
        else 
        begin
            z = z - 10;
        end
    end
    
    /* Initialize array */
    numbers[0] = 5;
    numbers[1] = 10;
    numbers[2] = 15;
    numbers[3] = 20;
    numbers[4] = 25;
    numbers[5] = 30;
    numbers[6] = 35;
    numbers[7] = 40;
    numbers[8] = 45;
    numbers[9] = 50;
    
    /* Testing function calls with parameters */
    printArray(numbers, 10);
    
    /* Testing function call with return value */
    z = factorial(5);
    
    /* Testing function call with float return */
    result = computeAverage(numbers, 10);
    
    /* Testing bitwise and shift operators */
    x = x & y;
    y = y | 5;
    z = z << 2;
    z = z >> 1;
    
    /* Testing unary operators */
    x = -x;
    z = !z;
    
    /* Testing conditional expression */
    x = (y > 10) ? y : 10;
    
    /* Testing pointer dereferencing */
    ptr = &z;
    *ptr = 42;
    
    return;
end