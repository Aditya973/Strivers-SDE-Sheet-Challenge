/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(!head || !head->next){
          return head;
     }
     int n = 1;
     Node* last = head;
     while(last->next != nullptr){
          n++;
          last = last->next;
     }
     k = k%n;
     if(k == 0 || k == n){
          return head;
     }
     Node* newHead;
     Node* temp = head;
     for(int i = 1;i<n-k;i++){
          temp = temp->next;
     }
     newHead = temp->next;
     temp->next = nullptr;
     last->next = head;
     return newHead;
}