/* Test file for micro C lexer */
integer x, y;
float total;
char ch;

begin
    x = 42;
    y = 10;
    total = x + y;
    
    if (total > 50) {
        // Single-line comment
        return true;
    } else {
        return false;
    }
    
    /* Multi-line
       comment 
       test */
    
    ch = 'A';
    const string msg = "Hello, World!";
end