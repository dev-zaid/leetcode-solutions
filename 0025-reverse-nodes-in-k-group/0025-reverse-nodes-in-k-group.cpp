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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //check if k nodes exist
        int cnt = 0;
        ListNode* curr = head;
        while(cnt<k){
            if(curr==NULL){
                return head;
            }
            curr=curr->next;
            cnt++;
        }
        //recursively reverse the next group
        ListNode* prevNode = reverseKGroup(curr, k); 

        //reverse the current group
        cnt=0;
        curr = head;

        while(cnt<k){
            ListNode* next = curr->next;
            curr->next = prevNode;
            prevNode=curr;
            curr = next;
            cnt++;
        }

        return prevNode;
        
    }
};