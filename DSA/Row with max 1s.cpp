O(m+n) Solution:
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int min=INT_MAX, pos = -1;
	    int i=0,j=m-1;
	    while(i<n&&j>=0)
	    {
	        
	        if(arr[i][j]==1)
	        {
	            pos = i;
	            j--;
	        }
	        else 
	            i++;
	    }
	    return pos;
	}

};

O(nlogm) solution: 

class Solution{
    public:
        int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
            // code here
            int min=INT_MAX, pos = -1;
            for(int i=0;i<n;i++)
            {
                int zcount = upper_bound(arr[i].begin(),arr[i].end(),0)-arr[i].begin();
                //cout<<i<<"\t"<<zcount<<"\n";
                if(zcount<min && zcount!=m)
                {
                    //cout<<zcount;
                    min = zcount;
                    pos = i;
                }
            }
            return pos;
        }

};

};