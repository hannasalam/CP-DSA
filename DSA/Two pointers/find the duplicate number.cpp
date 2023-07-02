class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        int slow = nums[0];
        int fast = nums[0];
        int n = nums.size();
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);
        slow = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

//what is happening is that, first the both of them enters the loop and loop is found
//after that the fast is inside the loop and slow is outside. When slow == fast which means slow is inside the loop and same as fast

//The intuition behind this step is that the distance between the meeting point of the slow and fast pointers and 
//the starting point of the cycle is equal to the distance between the first element of the vector and the duplicate
// number. By moving both pointers at the same pace, they will eventually meet at the starting point of the cycle, 
// which represents the duplicate number.