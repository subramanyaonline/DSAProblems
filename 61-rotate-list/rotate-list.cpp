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
        if(!head || !head->next) return head ; 
         
        int size = 0 ; 
        ListNode* tail ; 
        ListNode* node = head ; 
        while(node){
            size++; 
            tail = node ; 
            node = node->next ; 
        }

        k = k%size ;  
        if(k==0) return head ;
        int jump = size-k ; 
        node = head ; 
        ListNode* prev ; 
        for(int i=1;i<=jump;i++){
            prev = node ; 
            node = node->next ; 
        }

        prev->next = nullptr ; 
        tail->next = head ; 
        head = node ; 

        return head ; 
    }
};