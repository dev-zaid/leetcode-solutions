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
    ListNode* middleNode(ListNode* head) {
        //count number of elements
        int count = 0;
        ListNode* curr = head;

        while(curr != NULL){
            count++;
            curr = curr->next;
        }

        curr = head;
        int middle = count/2;

        while(middle > 0){
            curr=curr->next;
            middle--;
        }

        return curr;
    }
};