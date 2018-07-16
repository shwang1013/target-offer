class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        // 方法二：两个指针，头和尾　//
        // 因为排序好了，如果头+尾>sum，那就尾左移，如果小于，那就头右移//
        // 积最小这个条件，f = a(s-a),画个二次函数曲线就知道了,a越小，积越小//
        int sz = array.size();
        vector<int> res;
        if(sz <= 1) return res;
        int start = 0;
        int end = sz-1;
        int curSum;
        while(start < end)
        {
            curSum = array[start] + array[end];
            if(curSum > sum)
                end--;
            else if (curSum < sum)
                start++;
            else
            {
                res.push_back(array[start]);
                res.push_back(array[end]);
                break; //为什么加　break，因为如果不跳出的话，下一步还会继续判断，所以找到时候应该跳出
            }
        }
        return res;
        // 方法一：　遍历：O(n2) ->>>　如果和为sum,得到一个数组，存储所有的和为m的两个数　//
        // s*(sum-1) 等价于二次函数，a越小，积越小，所以返回前两个就行
        //　但是复杂度太高，这种方法肯定不行，报错了，溢出　//
        /*int sz = array.size();
        vector<int> res;
        vector<int> result;
        for (int i = 0; i<sz; i++)
        {
            for(int j =i+1; j<sz; j++)
                if(array[i]+array[j]==sum)
                {
                    res.push_back(array[i]);
                    res.push_back(array[j]);
                }
        }
        result.push_back(res[0]);
        result.push_back(res[1]);
        return result;*/
        
        
    }
    
};

