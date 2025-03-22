integer square(integer x) begin
    return x * x;
end

integer sum_array(integer arr) begin
    integer sum = 0;
    for (i = 0; i < 5; i = i + 1) begin
        sum = sum + arr[i];
    end
    return sum;
end

integer main() begin
    integer y;
    y= square(5);
    integer i;
    integer a[5];
    for (i = 0; i < 5; i = i + 1) begin
        a[i] = i;
    end
    integer x;
    x= sum_array(a);
    
    return 0;
end

