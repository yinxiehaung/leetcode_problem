/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *right = head->next;
    while(right != NULL){
        right = right->next;
        if(right != NULL){
            right = right->next;
        }
        head = head->next;
    }
    return head;
}
