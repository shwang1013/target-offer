/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
// 原树的深度由左右子树中深度较的深度加1，为原树的深度
// -----------　　　　不太懂,计算过程是怎样的，假设３层，怎么返回３？　　　------------//
/*如果一棵树只有一个结点，它的深度为1。如果根结点只有左子树而没有右子树，那么树的深度应该是其左子树的深度加1；
同样如果根结点只有右子树而没有左子树，那么树的深度应该是其右子树的深度加1。
如果既有右子树又有左子树呢？那该树的深度就是其左、右子树深度的较大值再加1。*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL) return 0;
        // the depth of left sub-tree
        int left = TreeDepth(pRoot->left);
        // the depth of right sub-tree
        int right = TreeDepth(pRoot->right);
        // depth is the binary tree
        return max(left, right) + 1;
    }
};
