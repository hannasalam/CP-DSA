vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<int> prime(N+1,1);
        vector<int>ans;
        for(int i=2;i<=N;i++)
        {
            if(prime[i]==1)
            {
                for(int j = 2*i;j<=N;j+=i)
                {
                    prime[j]=0;
                }
                ans.push_back(i);
            }
        }
        return ans;
    }