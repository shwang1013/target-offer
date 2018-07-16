class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        // 方法：转换成字符串　-----　比较字符串大小即可//
        int sz = numbers.size();
        if(sz==0) return "";
        // 根据字符串大小排序，按这个顺序升序排序好，组合好就是最小的数字
        // 比如[1,32,9,18,82,91,903]   ->     [1,18,32,82,9,903,91]
        sort(numbers.begin(),numbers.end(),cmp);
        string res;
        for(int i=0;i<sz;i++)
        {
            res+=to_string(numbers[i]);
        }
        return res;
    }
    static bool cmp(int a, int b) //　cmp　函数，在sort中，就是定义一种规定'小于'的关系
    {
        /*比较函数是一个自己定义的函数，返回值是bool型，它规定了什么样的关系才是“小于”．
        简单来说，有一个数组int a[100]，要对从a[0]到a[99]的元素进行排序，只要写sort(a,a+100)就行了，默认的排序方式是升序。
        比较函数是一个自己定义的函数，返回值是bool型，它规定了什么样的关系才是“小于”。
        想把刚才的整数数组按降序排列，可以先定义一个比较函数cmp*/
        //to_string()函数返回字符串形式
        string　A = to_string(a) + to_string(b);
        string　B = to_string(b) + to_string(a);
        return A<B;
    }
};
