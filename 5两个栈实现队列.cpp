class Solution
{
public:
    void push(int node) 
    {
        stack1.push(node);
    }

    int pop()
    {
        int pop_val;
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                pop_val = stack1.top();
                stack2.push(pop_val);
                stack1.pop();
            }
        }

        pop_val = stack2.top();
        stack2.pop();
        return pop_val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
