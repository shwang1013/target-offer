class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k)
    {
        // 方法二：有序数组，当然是二分查找//
		/*二分查找 找到第一个K 和 最后一个K 二者位置相减*/
        // 利用二分查找法，找到第一个k和最后一个k，做差，就是k出现的次数
        int start = 0;       
        int end = data.size()-1;        
        int firstK = getFirstK(data,start,end,k);
        int lastK = getLastK(data,start,end,k);
        int numbersOfK = 0;
        if(end == -1) return 0;
        if(firstK>-1 && lastK>-1)
            numbersOfK = lastK - firstK + 1;
        return numbersOfK;
    }
    int  getFirstK(vector<int>data,int start,int end,int k)
    {
        if(start>end) return -1;
        int mid;
        while(start<=end)
        {
            mid = (start+end)/2;
            if(data[mid] == k)
            {
                if(mid == start || data[mid-1]!=k)// 如果k已经在第一个，或者k不在第一个但是它的前一个不等于k
                    return mid; //得到了第一个k
                else // k不在第一个，而且前一个不是k,　说明还没找到第一个k，这时候应该把前一个作为最后，继续往前找
                    end = mid -1;
            }
            else// 如果没找到k，那就按照大于或者小于，继续二分查找。
            {
                if(data[mid] > k)
                     end = mid-1;
                else
                    start = mid+1;
            }
        }
        return -1; // // k在数组中不存在的情况

    }
    int getLastK(vector<int>data,int start,int end,int k)
    {
        if(start > end)
            return -1;
         int mid;
         while(start<=end)
         {
            mid = start+(end-start)/2;
            if(data[mid]==k)
            {
                if((mid == end) || (data[mid+1] != k))
                    return mid;
                else
                    start = mid +1;
            }
            else
            {
                if(data[mid]>k)
                    end = mid-1;
                else
                    start = mid+1;
            }
         }
         return -1;
    }

        //　方法一：遍历，傻子都会　//
        /*
        int sz = data.size();
        int num=0;
        for(int i =0;i<sz;i++)
        {
            if(data[i]==k)
                num++;
        }
        return num;
        */
};
