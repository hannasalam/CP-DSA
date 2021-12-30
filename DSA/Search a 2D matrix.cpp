class Solution {
public:
    bool binarySearch(vector<int> matrix, int s,int target)
    {
        int mid;
        int start = 0, end = s;
        while(start<=end)
        {
            mid = (start+end)/2;
            if(target==matrix[mid])
                return true;
            else if(target<matrix[mid])
                end = mid-1;
            else
                start = mid+1;
        }
        return false;        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = matrix[0].size()-1;
        if(target==matrix[0][0])
            return true;
        if(matrix.size()==1)
        {
            return binarySearch(matrix[0], s, target);
        }
        for(int i=1;i<matrix.size();i++)
        {
            if(target==matrix[i][0])
            {
                cout<<"ivde";
                return true;
            }
            else if(target<matrix[i][0])
            {
                return binarySearch(matrix[i-1], s, target);
            }
        }
        return binarySearch(matrix[matrix.size()-1], s, target);
    }
};