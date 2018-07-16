class Solution {
public:
    int rectCover(int number) {
        // 这和青蛙跳一样，前一次要么是横着覆盖，要么是竖着覆盖
        // 假设是２＊ｎ:　横着盖，则还剩　2＊（n-2），竖着盖，还剩　２×（n-1）.
        // 因此，fN = fn-1 + fn-2,还等价于是斐波那契数列
        if(number==0) return 0;
        if(number==1) return 1;
        if(number==2) return 2;
        int last_vertical =1;
        int last_transverse = 2;
        int thismoment;
        for(int i=3;i<=number;i++)
        {
             thismoment = last_vertical + last_transverse;
             last_vertical = last_transverse;
             last_transverse = thismoment;
        }
        return thismoment;

    }
};
