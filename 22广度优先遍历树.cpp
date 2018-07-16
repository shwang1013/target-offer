/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
/*
打印二叉树的有两种方式：深度优先遍历或者广度优先，这道题要求同层结点从左至右打印， 
说明需要进行广度优先遍历，为了达到这个目的，我们需要借助数据结构：队列.
不断将根结点、左孩子结点、友孩子结点push进入队列中，再放掉，同时进行打印操作；
*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) 
    {
        vector<int> result;  
        if (root == NULL) return result;  
        queue<TreeNode*> q;  
        q.push(root);  //　先把头结点放到队列（为什么要放呢？因为链表，知道头结点即可知道一切）
        while (!q.empty())  
        {  
            TreeNode* temp = q.front();  //　得到头结点，赋给temp
            q.pop();  //　删除头结点，这时候头结点是左孩子或者右孩子了
            result.push_back(temp->val);  //　打印头结点值
            if (temp->left)  
            {  
                q.push(temp->left);  //　头结点有左右孩子，直接入队，入队后，如果队列非空，这时候
            }  
              
            if (temp->right)  
            {  
                q.push(temp->right);  
            }  
        }  
        return result;  
    }
};
