#include <iostream>

using namespace std;

struct ListNode{
    string val;
    ListNode *next;
    ListNode(string x) : val(x), next(NULL){}
};

void createLinkedList(ListNode *tail, int n){
    for(int i = 0; i < n; ++i){
        string temp;
        cin >> temp;
        ListNode *p = new ListNode(temp);
        tail->next = p;
        tail = p;
    }
}

ListNode* reverseList(ListNode* head){
    ListNode *pre = NULL;
    ListNode *next = NULL;
    while(head!=NULL){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

ListNode* reverseList2(ListNode* head, int k){
    ListNode *pre = NULL;
    ListNode *next = NULL;
    while(k--){
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

ListNode* reverseListGroup(ListNode *head, int n, int k){
    if(!head)   return head;
    if(k <= 1 || k > n)  return head;

    ListNode *p = head;
    ListNode *tmp = head;
    ListNode *result = NULL;
    ListNode *q = NULL;

    for(int i = 0; i <= n - k; i += k){
        tmp = head;
        for(int j = 0; j < k; ++j){
            head = head->next;
        }
        p = reverseList2(tmp, k);
        if(i == 0){
            result = p;
        }else{
            q->next = p;
        }
        q = tmp;
    }

    while(head){
        q->next = head;
        q = head;
        head = head->next;
    }

    return result;
}

bool isPalindrome(ListNode *head, int n){
    int i = n / 2;
    ListNode *fast = head;
    while(i-- > 0){
        fast = fast->next;
    }
    if(n % 2 == 1){
        fast = fast->next;
    }
    fast = reverseList(fast);

    while(fast != NULL){
        if(head->val != fast->val)
            return false;
        head = head->next;
        fast = fast->next;
    }
    return true;
}

void showLinkedList(ListNode *head){
    ListNode *p = head;

    cout<<p->val;
    p = p->next;
    while(p){
        cout << " " << p->val;
        p = p->next;
    }
    cout<<endl;
}

int main(){
    int n, k;
    while(cin >> n){
        string temp;
        cin >> temp;
        ListNode *head = new ListNode(temp);

        createLinkedList(head, n - 1);
        cin >> k;

        head = reverseListGroup(head, n, k);
        //tmp = head->next;
        //cout<<tmp->val <<"\t"<<head->next->val<<endl;

        //string result = isPalindrome(head, n)? "true" : "false";
        //cout << result << endl;

        showLinkedList(head);
    }

    return 0;
}
