class Solution {
public:
    // 方法：先整体翻转，再根据空格，把单个单词再翻转一次；也可以先局部翻转，再整体翻转
    string ReverseSentence(string str) 
    {
        auto size = str.size();
        if(size == 0) return "";
        int mark=0;
        str += ' ';// 字符串末尾得，再加一个空格，作为最后一个单词翻转的标志
        ReverseWord(str, 0, size-1);//先整体翻转
        //　下面进行局部翻转
        for(int i = 0; i < size+1; ++i)
        {
            if(str[i] == ' ')
            {
                ReverseWord(str, mark, i-1);　// 碰到空格的话，翻转整个单词
                mark = i+1;
            }
        }
        str = str.substr(0, size);　//　
        //ReverseWord(str, 0, size-1);// 也可以，后整体翻转
        return str;
    }
    // 字符串翻转函数，起始字符下标：l，
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
