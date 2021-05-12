#include<bits/stdc++.h>
using namespace std;

class Node{
        public:
                int data;
                Node* next;
};

// for printing 
void print(Node* n)
{
        while(n!=NULL)
        {
                cout<<n->data<<" ";
                n=n->next;
        }
        cout<<endl;
}

// insert at the start
void push(Node** head,int data)
{
        Node* new_node = new Node();
        new_node->data=data;
        new_node->next=(*head);
        (*head) = new_node;
}

// insert after at the pos
void insertAfter(Node** head,int data,int pos)
{
        Node* new_node = new Node();
        new_node->data=data;
        Node* temp = (*head);
        for(int i=1;i<pos;i++)
        {
                if(temp->next==NULL)
                {
                        cout<<"pos doesn't exist"<<endl;
                        break;
                }
		temp=temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
}

//insert at the end
void atEnd(Node** head,int data)
{
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = NULL;
        if(*head == NULL)
        {
                *head = new_node;
                return;
        }
        Node* temp=*head;
        while(temp->next!= NULL)
                temp=temp->next;
        temp->next = new_node;
        return;
}

// delete at the beginning
void deleteAtBeg(Node** head)
{
        Node* temp=*head;
        *head = (*head)->next;
        free(temp);
}

// delete at the end
void deleteAtEnd(Node** head)
{
        Node* temp=*head;
        Node* prev;
        while(temp->next!=NULL)
        {
                prev = temp;
                temp = temp->next;
        }
        prev->next=NULL;
        free(temp);
}

//delete the specific key
void deleteKey(Node** head,int key)
{
        Node* temp = *head;
        Node* prev = NULL;
        if(temp!= NULL && temp->data == key)
        {
                *head= temp->next;
                delete temp;
                return;
        }
        else
        {
                while(temp!= NULL && temp->data != key)
                {
                        prev = temp;
                        temp = temp->next;
                }
                if( temp==NULL)
                        return ;
                prev->next = temp->next;
                delete temp;
        }
}

// delete node at specific position
void deleteAtpos(Node** head,int pos)
{
	if((*head) == NULL)
	return;
	
	Node* temp = *head;
	if(pos == 0)
	{
		*head = temp->next;
		free(temp)
		return;
	}
	for(int i=1;temp!=NULL && i<=pos;i++)
	{
		temp = temp->next;
	}
	if(temp == NULL || temp->next == NULL)
		return;

	Node* next = temp->next->next;
	free(temp->next);
	temp->next = next;
}

// length of the list
int length(Node* head)
{
	int count = 0;
	Node* current = head;
	while(current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

