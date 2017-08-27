

int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
     if (n == 0) 
     return (1 % d);

    long long res=1,base=x;
    while (n > 0) 
    {
     if (n % 2 ==0) 
    {
      base = (base * base) % d;
      n /= 2;
                
      } 
      else 
      {
       res = (res * base) % d;
        n--;
                
         }
     
      }
     if (res < 0) 
     res = (res + d) % d;
            
    return res;
    
}
