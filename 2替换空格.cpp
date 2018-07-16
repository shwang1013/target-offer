class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (str == NULL || length<=0)
            return ;
        int blankNum=0;
        int len = 0; // 
        for(int i=0;str[i]!='\0';i++)
        {
            len++; //字符串总长度
            if(str[i]==' ')
                blankNum++; //空格数目总数
        }
        int newTotalLength = len + blankNum*2; //替换后的总长度
        if(newTotalLength > length)
            return ;        
        //开始替换
        for(int i=len;i>=0;i--)//从后往前遍历
        {
            if(str[i]!=' ')
                str[newTotalLength--] = str[i];
            else
            {
                str[newTotalLength--]='0';
                str[newTotalLength--]='2';
                str[newTotalLength--]='%';
            }
             
        }
	}
};
