/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
/* 先前序遍历这棵树的每个结点，如果遍历到的结点有子结点，就交换它的两个子节点，
当交换完所有的非叶子结点的左右子结点之后，就得到了树的镜像 */
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        // tem,递归
        if(pRoot==NULL)
            return ;
        TreeNode *tem;
        tem = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tem;
        //while(pRoot->left&&pRoot->right)
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
