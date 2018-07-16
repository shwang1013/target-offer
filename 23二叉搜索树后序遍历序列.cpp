class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        int sz = sequence.size(); // 得到序列的尺寸
        if(sz < 1)
            return false;
        int i;
        int root = sequence[sz-1];
        vector<int> lseq, rseq; 
        // 在定义两棵树，用来存储左子树和右子树，下次用来递归
        // 遍历，直接可以构造出一颗左子树，而且此时的i, 正好是左右子树的分界线
        for(i = 0; i < sz-1; i++)
        {
            if(sequence[i] < root)
                lseq.push_back(sequence[i]);
            else
                break;　//　当找到比root大的那个值时，应该是左右子树分界点，跳出来
        }
        // 从i开始，构建右子树,如果在这个过程中（分界点右侧）还能发现有比root小的，说明右子树有问题，返回false。
        //　如果没问题，左右子树就都构建ＯＫ了，递归
        for(i; i < sz-1; i++)
        {
            if(sequence[i] > root)
                rseq.push_back(sequence[i]);
            else
                return false;
        }
        bool left = true;
        if(!lseq.empty())
            left = VerifySquenceOfBST(lseq);
        bool right = true;
        if(!rseq.empty())
            right = VerifySquenceOfBST(rseq);
        return (left && right);
    }
};
