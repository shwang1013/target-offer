class Solution {
public:
    int Fibonacci(int n)
    {      
        //  --------------  方法一：递归 --------------- //
        //　递归会报错，因为会溢出，计算量太大
        // if(n<=1) return n;
        // else return Fibonacci(n-1)+Fibonacci(n-2);
        // 运行超时:您的程序未能在规定时间内运行结束，请检查是否循环有错或算法复杂度过大。
        
        //  --------------  方法二：循环 --------------- //
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        // 赋初值
        int fN_1=1; //　fN-1  和　fN-2
        int fN_２=0;
        int fN; //　fN－－－第Ｎ项的值
        for(int i=2;i<=n;i++)            
        {            
            fN=fN_1+fN_２;　//　
            fN_２=fN_１;
            fN_１=fN;
        }
        return fN;
    }
};
