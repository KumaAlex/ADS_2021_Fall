#include <bits/stdc++.h>
using namespace std;
 
struct Node {
  int value;
  int ans;
  Node *prev;
  Node(int x) {
    value = x;
    prev = NULL;
    ans = -1;
  }
};
 
struct Stack {
  private:
    Node *head;
    int sz;

  public:
    
    Stack() {
        sz = 0;
        head = NULL;
    }

    int top() { 
      return head->value; 
    }
   
    void pop() {
      head = head->prev;
      sz--;
    }
 
    int size() { 
      return sz;
    }
 
    bool empty() { 
      return sz == 0; 
    }
 
    int push(int x) {
        sz++;
        Node * node = new Node(x);
        if (head == NULL) {
            head = node;
            return head->ans;
        }
        node->prev = head;
        head = node;
        Node * cur = head;
        while (cur->prev != NULL) {
            cur = cur->prev;
            if (cur->value <= head->value) {
                head->ans = cur->value;
                return head->ans;
            }
        }
        return node->ans;
    }
 
};
 
int main() {
  int n;
  Stack st;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    cout << st.push(x) << " ";
  }
  return 0;
}
