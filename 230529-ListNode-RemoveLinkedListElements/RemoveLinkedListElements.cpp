/**
题意：删除链表中等于给定值 val 的所有节点。

示例 1： 输入：head = [1,2,6,3,4,5,6], val = 6 输出：[1,2,3,4,5]

示例 2： 输入：head = [], val = 1 输出：[]

示例 3： 输入：head = [7,7,7,7], val = 7 输出：[]

代码链接：
https://leetcode.cn/problems/remove-linked-list-elements/
 * 
 */
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr) {}
};

class Solution {
    public:
    // 解法一：如果头结点属于删除节点，利用原来的链表进行操作
    ListNode* removeElements1 (ListNode* head, int val) {
        while (head != nullptr && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        ListNode* cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next =  cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }    
        }
        return head;
    }

    // 解法二：如果头结点属于删除节点，利用虚拟头节点进行操作
    ListNode* removeElements2 (ListNode* head, int val) {
        return head;
    }


};
