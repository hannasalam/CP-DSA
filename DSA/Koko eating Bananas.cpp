class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max=0,min = 1;
        for(int i:piles)
        {
            max= max>i?max:i;
        }
        cout<<"ans "<<max<<endl;
        int ans;
        cout<<min<<"\t"<<max<<"\t";
        while(min<max)
        {
            int mid = (max+min)/2;
            int hours = 0;
            int count = 0;
            for(auto x: piles)
            {
                hours += x/ mid + (x % mid != 0);
            }
            cout<<mid<<"\t"<<hours<<"\n";
            if(hours>h)
            {
                min = mid+1;
                
            }
            else
            {
                max = mid;
                
            }
        }
        return max;
        
    }
};