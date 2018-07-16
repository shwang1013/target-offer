class Solution {
public:
    // 没咋懂，二刷再考虑考虑　
    //思路：（１）数组排序，（２）统计０的个数　（３）统计排序后的数组中相邻数字之间的空缺总数
    bool IsContinuous( vector<int> numbers ) 
    {
        if( numbers.size() ==0)
            return false;
        sort(numbers.begin(),numbers.end());  //先排序
        int zero = 0, i = 0;
        for(; i < numbers.size() && numbers[i] == 0; i++)
        {
            zero ++;  //统计0的个数
        }
        for(; i < numbers.size() - 1; i++) //　遍历看看是否有对子，没有的话继续匹配,此时的i已经是最后一个０后面的数了
        {
            if(numbers[i] == numbers[i+1]) //有对子，则返回false
                return false;
            if(numbers[i] + 1 + zero >= numbers[i+1])
            {  //可以继续匹配
                zero -= numbers[i+1] - numbers[i] - 1;
            }
            else
                return false;
        }
        if(i == numbers.size() -1)
            return true;
        else
            return false;
    }
};
