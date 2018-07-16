
/*思路：
先序遍历的第一个元素为根节点，在中序遍历中找到这个根节点，从而可以将中序遍历分为左右两个部分，
左边部分为左子树的中序遍历，右边部分为右子树的中序遍历，进而也可以将先序遍历除第一个元素以外的剩余部分分为两个部分，
第一个部分为左子树的先序遍历，第二个部分为右子树的先序遍历。
由上述分析结果，可以递归调用构建函数，根据左子树、右子树的先序、中序遍历重建左、右子树。
*/
/* 先序遍历第一个位置肯定是根节点node，
中序遍历的根节点位置在中间p，在p左边的肯定是node的左子树的中序数组，p右边的肯定是node的右子树的中序数组
另一方面，先序遍历的第二个位置到p，也是node左子树的先序子数组，剩下p右边的就是node的右子树的先序子数组
把四个数组找出来，分左右递归调用即可
 */

/*
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
       int in_size = vin.size();//获得序列长度
       if (in_size == 0)
           return NULL;
       // 分别存储 左子树， 右子树
        vector<int> pre_left,pre_right,in_left,in_right;
        int val=pre[0];//先序遍历第一个位置 = 根节点node， 取其值
        // 新建一个树，传入结点值
        TreeNode* node = new TreeNode(val);//
        int p = 0;// 索引，用于存储中序序列根节点的位置
        for(p;p<in_size;++p)
        {
            if(vin[p] == val)
                break; // 找到即跳出for循环
        }
        for (int i =0 ; i < in_size; ++i)
        {
            if(i<p)
            {
                //建立中序序列的左子树和前序序列的左子树
                in_left.push_back(vin[i]); 
                pre_left.push_back(pre[i+1]); // 前序第一个为根节点，+1从下一个开始记录                
            }
            else if(i>p)
            {
                in_right.push_back(vin[i]);
                pre_right.push_back(pre[i]);
            }
        }
        // 取出前序和中序的左子树和右子树
        // 递归，再对其进行上面步骤：区分左右子树，直到叶节点！
        node->left = reConstructBinaryTree(pre_left, in_left);
        node->right = reConstructBinaryTree(pre_right, in_right);
        return node;
    }
};
