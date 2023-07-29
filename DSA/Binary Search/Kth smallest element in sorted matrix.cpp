class Solution {
public:
    bool check(vector<vector<int>>& matrix,int mid, int k){
        int j = matrix.size()-1;
        int count = 0;
        for(int i=0;i<matrix.size();i++){
            while(j>=0 and matrix[i][j]>mid) j--;
            count+= (j+1);
        }
        if(count>=k) return true;
        return false;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // [ 1,5, 9],
        // [10,11,13],
        // [12,13,15]
        //bottom traingle can be greater
        //fn? 
        // find if k or less
        int n = matrix.size();
        long long low = matrix[0][0]-1, high = matrix[n-1][n-1];
        while(low+1<high){
            int mid = low+(high-low)/2;
            if(check(matrix,mid,k))
                high = mid;
            else
                low = mid;
        }
        return high;
        
    }
};