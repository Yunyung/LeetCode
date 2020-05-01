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

/* slower version */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        int num1, num2;
        ListNode dummyHead = ListNode(0, NULL);
        ListNode* cur = &dummyHead;
        
        while (l1 && l2){
            num1 = l1->val;
            num2 = l2->val;
            int min;
            if (num1 < num2){
                min = num1;
                l1 = l1->next;
            }
            else{
                min = num2;
                l2 = l2->next;
            }
            ListNode* newNode = new ListNode(min, NULL);
            cur->next = newNode;
            cur = cur->next;
            
        }
        
        while (l1 != NULL){
            ListNode* newNode = new ListNode(l1->val, NULL);
            cur->next = newNode;
            cur = cur->next;
            l1 = l1->next;
        }
        
        while (l2 != NULL){
            ListNode* newNode = new ListNode(l2->val, NULL);
            cur->next = newNode;
            cur = cur->next;
            l2 = l2->next;
            
        }
        
        ListNode* p = dummyHead.next;
        while(p){
            cout << p->val;
            p = p->next;
        }
        return dummyHead.next;
        
    }
};

/* faster version */
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode dummyHead(0, NULL);
        ListNode* cur = &dummyHead;
        
        while (l1 && l2){
            if (l1->val < l2->val){
                cur->next = l1; 
                l1 = l1->next;
            }
            else {
                cur->next = l2; 
                l2 = l2->next;
            }
            
            cur = cur->next;
        }
        
        cur->next = (l1) ? l1 : l2;
        
        return dummyHead.next;
        
    }
};