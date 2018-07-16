/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
    {
        // 　方法一：遍历两次，第一次得到总的节点数，第二次找到倒数第k个结点
        /*ListNode *ptr = pListHead; //遍历指针,遍历完指针指向最后一个结点
        ListNode *ptr1 = pListHead; //返回指针，需要一个新的指针指向头指针，进行第二次遍历
        if (pListHead == NULL || k == 0)//考虑全面
            return NULL;
        int n =1;//已经指向第一个结点
        while (ptr->next != NULL)　//遍历得到总的结点数
        {
            ptr=ptr->next;
            n++;
        }
        if(n<k)//否则倒数第Ｋ个，成了负数了
            return NULL;
        for (int i = 0; i < n - k; ++i)
            ptr1 = ptr1->next;　//这样可以找到第n-k个结点
        return ptr1;*/
        
        // 　－－－－－　方法一：遍历一次，定义两个指针，第一个指针先走k-1步，第二个指针按兵不动，一比二就快乐k-1步　－－－－//
        //　　这样，一走到end，二就到了　end-(k-1), 也就是倒数第k个结点
        ListNode *ptr1 = pListHead; // 指针１
        ListNode *ptr2 = pListHead;　//指针２
        if (pListHead == NULL || k == 0)//考虑全面
            return NULL;
        int i;
        for(i=0;i<k-1;i++)　//　p1　走k-1步
        {
            if(ptr1->next) // 这个条件等价于方法一种的，if(n<k)return　NULL;　因为当i<k-1时,如果发生ptr1->next==null，说明k太大了，超出了链表的总结点个数
                ptr1 = ptr1->next;
            else 
                return NULL;
        }
        while(ptr1->next)　//　p1走到end，　p2开始走
        {
            ptr1=ptr1->next;            
            ptr2=ptr2->next;
        }
        return ptr2;
    }
};
