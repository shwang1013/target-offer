/* ---------------------   全面考虑    --------------------- */
//　底数为０，指数为负数或０，无意义
//　指数为负数，正数要区分对待，其他没问题
class Solution {
public:
    double Power(double base, int exponent) {
        float res=1;
        if(base==0 & exponent<=0)
            return 0;
        if(exponent<0)
        {
            res = 1;
            for(int i=1;i<=-exponent;i++)
                res *= base; 
                res=1/res;
            //res= pow(base,exponent); // pow，c++中的指数函数
            // res=1/res;
            return res;
        }
        if(exponent>=0)
        {
            res = 1;
            //for(int i=1;i<=exponent;i++)
              //  res *= base;
            res= pow(base,exponent); // pow，c++中的指数函数
            return res;
        }
    }
};
