/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        if(head1 == nullptr && head2 == nullptr){
            return nullptr;
        }
        if(head1 == nullptr&&head2!=nullptr){
            return head2;
        }
        if(head1 != nullptr && head2 == nullptr){
            return head1;
        }
        ListNode* prev = nullptr;
        ListNode* current = head1;
        ListNode* future = nullptr;
        while(current != nullptr){
            future = current->next;
            current->next = prev;
            prev = current;
            current = future;
        }
        ListNode* add1 = prev;

        prev = nullptr;
        current = head2;
        future = nullptr;
        while(current != nullptr){
            future = current->next;
            current->next = prev;
            prev = current;
            current = future;
        }
        ListNode* add2 = prev;
        //链表相加
        ListNode* head = nullptr;
        
        ListNode* tail = nullptr;
        int cos = 0;
        ListNode* pause = nullptr;
        bool flag = true;
        while(1){
            if(add1 == nullptr){
                pause = add2;
                break;
            }
            if(add2 == nullptr){
                pause = add1;
                break;
            }
            ListNode* newp = nullptr;
            int te = add1->val + add2->val + cos;
            cos = te / 10;
            te = te % 10;
            newp = new ListNode(te);
            if(flag){
                head = newp;
                tail = newp;
                flag = false;
            }else{
                tail->next = newp;
                tail = newp; 
            }
            add1 = add1->next;
            add2 = add2->next;
        }
        flag = true;
        while(pause != nullptr){
            ListNode* newp = nullptr;
            int te = pause->val + cos;
            cos = te/10;
            te = te % 10;
            newp = new ListNode(te);
            tail->next = newp;
            tail = newp;
            pause = pause->next;
        }
        if(cos == 1){
            ListNode* newp = nullptr;
            newp = new ListNode(1);
            tail->next = newp;
            tail = tail->next;
        }
        prev = nullptr;
        current = head;
        future = nullptr;
        while(current != nullptr){
            future = current->next;
            current->next = prev;
            prev = current;
            current = future;
        }
        return prev;
    }
};