class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        int leftShift = 1<<k;
        int Xor = n&leftShift;
        int rightShift = Xor>>k;
        int lastBit = rightShift&1;
        return lastBit;
    }
};