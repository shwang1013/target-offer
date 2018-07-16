class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) 
    {
        //　-----      方法一---------------------//
        //排序sort()，如果超过一半，排序后中间值肯定是那个数。
        //排序，遍历，看看中间值是否>sz/2，是的话返回中间值，否则返回０
        // 但是时间复杂度O(NlogN),高，不行
        /*vector<int> nums;
        int sz = numbers.size();
        if(sz == 0) 
            return 0;
        if(sz ==1)
            return numbers[0];
        sort(numbers.begin(),numbers.end());　
        int n=0;
        for(int i=0;i<=sz-1;i++)
        {
            if(numbers[i] == numbers[sz/2+1])
                n++;
        }
        if(n > sz/2)
            return numbers[sz/2];
        else 
            return 0;*/
        
        // ---- -- 　　方法２：　-------//
        /*
        如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
        遍历两次：一得到数字，二得到次数。
        遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；若次数为0，则保存下一个数字，并将次数置为1。遍历结束后，所保存的数字即为所求。
        然后再判断它是否符合条件即可。*/
        
        if(numbers.empty()) return 0;
        // 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
        int result = numbers[0];
        int times = 1; // 次数
        // 得到这个数字　result
        for(int i=1;i<numbers.size();++i)
        {
            if(times == 0)
            {
                // 更新result的值为当前元素，并置次数为1
                result = numbers[i];
                times = 1;
            }
            else if(numbers[i] == result)
            {
                ++times; // 相同则加1
            }
            else
            {
                --times; // 不同则减1               
            }
        }
        // 判断result是否符合条件，即出现次数大于数组长度的一半
        times = 0;
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i] == result) ++times;
        }
        return (times > numbers.size()/2) ? result : 0;
        
        
       // --------- 方法三: 基于partition函数-------------//
        // 还是中位数：成熟的Ｏ(n)算法 -> 得到数组中任意第k大的数字 (快排的启发)　
        //　求中位数，最快的就是快快速排序算法
        /*
        随机选一个数字，调整数组中数字的顺序，使得比选中的数字小的数字都排在它左边，大的在右
        如果选中的下标正好 = n/2,　这时候就是中位数，如果　>n/2,　那中位数就在左，反之在右。
        这是个递归问题。
        */
        //　PS: 这个解法，需要交换数组顺序，因此可以问问面试官，是不是可以修改数组　//
    }
};
