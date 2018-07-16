class Solution {
public:
    int jumpFloor(int number) {
        // 前一次要么是一级跳，要么是二级跳，所以 fN = fN-1 + fN-2
        // 和上一题一样，斐波那契数列，递归肯定不行，复杂度太大
        // －－－－－　用循环的方法　－－－－－－　//
        if (number==0)return 0;
        if (number==1)return 1;
        if (number==2) return 2;
        int lastJump=2;
        int lastlastJump=1;
        int thisJump;
        for(int i=3;i<=number;i++)
        {
            thisJump = lastJump + lastlastJump;
            lastlastJump = lastJump;
            lastJump = thisJump;
        }
        return thisJump;
    }
};
