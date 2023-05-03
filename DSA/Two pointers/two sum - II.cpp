vector<int> twoSum(vector<int>& numbers, int target) {
        int first = 0,last = numbers.size()-1;
        while(first<last){
            int sum = numbers[first]+numbers[last];
            if(sum==target) return {first+1, last+1};
            if(sum<target) first++;
            else last--;
        }
        return {};
}