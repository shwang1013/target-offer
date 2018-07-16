
/*思路一：循环方法

15 * 矩阵是有序的，从左下角来看，向上数字递减，向右数字递增，
16 * 因此从左下角开始查找，当要查找数字比左下角数字大时。右移 ->等价于剔除行/列
17 * 要查找数字比左下角数字小时，上移 > 等价于剔除行/列*/
/*class Solution {
public:
    bool Find(int target, vector<vector<int> > array) 
    {
        int raw = array.size();
        int col = array[0].size();
        int i = raw - 1 ;
        int j = 0;
        while(i>=0 && j<col)
        {
            if(target == array[i][j])
                return true;
            else if (target>array[i][j])
                j++;
            else
                i--;
        }
        return false;
    }
};*/



//思路二：因为每一行都是递增的，所以可以对每一行都用二分法
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) 
    {
        int rowCount = array.size();
        int colCount = array[0].size();
        for(int i=0; i<rowCount; i++)
        {
            int low=0;
            int high = colCount-1;
            while(low<=high)
            {
                int mid = (low+high)/2;
                if(target > array[i][mid])
                    low = mid+1;
                else if(target < array[i][mid])
                    high = mid-1;
                else
                    return true;
            }
        }
        return false;



