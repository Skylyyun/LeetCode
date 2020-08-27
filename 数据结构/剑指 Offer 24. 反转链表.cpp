/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//双指针解法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = nullptr,  *pre = head, *temp = nullptr;
        while(pre != nullptr) {
            temp = pre->next;
            pre->next = cur;
            
            //同时移动cur和pre
            cur = pre;
            pre = temp;
        }
        return cur;
    }
};

//递归法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //出口：考虑一开始就只有一个节点的情况
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *ret = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ret;
    }
};

//妖魔化的双指针
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode *temp = nullptr, *cur = head;
        while(head->next != nullptr) {
            temp = head->next->next;
            head->next->next = cur;
            cur = head->next;
            head->next = temp;
        }
        return cur;
    }
};