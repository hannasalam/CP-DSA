    int maxSumTwoNoOverlap(vector<int>& a, int firstLen, int secondLen) {
        int n = a.size();
        vector<int> left(n), right(n);
        int sum = 0, ans = 0;
        for(int i=0;i<n;i++)
        {
            if(i<firstLen)
            {
                sum+= a[i];
                left[i] = sum;
            }
            else
            {
                sum+= a[i] - a[i-firstLen];
                left[i] = max(left[i-1],sum);
            }
        }
        sum = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(i+secondLen>=n)
            {
                sum+= a[i];
                right[i] = sum;
            }
            else
            {
                sum+= a[i]-a[i+secondLen];
                right[i] = max(sum, right[i+1]);
            }
        }
        for(int i=firstLen-1;i<n-secondLen;i++)
        {
            ans = max(ans, left[i]+right[i+1]);
        }
        sum=0;
        for(int i=0;i<n;i++)
        {
            if(i<secondLen)
            {
                sum+= a[i];
                left[i] = sum;
            }
            else
            {
                sum+= a[i] - a[i-secondLen];
                left[i] = max(left[i-1],sum);
            }
        }
        sum = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(i+firstLen>=n)
            {
                sum+= a[i];
                right[i] = sum;
            }
            else
            {
                sum+= a[i]-a[i+firstLen];
                right[i] = max(sum, right[i+1]);
            }
        }
        for(int i=secondLen-1;i<n-firstLen;i++)
        {
            ans = max(ans, left[i]+right[i+1]);
        }
        return ans;
    }