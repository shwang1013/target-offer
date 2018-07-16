/*
应用一个辅助栈，压的时候，如果A栈的压入比B栈压入大，B栈不压.
小于等于，AB栈同时压入，出栈，如果，AB栈顶元素不等，A出，B不出。
用一个栈data保存数据，用另外一个栈min保存依次入栈最小的数
比如，data中依次入栈，5,  4,  3, 8, 10, 11, 12, 1
则min依次入栈，5,  4,  3，no,no, no, no, 1
no代表此次不如栈
每次入栈的时候，如果入栈的元素比min中的栈顶元素小或等于则入栈，否则不如栈。
*/
class Solution {
public:
    stack<int> stack1,stack2;
    // stack1用作辅助栈，stack2 用作最小值栈
    // 最基本的思路，每次入栈都排序，但是这样不能保证最后出栈的元素是最先进栈的，不符合先进后出，所以这时候不是栈结构了  //
    void push(int value) {
        stack1.push(value);　//　辅助栈，全push进去
        if(stack2.empty())
            stack2.push(value);　//　刚开始stack2为空，肯定得先入一个值
        else if(value<=stack2.top())　//最小值栈，如果val　比最小值栈的栈顶小，那就进栈
            stack2.push(value);
        }
    void pop() {
        if(stack1.top()==stack2.top())
            stack2.pop();
        stack1.pop();
    }
    int top() {
        return stack1.top(); 
    }
    int min() {
        return stack2.top();
    }    
};
