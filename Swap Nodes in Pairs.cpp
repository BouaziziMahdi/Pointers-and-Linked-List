#include <bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 class Solution {
public:
    ListNode* swapPairsRecurvive(ListNode*  head) {
         if(head==nullptr || head->next==nullptr)
             return head;
             head->next->next=swapPairsRecurvive(head->next->next);
             ListNode *temp=head->next;
             head->next=temp->next;
             temp->next=head;
             return temp;
         
     }
    ListNode* swapPairs(ListNode* head) {
        return swapPairsRecurvive(head);
    }
};