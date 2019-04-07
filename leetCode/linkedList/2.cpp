struct ListNode {
  int val;
  ListNode *next;
  ListNode (int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    bool hasCycle(ListNode *head) {
      while(head != nullptr) {
        if(head == head -> next) return true;

        std::swap(head, head->next);
      }
      return false;
    }
};
