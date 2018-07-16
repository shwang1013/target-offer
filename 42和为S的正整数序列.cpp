class Solution {
public:
    // 不懂，先过，哎　//
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        if(sum < 3) //判断边界条件，sum不能小于3.如果满足边界条件，则进行如下操作。否则返回空result；
            return result;
        vector<int> tmpVec;
        int begin = 1;
        int end = 2;
        int curSum = begin + end; //设置两个变量begin和end，分别为数列的开始数值和终结数值。初始值begin = 1；end = 2；curSum = 3；
        while(begin <= sum / 2)
        {
            while(curSum > sum)
            {
                curSum -= begin;
                begin++;
            }
            if(curSum == sum && end - begin >= 1)
            {
                //tmpVec.clear();
                for(int i = begin; i<= end; i++)
                {
                    tmpVec.push_back(i);
                }
                result.push_back(tmpVec);
            }
            end++;
            curSum += end;
        }
 
        return result;
    }
};
