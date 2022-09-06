class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        int prevNumber = n-1;
        int Xor = prevNumber&n;
        if(Xor) return false;
        return true;
    }
};