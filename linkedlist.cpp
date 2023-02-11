//Harsh kumar srivastava (22MCA0310)
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Node
{
public:
int data;
Node *next;
};
void printoutList(Node *n)
{
cout << " Linked List data are: " << endl;
;
while (n != NULL)
{
cout << n->data << " " << endl;
n = n->next;
}
}
int main()
{
Node *head = NULL;
Node *second = NULL;
Node *third = NULL;
// allocating 3 nodes in the heap
head = new Node();
second = new Node();
third = new Node();
head->data = 1;
head->next = second;
second->data = 2;
second->next = third;
third->data = 3;
third->next = NULL;
printoutList(head);
return 0;
} 