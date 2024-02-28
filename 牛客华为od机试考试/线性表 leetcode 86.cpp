//
// Created by Nino Neumann on 2024/2/22.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        bubble(head,x,head);
        return head;
    }
    void bubble(ListNode* root,int x,ListNode* head){
        if(root==nullptr) return;
        bubble(root->next,x,head);
        for(ListNode* i = head;i!=root;i = i->next)
            if(i->val>=x && i->next->val<x) swap(i->val,i->next->val);
    }
};