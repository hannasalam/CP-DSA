int Solution::solve(int a) {
    int count=0,i=0;
    while(a)
    {
        if((a>>i)& 1 == 1)
        {
            break;
        }
        count++;
        i++;
    }
    return count;
}