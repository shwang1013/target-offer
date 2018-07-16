class Solution {
public:
    void reOrderArray(vector<int> &array) {
        // 方法一：遍历，把奇数和偶数都推到数组里，再组合//
        /*int i=0;
        vector<int> arr1;
        vector<int> arr2;
        for(i;i<array.size();i++)
        {
            if(array[i]%2==1)
                arr1.push_back(array[i]);
            else
                arr2.push_back(array[i]);
        }
        for(i=0;i<arr2.size();i++)
            arr1.push_back(arr2[i]);
        array = arr1;*/
        //　方法二：还是遍历，直接新建一个，依次装进去就行//
        vector<int>res;
        int i=0;
        for(i=0;i<array.size();i++)
        {
            if(array[i]%2==1)
                res.push_back(array[i]);//遍历一遍，把所有的奇数追加进去
        }
        for(i=0;i<array.size();i++)
        {
            if(array[i]%2==0)
                res.push_back(array[i]);//　再遍历一次，把所有的偶数追加进去
        }
        array = res;
    }
};
