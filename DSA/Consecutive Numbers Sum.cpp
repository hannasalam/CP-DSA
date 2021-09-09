    int consecutiveNumbersSum(int n) {
        int sum = 1;
        for(int i=2;i<sqrt(2*n);i++)
        {
            if((n-(i*(i-1))/2)%i==0)
            {
                sum++;
            }
        }
        return sum;
    }