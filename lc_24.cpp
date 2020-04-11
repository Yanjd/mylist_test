 /*
 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 */

#include<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

 ListNode* swapPairs(ListNode* head) {
        ListNode* dum=new ListNode(-1);
        ListNode *cur=dum;
        ListNode* p;
        ListNode* q;
        if(!head) return nullptr;
        if(!head->next) return head;
        p=head;
        q=head->next;
        while(p&&q){
            p->next=q->next;
            q->next=p;
            cur->next=q;
            cur=cur->next->next;
            p=p->next?p->next:nullptr;
            q=p?p->next:nullptr;
        }
        return dum->next;
    }