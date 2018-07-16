class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) 
    {
        // －－－－－－－－－－－　方法一：　直接用Ｃ++ 排序函数　－－－－－－－－－　//
        //sort(rotateArray.begin(),rotateArray.end());　//C++排序函数         
        //return rotateArray[0];        
        //　－－－－－－－－－－　方法二：　比较第i个和第i+１个数的大小，如果大于，说明找到了转折点　－－－－－－//
        /*
        int length = rotateArray.size();
        if (length == 0)
            return 0;
        for(int i =0; i<length; i++)
        {
            if(rotateArray[i]>rotateArray[i+1])
                return rotateArray[i+1];
        }
        return rotateArray[0];
        */
        //　－－－－－－－－－－　方法三：　二分法　－－－－－－－－//
        int length = rotateArray.size();
        if (length == 0)
            return 0;        
        int left = 0;
        int right = length - 1;
        int middle = -1;
        while (rotateArray[left]>=rotateArray[right]) 
        {
            //相邻，说明right已经指向了小数组的头，left指向了小数组的尾部
            if(right-left==1)　
            {
                middle = right;　//中间指针　指向right，即小数组的头，最终返回
                break;
            }
            //　如果（right - left）　！＝　１
            middle = (right ＋ left) / 2;　//　ｍｉｄｄｌｅ先指向中间：二分法
            if (rotateArray[middle] >= rotateArray[left])　//　如果　midVal 大于leftVal，说明 midVal 处在大值数组中
                left = middle; //这时候，把left放到中间，再来
            if (rotateArray[middle] <= rotateArray[right]) //　如果　midVal 小于rightVal，说明 midVal 处在小值数组中
                right = middle;
        }
        return rotateArray[middle];
    }
};
