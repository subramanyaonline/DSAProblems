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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head->next==nullptr) return head ;
        //finding the size of the list 
        ListNode* node1 = head ;
        int size = 0 ;
        while(node1!=nullptr){
            node1=node1->next ;
            size++;
        }
        node1 = head ;
        ListNode* node2 = head ;
        int idx1 = k ; int count1 = 1 ;int count2 = 1;
        int idx2 = size+1-k ;

        while(count1<idx1){
            node1 = node1->next ;
            count1++;
        }

        while(count2<idx2){
            node2 = node2->next ;
            count2++;
        }
        swap(node1->val,node2->val);
        return head ;
    }
};