class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        // 方法一：从第一个元素开始，遍历，求和 --     o(ｎ)
        /*int i,j;
        int max = array[0];
        for(i=0;i<array.size();i++) // 从第一个数出发求和，到从倒数第二个数出发求和
        {
            int curSum = 0;
            for(j = i;j<array.size(); j++)　
            {
                curSum += array[j];　//当前和，不断地加后面的数
                if(curSum > max)　//直到，比max大，才更新
                    max = curSum;
            }
        }
        return max;*/
        //　方法２：　没他妈的明白　------- // 
        if (array.size()==0) {
             return 0;
         }
         int curSum=0;
         int greatestSum=array[0];
         for (int i = 0; i < array.size(); i++) {
             if (curSum<=0) // 如果当前和小于等于0，就重新设置当前和, 因为你不设置的话，用一个负数加下一个数，只会更小，所以应该从下一个数重新加起
             {
                 curSum=array[i]; //记录当前最大值
             }
             else // 如果当前和大于0，累加当前和
             {
                 curSum+=array[i]; //当array[i]为正数时，加上之前的最大值并更新最大值。
             }
             if (curSum>greatestSum) 
             {
                 greatestSum=curSum; // 更新记录到的最在的子数组和
             }
         }
         return greatestSum;
        // 方法３：　动态规划　-----------//
    }
};

