	int main() {
        int x,n;
        cin>>x>>n;
        int ans=1;
        while(n)
        {
            //x = x*x;
            if(n&1==1)
            {
                ans= (ans * x)%10000007;
            }
            n = n>>1;
            x = x*x;
        }
        cout<<ans%10000007<<"\n";
        return 0;
	}