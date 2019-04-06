int sumOfDigits(int a) 
{ 
    int sum = 0; 
    while (a) 
    { 
        sum += a % 10; 
        a /= 10; 
    } 
    return sum; 
}