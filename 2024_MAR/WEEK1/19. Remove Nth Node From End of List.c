/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 1 2 3 4 5
 ^   ^
 */
int link_size(struct ListNode *first){
    int res = 0;
    while(first){
        first = first->next;
        res++;
    }
    return res;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int list_size = link_size(head), address = list_size - n - 1, i = 0;
    if(address == -1){
        return head->next;
    }
    struct ListNode *curr = head;
    while(i < address){
        i++;
        curr = curr->next;
    }
    curr->next = curr->next->next;
    return head;
}
