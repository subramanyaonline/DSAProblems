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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head ;
        if(k==0) return head; 
        ListNode* node = head ;
        ListNode* tail = nullptr;
        int size = 0 ;
        while(node!=nullptr){
            tail = node ;
            node = node->next ;
            size++;
        }
        k=k%size ;
        if(k==0) return head; 

        //i need to know the node where i should cut the list and attch at the first , that is size-k fromt the start. 
        node=head; int count = 0 ;
        while(node!=nullptr){
            count++;
            if(count < size-k)
                node=node->next ;
            else 
                break ;
        }
        //now node is pointing to the end of the new list . 
        ListNode* nextNode = node->next  ;
        node->next = nullptr ;
        tail->next = head ;
        head = nextNode ;
        return head ;
    }
};