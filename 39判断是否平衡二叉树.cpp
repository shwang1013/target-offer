class Solution {
public:
    /************　　方法二：如果改为从下往上遍历，如果子树是平衡二叉树，则返回子树的高度；
                    如果发现子树不是平衡二叉树，则直接停止遍历，这样至多只对每个结点访问一次。
                －－－－－－－－－－－－－－    看不懂　－－－－－－－－－－－－－－－
    *******/
    bool IsBalanced_Solution(TreeNode *root) 
    {
        return getDepth(root) != -1;
    }
    int getDepth(TreeNode *root) 
    {
        if (root == NULL) return 0;
        int left = getDepth(root->left); // 若果左子树不为０，继续往下
        if (left == -1) return -1;
        int right = getDepth(root->right);
        if (right == -1) return -1;
        // 返回，如果不是平衡二叉树，返回－１；　是平衡二叉树，返回深度
        return abs(left - right) > 1 ? -1 : 1 + max(left, right);
    }
};
    // ---- 方法一：分别求出左子树和右子树的深度　------//
    //--  调用上一题的函数：二叉树深度，求左右　-> 做差  --//
    /* 这种思路效率并不高，因为结点会被重复利用，在判断上层结点的时候，会多次重复遍历下层结点，增加了不必要的开销。*/
    /*bool IsBalanced_Solution(TreeNode* pRoot) 
    {
        if(pRoot == NULL) return true;
        int l = TreeDepth(pRoot->left);
        int r = TreeDepth(pRoot->right);
        if(l-r>1 ||l-r<-1) return false;
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
    }
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL) return 0;
        // the depth of left sub-tree
        int left = TreeDepth(pRoot->left);
        // the depth of right sub-tree
        int right = TreeDepth(pRoot->right);
        // depth is the binary tree
        return max(left, right) + 1;
    }*/

