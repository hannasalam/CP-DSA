#define ll long long
class Solution {
public:
   int p = 1e9 + 7;
    
    ll power(long long x, long long n) {
      if(n==0) return 1;
    else if(n%2 == 0)        
        return power((x*x)%p,n/2)%p;
    else                             
        return x*(power((x*x)%p,(n-1)/2)%p)%p;
    }
  
    int countGoodNumbers(long long n) {
      ll count_of_4s = n/2;
      ll count_of_5s = n - count_of_4s;
      ll ans = ((power(4LL, count_of_4s) % p  * power(5LL, count_of_5s) % p) % p);
      return (int)ans;
    }
};