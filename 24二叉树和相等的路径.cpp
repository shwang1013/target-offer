/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
// 相当于栈的特性，后进先出
class Solution {
public:
    vector<int> path;
    vector<vector<int>> buffer;
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {    
        if(root == NULL)
            return buffer;
        path.push_back(root->val); // 路径先入根节点，下一步：看根节点的左右孩子是否为空
        if((expectNumber-root->val) == 0 && root->left == NULL && root->left == NULL)
            buffer.push_back(path);
        if (root->left != NULL)
            FindPath(root->left,expectNumber - root->val);
        if (root->right != NULL)
            FindPath(root->right,expectNumber - root->val);
        if(path.size()!=0)
            //path = 
            path.pop_back();　//　分析一下可以发现：其实这个函数的path里，一直都只有一个元素
        return buffer;
    }
};

