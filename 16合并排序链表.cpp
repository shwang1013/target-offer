/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
/*　对链表排序　－－　递归   */
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2; // 如果pHead1空，直接返回pHead2 即可
       else if(pHead2==NULL)
            return pHead1;// 如果pHead2 空，直接返回pHead1 即可
         
         ListNode* newhead=NULL; // 建一个新的指针，用来存新生成的合并链表
        
        if(pHead1->val<pHead2->val)　//　先比较根节点，如果１小，新链表就把１的根节点加进去，在比较１的下一个结点和２的头结点；
        {
            newhead=pHead1;
            newhead->next=Merge(pHead1->next,pHead2);
        }
        else
        {
            newhead=pHead2;
          　newhead->next=Merge(pHead1,pHead2->next);
        }
       return newhead;
    }
};

