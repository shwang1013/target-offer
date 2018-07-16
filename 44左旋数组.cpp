class Solution {
public:
        string LeftRotateString(string str, int n) 
        {
            // 方法４：最重要的方法　－－－　字符串翻转　－－－//
            /* 可以翻转前n 个，再翻转后面的，最后整体翻转，共３次，实现左旋*/
            int len = str.length();
            if(len == 0) return "";
            ReverseWord (str, 0, n-1);
            ReverseWord (str, n, len-1);
            ReverseWord (str, 0, len-1);
            return str;
        }
        void ReverseWord (string &str, int l, int r)
        {
            while(l < r)
            {
                swap(str[l], str[r]);　// swap() 交换两个字符串的内容 
                ++l;
                --r;
            }
        }
};
        
        
        
        
        
        // 方法三：巧解法 --//
        // str写两次，从n开始取len位，不就是反转的字符串吗　//
        // 如：　fasdfe,n=3  ->>   fasdfefasdfe     ->>>>----  从str[3]往后取６位就ＯＫ了　->>>　dfefas。
        /*int len = str.length();
        if(len == 0) return "";
        str+=str;
        //n = n % len;
        str += str;
        return str.substr(n, len); // 从n开始，往后取len位*/
        
        // 方法一：遍历，先把前n位存到一个字符串，再把n+1到最后存到第二个字符串
        // 然后把两个字符串合并即可,时间复杂度为O(N)
        /*
        int sz = str.size();
        string res1;
        string res2;
        if(n>sz || n<0) return res1;
        for(int i = 0;i<n;i++)
            res1+=str[i];
        for(int j=n;j<sz;j++)
            res2+=str[j];
        return res2+res1;*/
        
        // 方法二：运用字符串操作函数　－－substr　和　erase
        // erase() //删除字符**s.erase(13);从索引13开始往后全删; s.erase(7,5);从索引7开始往后删5个 
        // substr() //返回某个子字符串s.substr();//返回s的全部内容s.substr(11);//从索引11往后的子串//s.substr(5,6);//从索引5开始6个字符 
        /*if(n<0) return NULL;
        if(n==0) return str;
        string strTemp="";
        strTemp=str.substr(0,n);//返回从索引０开始n个字符
        str.erase(0,n);//把str从索引0开始往后删n个,只剩下最后几个
        str+=strTemp;// str = 最后几个　＋　前n个
        return str;*/

