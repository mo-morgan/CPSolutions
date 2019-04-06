int prodOfDigits(int a) 
{ 
    int prod = 0; 
    while (a) 
    { 
        prod *= a % 10; 
        a /= 10; 
    } 
    return prod; 
} 
  