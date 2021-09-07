class Solution {
public:
    int kConcatenationMaxSum(vector<int>& v, int k) {
        long n = v.size();
        if(k==1)
		{
			int sum = 0, maxi = INT_MIN;
			for(int i=0;i<n;i++)
			{
				sum +=v[i];
				maxi = max(maxi,sum);
				if(sum<0)
					sum=0;
			}
			return maxi;
		}
		else
		{
			long sum;
			sum = accumulate(v.begin(),v.end(),0);
			long ksum = 0,y,maxi=INT_MIN;
			for(int i=0;i<2*n;i++)
			{
				y = i%n;
				ksum +=v[y];
				//cout<<ksum<<"kj ";
				maxi = max(maxi,ksum);
				if(ksum<0)
					ksum=0;
			}
            if(maxi<=0) return 0;
			//cout<<ksum<<"kk "<<sum<<"ss \n";
			if(sum<=0)
			{
				return maxi;
			}
			else
			{
				maxi= (maxi+(k-2)*sum)%1000000007;
				return maxi;
			}
	
        
    }
    }
};