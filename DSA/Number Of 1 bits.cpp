int Solution::numSetBits(unsigned int A) {
    int rem,count = 0;
    while(A)
    {
        A= A&(A-1);
        count++;
    }
    return count;
    
    
}