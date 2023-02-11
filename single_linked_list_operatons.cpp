//Harsh kumar srivastava (22MCA0310)
#include <iostream>
using namespace std;
class SLinkedList
{
class Node
{
public:
int val;
Node *next;
Node(int n)
{
val = n;
next = NULL;
}
};
Node *head;
int size;
public:
SLinkedList()
{
head = NULL;
size = 0;
}
void addAtFirst(int n)
{
size++;
Node *newN = new Node(n);
if (head == NULL)
{
head = newN;
head->next = newN;
return;
}
Node *temp = head;
while (temp->next != head)
{
temp = temp->next;
}
temp->next = newN;
newN->next = head;
head = newN;
}
void addAtEnd(int n)
{
size++;
Node *newN = new Node(n);
if (head == NULL)
{
head = newN;
head->next = newN;
return;
}
Node *temp = head;
while (temp->next != head)
{
temp = temp->next;
}
temp->next = newN;
newN->next = head;
}
void addAtPos(int n, int pos)
{
if (head == NULL)
{
Node *newN = new Node(n);
head = newN;
head->next = newN;
return;
}
if (pos == 0)
{
addAtFirst(n);
return;
}
if (pos == size)
{
addAtEnd(n);
return;
}
pos--;
Node *newN = new Node(n);
Node *temp = head;
while (pos > 0)
{
temp = temp->next;
pos--;
}
newN->next = temp->next;
temp->next = newN;
}
void deleteFirst()
{
if (head == NULL)
{
cout << "UnderFlow !!" << endl;
return;
}
if (size == 1)
{
head = NULL;
size--;
return;
}
size--;
Node *temp = head;
while (temp->next != head)
{
temp = temp->next;
}
temp->next = head->next;
head = head->next;
}
void deleteEnd()
{
if (head == NULL)
{
cout << "UnderFlow !!" << endl;
return;
}
if (size == 1)
{
head = NULL;
size--;
return;
}
size--;
Node *temp = head;
while (temp->next->next != head)
{
temp = temp->next;
}
temp->next = head;
}
void deleteData(int data)
{
if (head == NULL)
{
cout << "UnderFlow !!" << endl;
return;
}
if (data == head->val)
{
deleteFirst();
return;
}
size--;
Node *temp = head;
while (temp->next->val != data)
{
temp = temp->next;
}
temp->next = temp->next->next;
}
void display()
{
if (head == NULL)
return;
Node *temp = head;
while (temp->next != head)
{
cout << temp->val << " ";
temp = temp->next;
}
cout << temp->val << " ";
cout << endl;
}
};
main()
{
SLinkedList *list = new SLinkedList();
cout << "Linked List" << endl
<< endl;
cout << "Choose option" << endl;
cout << " 1. Add value at first" << endl;
cout << " 2. Add value at last" << endl;
cout << " 3. Add value at given position" << endl;
cout << " 4. Delete first" << endl;
cout << " 5. Delete last" << endl;
cout << " 6. Delete data" << endl;
cout << " 7. Display" << endl;
cout << endl;
int n;
do
{
cout << ">>";
cin >> n;
switch (n)
{
case 1:
{
cout << "Enter value in linked list : ";
int data;
cin >> data;
list->addAtFirst(data);
cout << endl;
break;
}
case 2:
{
cout << "Enter value in linked list : ";
int data;
cin >> data;
list->addAtEnd(data);
cout << endl;
break;
}
case 3:
{
cout << "Enter value : ";
int data, pos;
cin >> data;
cout << "Enter position :";
cin >> pos;
list->addAtPos(data, pos);
cout << endl;
break;
}
case 4:
{
list->deleteFirst();
cout << "Item deleted successfully !!";
cout << endl
<< endl;
break;
}
case 5:
{
list->deleteEnd();
cout << "Item deleted";
cout << endl
<< endl;
break;
}
case 6:
{
cout << "Enter value to delete : ";
int data;
cin >> data;
list->deleteData(data);
cout << "Item deleted ";
cout << endl
<< endl;
break;
}
case 7:
{
cout << " elements in linked List : ";
list->display();
cout << endl;
break;
}
}
} while (n > 0 && n < 8);
} 