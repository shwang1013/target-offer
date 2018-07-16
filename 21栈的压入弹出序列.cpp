class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool res;
        if(pushV.size() != 0 || popV.size() != 0) 
        {
            vector<int> stack;
            for(int i = 0,j = 0 ;i < pushV.size();i++)
            {
                stack.push_back(pushV[i]);
                while(j < popV.size() && stack.back() == popV[j])
                {
                    stack.pop_back();
                    j++;
                }      
            }
            return stack.empty();
        }
        return res;
        
    }
};

