#include <bits/stdc++.h>

using namespace std;

// 指针实现链表
struct Node {
  int data;
  Node *prev, *next;
};

Node *head, *tail;

void initialize() {
  head = new Node();
  tail = new Node();
  head->next = tail;
  tail->prev = head;
}

void insert(Node* p, int value) {
  Node* q = new Node();
  q->data = value;
  p->next->prev = q;
  q->next = p->next;
  p->next = q;
  q->prev = p;
}

void remove(Node* p) {
  p->prev->next = p->next;
  p->next->prev = p->prev;
  delete p;
}

void recycle() {
  while(head != tail) {
    head = head->next;
    delete head->prev;
  }
  delete tail;
}


// 数组实现链表

const int SIZE = 100;

struct Node {
  int value;
  int prev, next;
} node[SIZE];

int head, tail, tot;
void initialize() {
  head = 1;
  tail = 2;
  tot = 2;
  node[head].next = tail;
  node[tail].prev = head;
}

void insert(int p, int value) {
  int q = ++tot;
  node[q].value = value;
  node[node[p].next].prev = q;
  node[q].next = node[p].next;
  node[p].next = q;
  node[q].prev = p;
}

void remove(int p) {
  node[node[p].next].prev = node[p].prev;
  node[node[p].prev].next = node[p].next;
}

void clear() {
  memset(node, 0, sizeof(node));
  head = tail = tot = 0;
}
