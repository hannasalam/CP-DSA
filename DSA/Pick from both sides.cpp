//method 1 - Sliding window
int Solution::solve(vector<int> & A, int b) {
   int x = A.size()-b;
   int slider = 0;
   for(int i=0;i<x;i++)
   {
       slider+= A[i];
   }
   int sum = slider;
   for(int i=x;i<A.size();i++)
   {
       sum+=A[i];
   }
   //cout<<sum;
   int final = slider;
   for(int i=x;i<A.size();i++)
   {
       //slider-=A[i-1];
       slider-= A[i-x];
       slider+= A[i];
       final = min(slider,final);
       //cout<<final<<" ";
   }
   return (sum-final);
   
   }

//method 2- Prefix sum
int Solution::solve(vector<int> & cardPoints, int k) {
    int len=cardPoints.size()+1;
        vector<int>prefixsum(len,0);
        //Build the prefix sum array
        for(int i=1;i<len;i++) prefixsum[i]=prefixsum[i-1]+cardPoints[i-1];
        
    int max_sum=INT_MIN;
    
    for(int i=0;i<=k;i++)
    {
        int left_sum=prefixsum[i];//Assuming number of cards picked from left is i
        int right_sum=prefixsum[len-1]-prefixsum[len-(k-i)-1];//The remaining cards are picked from right end
        max_sum=max(max_sum,left_sum+right_sum);//Storing the maximum total sum
    }
    return max_sum;       
   
}