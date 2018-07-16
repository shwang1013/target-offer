class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
    {
        /* 知识点：　红黑树 + 堆 + 快排*/
        // 方法一：直观法：排序，遍历，存前k个，返回 --Ｏ(n) //
        /*
        int sz = input.size();
        vector<int> res;
        if(sz == 0 || k>sz) return res;
        sort(input.begin(),input.end());
        for(int i = 0; i<k; i++)
            res.push_back(input[i]);
        return res;*/
        
        //　方法二：　最大堆　by headWritting//
        /*vector<int> res;
        int sz = input.size();
        if(sz==0 || k>sz)
        {
            return res;
        }
        heapSort(input,sz);
        for(int i = 0; i<k; i++)
            res.push_back(input[i]);
        return res;
    }
    void swap(vector<int> input,int i,int j)
    {
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
    }
    void heapSort(vector<int> input,int sz)
    {
        int i;
        for(i = sz/2; i>=0; i--)
        {
            heapAdjust(input,i,sz);
        }
        for(i = sz-1; i>=1;i--)
        {
            swap(input,0,i);
            heapAdjust(input,0,i-1);
        }
    }
    void heapAdjust(vector<int> input,int i,int sz)
    {
        int temp = input[i];
        for(int j=((i=0)?(2*i+1):(2*i));j<=sz;j=0?(2*j+1):(2*j))
        {
            if(j<sz && input[j]<input[j+1])
                j++;
            if(temp>=input[j])
                break;
            //else if (temp<input[j])
            input[i]=input[j];
            i=j;
        }
        input[i] = temp;*/
        
        
        // ---方法３：用c++库中的 STL->heap() ----//
        //->先建立一个容量为k的容器，make_heap //
        //->然后往进插：如果小于容器里最大值的话，就插进来：先pop一下，然后插进来，再push_heap（）一下
        int len=input.size();
        if(len<=0||k>len||k<=0) return vector<int>();
        vector<int> res(input.begin(),input.begin()+k);
        //for (int i = 0; i < k; i++) res.push_back(input[i]);
        //建堆
        make_heap(res.begin(),res.end());
         
        for(int i=k;i<len;i++)
        {
            if(input[i]<res[0])
            {
                //先pop,然后在容器中删除
                pop_heap(res.begin(),res.end());
                res.pop_back();
                //先在容器中加入，再push
                res.push_back(input[i]);
                push_heap(res.begin(),res.end()); // 重构最大堆
            }
        }
        //使其从小到大输出
        sort_heap(res.begin(),res.end());
        return res;
         
    }
};
