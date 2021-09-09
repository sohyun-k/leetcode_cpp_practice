#pragma once
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* tmp_l1 = l1;
        ListNode* tmp_l2 = l2;
        vector<ListNode*> result;
        bool up = false;
        bool endl1 = false, endl2 = false;
        while (endl1 == false || endl2 == false || up == true) {
            ListNode* tmp_result;
            int tmp_num;
            if (endl1) tmp_l1->val = 0;
            if (endl2) tmp_l2->val = 0;
            if (up) {
                tmp_num = tmp_l1->val + tmp_l2->val + 1;
            }
            else {
                tmp_num = tmp_l1->val + tmp_l2->val;
            }
            int num = tmp_num % 10;
            if (tmp_num >= 10) {
                up = true;
            }
            else {
                up = false;
            }
            if (result.size() == 0) {
                tmp_result = new ListNode(num);
            }
            else {
                result.at(result.size() - 1)->next = new ListNode(num);
                tmp_result = result.at(result.size() - 1)->next;
            }
            result.push_back(tmp_result);
            if (tmp_l1->next != nullptr) {
                tmp_l1 = tmp_l1->next;
            }
            else {
                endl1 = true;
            }
            if (tmp_l2->next != nullptr) {
                tmp_l2 = tmp_l2->next;
            }
            else {
                endl2 = true;
            }
        }
        return result.at(0);
    }
};