class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2)
    {
        //　异或具有交换律 //
        /*一个数组中，所有的数字从头到尾异或，如果每个数字都出现两次，那结果必为０
        ->>> 2^3^2^3^4^4 = 2^2^3^3^4^4 = 0  交换律*/
        /* 一个数组中，所有的数字从头到尾异或，如果有不同数字出现，那结果就不为０
        >>> 2^3^2^3^4^4^7 = 2^2^3^3^4^4^7 =7*/
        
        if(data.size()<2)
            return ;
        int size=data.size();
        int temp=data[0];
        for(int i=1;i<size;i++)
            temp=temp^data[i];　// 对数组中的每一个数字异或
        if(temp==0)
            return ;　// 如果异或结果为０，说明没有数字只出现一次
        
        int index=0;
        while((temp&1)==0) // 找到１所在的位置，(temp&1)!=0，则找到１的位置　＝　index
        {
            temp=temp>>1;
            ++index;
        }
        *num1=*num2=0;
        for(int i=0;i<size;i++) // 这个函数的功能，根据倒数第index位是不是１，分为两组数，然后在用num分别异或，更新的Ｎｕｍ就是只出现一次的数
        {
            if(IsBit(data[i],index))　//　如果倒数第index位是１，则不断往后异或，在这里就能找到倒数第index位是１情况下的只出现一次的数
                *num1^=data[i];
            else  //　如果倒数第index位是0，则不断往后异或，在这里就能找到倒数第index位是１情况下的只出现一次的数
                *num2^=data[i];
        }
    }
    bool IsBit(int num,int index) // 这个函数的功能是看倒数第index位是不是１
    {
        num=num>>index;
        return (num&1);
    }
};
