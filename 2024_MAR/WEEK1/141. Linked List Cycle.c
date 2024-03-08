/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *left = head;
    struct ListNode *right = left;
    while(right != NULL){
        right = right->next;
        if(right != NULL){
            right=right->next;
        }
        left = left->next;
        if(left == right){
            break;
        }
    }
    return right == NULL?false:true;
}
