class Solution {
public:
    //　可以看成倒着往回跳，或者看成上一次归来是怎么来的
    // 总之青蛙跳就是看前一次有多少种来源，加起来就行
    int jumpFloorII(int number) {
        if(number == 0) return 0;
        if(number == 1) return 1;
        else
            return 2*jumpFloorII(number-1);
    }
};
