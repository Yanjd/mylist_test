/*
    合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp{  
       bool operator()(ListNode *a,ListNode *b){
          return a->val > b->val;
       }
    //优先级队列进行排序
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pri_queue;
        // 建立大小为k的小根堆
        for(auto elem : lists){
            if(elem) pri_queue.push(elem);
        }
        // 可以使用哑节点/哨兵节点
        ListNode dummy(-1);
        ListNode* p = &dummy;
        // 开始出队
        while(!pri_queue.empty()){
            ListNode* top = pri_queue.top(); pri_queue.pop();
            p->next = top; p = top;
            if(top->next) pri_queue.push(top->next);
        }
        return dummy.next;  
    }


ListNode* merge(ListNode* p1, ListNode* p2){
        if(!p1) return p2;
        if(!p2) return p1;
        if(p1->val <= p2->val){
            p1->next = merge(p1->next, p2);
            return p1;
        }else{
            p2->next = merge(p1, p2->next);
            return p2;
        }
    }
    //分治法-两两合并
     ListNode* mergeKLists2(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* head = lists[0];
        for(int i = 1; i<lists.size(); ++i){
            if(lists[i]) head = merge(head, lists[i]);
        }
        return head;  
    }


    ListNode* merge(vector<ListNode*>& lists, int start, int end){
        if(start == end) return lists[start];
        int mid = (start + end) / 2;
        ListNode* l1 = merge(lists, start, mid);
        ListNode* l2 = merge(lists, mid+1, end);
        return merge(l1, l2);
    }
    //分治法-归并
    ListNode* mergeKLists3(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        return merge(lists, 0, lists.size()-1);
    }
