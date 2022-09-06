class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int ones= 0;
        while(ans){
            ones+= ans%2;
            ans = ans/2;
        }
        return ones;
    }
};