# include <iostream>
# include <algorithm>
# include <cassert>

using namespace std;

struct Node {
    int val;
    Node *next;

    Node() {
        val = 0;
        next = NULL;
    }

};


int findMaxSum(int n, Node* head) {
    if(head == NULL){
        return 0;
    }
    int maxSum = head->val;
    int curSum = head->val;
    Node * cur = head->next;

    while(cur != NULL){
        curSum = max(cur->val, curSum + cur->val);
        maxSum = max(maxSum,curSum);

        cur = cur->next;
    }
    return maxSum;
}

int main() {
    int n;
    cin >> n;

    Node *head, *tail;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        Node *cur = new Node();
        cur -> val = x;
//        cout<<x<<" ";

        if (i == 1) {
            head = tail = cur;
        } else {
            tail -> next = cur;
            tail = cur;
        }
    }

    cout << findMaxSum(n, head) << "\n";
    return 0;
}