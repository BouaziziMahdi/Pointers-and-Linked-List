
#include <iostream>
using namespace std;
  struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pointeurA = headA;
        ListNode *pointeurB = headB;

        while (pointeurA != pointeurB) {
            if (pointeurA != nullptr) {
                pointeurA = pointeurA->next;
            } else {
                pointeurA = headB;
            }
            if (pointeurB != nullptr) {
                pointeurB = pointeurB->next;
            } else {
                pointeurB = headA;
            }
        }
        return pointeurA; 
    }
};
