#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(nullptr){}
};
class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* current = head;
        ListNode* nextpos = nullptr;
        ListNode* prepos = nullptr;
        while(current != nullptr){
            nextpos = current->next;
            current->next = prepos;
            prepos = current;
            current = nextpos;
        }
        return prepos;
    }
    void print(ListNode* head){
        ListNode* current = head;
        while(current != nullptr){
            cout<<current->val<<" ";
            current = current->next;
        }
    }
};
int main(){
    int value;
    bool flag = true;
    ListNode* head;
    ListNode* temp = nullptr;
    while(~scanf("%d",&value)){
        if(flag == true){
            head = new ListNode(value);
            temp = head;
            flag = false;
            continue;
        }
        ListNode* p = new ListNode(value);
        temp->next = p;
        temp = temp->next;
    }
    Solution* s = new Solution();
    head = s->reverseList(head);
    s->print(head);
}