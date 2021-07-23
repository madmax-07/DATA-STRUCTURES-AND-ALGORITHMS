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
  ListNode *merge(ListNode *h1, ListNode *h2)
{
    if (h1 == NULL)
        return h2;
    if (h2 == NULL)
        return h1;
    ListNode *c ;
    if (h1->val <= h2->val)
    {
        c = h1;
        c->next = merge(h1->next, h2);
    }
    else if (h1->val > h2->val)
    {
        c = h2;
        c->next = merge(h1, h2->next);
    }
    return c;
}
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    if (lists.size() == 0)
        return NULL;
    ListNode *result = NULL;
    for (int i = 0; i < lists.size(); i++)
    {

        result = merge(result, lists[i]);
    }
    return result;
}
};
