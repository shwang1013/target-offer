/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
/*　方法２：不用构建栈，直接用reverse函数 -> 翻转数组，reverse 函数的作用是 反转元素的顺序。*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) 
    {
        vector<int> result;//用数组存储链表所有节点的值
        struct ListNode* pNode = head;
        while(pNode!=NULL)
        {
            result.push_back(pNode->val);
            pNode = pNode->next;
        }
        reverse(result.begin(),result.end());//ｃ++ ，翻转函数,对数组实现翻转
        return result;
    }
};
/* 方法一：建立一个栈:实现后进先出　*/
/*
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) 
    {
        vector<int> result;//存储结果并返回
        stack<struct ListNode*> nodes;//建立一个栈，用来实现后进先出
        struct ListNode* pNode = head; //建立头指针,从头指针开始索引
         while (pNode != NULL){            //链表的所有节点全部入栈
            nodes.push(pNode);
            pNode = pNode->next;
        }

        while (!nodes.empty()){       //出栈：后进先出
            pNode = nodes.top();
            result.push_back(pNode->val);
            nodes.pop();
        }
        return result;
    }
};
*/


