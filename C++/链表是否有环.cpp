#include<iostream>
#include<set>
using namespace std;
struct ListNode{
int val;
ListNode* next;
ListNode(int x):val(x),next(nullptr){}
};
class Solution{
public:
    ListNode *detectCycleBySet(ListNode* head) {
        ListNode* temp = head;
        set<ListNode*> mySet;
        while(temp != nullptr){
            auto it = mySet.find(temp);
            if(it == mySet.end()){
                mySet.emplace(temp);
                temp = temp->next;
            }else{
                break;
            }
        }
        if(temp == nullptr){
            return NULL;
        }
        else{
            return temp;
        }
    }
    ListNode *detectCycleByPoint(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr){
            fast = fast->next;
            if(fast == nullptr){
                return nullptr;
            }else{
                fast = fast->next;
                if(fast== nullptr) return nullptr; 
            }
            slow = slow->next;
            if(slow == fast){
                break;
            }
        }
        ListNode* p = head;
        while(p != slow){
            p = p->next;
            slow = slow->next;
        }
        return p;
    }
};
int main(){

}