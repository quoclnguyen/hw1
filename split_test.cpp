#include "split.h"
#include <cstddef>
int main(){
  Node *a = new Node(1,NULL);
  Node *b = new Node(2, a);
  Node *c = new Node(3,b);
  Node *d = new Node(4,c);
  Node *e = new Node(5,d);
  Node *f = new Node(6,e);
  Node* odds = NULL;
  Node* evens = NULL;
  split(f, odds, evens);
  while(odds != NULL){
    Node* temp = odds;
    odds = odds->next;
    delete temp;
  }
  while(evens != NULL){
    Node* temp = evens;
    evens = evens->next;
    delete temp;
  }
  delete odds;
  delete evens;

  return 0;
}