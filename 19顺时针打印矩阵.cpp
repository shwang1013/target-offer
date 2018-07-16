/*
    思想，用左上和右下的坐标定位出一次要旋转打印的数据，一次旋转打印结束后，往对角分别前进和后退一个单位。
    提交代码时，主要的问题出在没有控制好后两个for循环，需要加入条件判断，防止出现单行或者单列的情况。
 */
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;
         
        // 输入的二维数组非法，返回空的数组
        if (row == 0 || col == 0)  return res;         
        // 定义四个关键变量，表示左上和右下的打印范围
        int left = 0, top = 0, right = col - 1, bottom = row - 1;
        int i;
        while(left <= right && top<= bottom)
        {
            // 从左到右
            for(i = left; i <= right; i++) res.push_back(matrix[top][i]);
            //从上到下 -> 最上行和最下边行不能相等，否则直接重复打印了
            if(top < bottom)
            {
                for(i = top+1; i <= bottom; i++) res.push_back(matrix[i][right]);
            }
                
            //从右到左　-> 最右列最左列也不能重复
            if(top < bottom && left < right)
            {
                for(i = right-1; i>=left; i--) res.push_back(matrix[bottom][i]);
            }
            //从下到上　-> 最下行和最上行，不能重复
            if(top+1 < bottom && left < right)
            {
                for(i = bottom -1; i>=top+1;i--) res.push_back(matrix[i][left]);
            }
            left++;top++;right--;bottom--;
        }
        return res;
    }
};
