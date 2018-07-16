/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
    // 如果两棵树的根节点相同，则调用这个函数，判断两棵树是否相同
    //　所以这个函数，需要不断判断左右结点是否相同，直到１空（那说明没找到）或者２空（说明找完了，符合条件）
    bool doesEqual(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        // 如果有一个结点没对上，返回false
        if(pRoot1->val!=pRoot2->val) return false;
        // 如果　tree２　遍历完了，说明都能对应的上，返回true
        if(pRoot2==NULL) return true;
        // 如果　tree2还没遍历完，tree１　就遍历完了，这时候返回false；
        if(pRoot1==NULL) return false;        
        // 上一步：如果根节点相同，就分别去子节点里面匹配
        //　判断左右结点，如果都相同，才能返回true 
        return doesEqual(pRoot1->left, pRoot2->left) && doesEqual(pRoot1->right, pRoot2->right);
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;
        // 先定义result为false,因为如果两棵树有一颗为空的话，直接返回false
        if(pRoot1!=NULL && pRoot2!=NULL)//都非空，才能作比较
        {
            //如果根节点相等，就以根节点为起点，看看树１是否包含树２
            if(pRoot1->val == pRoot2->val)
            {
                result = doesEqual(pRoot1,pRoot2);
            }
            //　如果根节点压根不相等，或者，这个根节点相等但不满足包含，那再从左结点开工，看看是否包含Ｔree2
            if(!result)
            {
                result = HasSubtree(pRoot1->left, pRoot2);
            }
            //　如果根节点压根不相等，或者，这个根节点相等但不满足包含，再从右结点开工，看看是否包含Ｔree2
            if(!result)
            {
                result = HasSubtree(pRoot1->right, pRoot2);
            }
        }
        return result;
    }
};
