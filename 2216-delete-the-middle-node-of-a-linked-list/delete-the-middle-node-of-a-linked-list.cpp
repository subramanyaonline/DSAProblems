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
    ListNode* deleteMiddle(ListNode* head) {

        if(head->next==nullptr) return nullptr ;

        int size = 0 ; 
        ListNode* node = head; 

        while(node != nullptr){
            size++; 
            node = node->next ; 
        }

        int index = 1 ; 
        ListNode* prev = head ;
        node = head->next ;
         
        while(node!=nullptr){
            if(index==size/2){
                prev->next = node->next ; 
                delete node ;
                return head ;
            }
            index++; 
            node = node->next ;
            prev = prev->next ;
        }

        return head ;
    }
};