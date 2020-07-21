#include <iostream>

using namespace std;
/*
This file contains the linked List implementation using classes
We are using the arrow operator '->' instead of '(*).'
For eg -
struct node* p = &a ; // a is some node
Then we have to ways to access 'a'
 (*p).value; // Using *p we get the access to the a and ' . ' operator gets the value
 brackets are used because ' . ' has higher priority than '*'
 therefore we use a shorter format to clean up code as -
 p->value; // This is same as (*p).value
*/

class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
class LinkedList
{

    Node* head;

    public:
    LinkedList()
    {
        head=NULL;
    }
    void addNodeAtEnd(int data)
    {
        Node* newNode=new Node(data);   //CPP way of creating dynamic memory
                                        //When dynamic memory allocation is used then it is your duty to free this memory when not in use
        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            Node *temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newNode;
        }
    }
    void addNodeAtBegin(int data)
    {
        Node* newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
        }
        else
        {
            newNode->next=head;
            head=newNode;
        }

    }
    void deleteNode(int data)   //Function to delete a node with given data
    {
        Node* temp=head;
        Node* deletedNode;
        if(head==NULL)
        {
            cout<<"List is already empty"<<endl;
        }
        else
        {
            while(temp!=NULL)
            {
                if(temp->next->data==data)
                {
                    deletedNode=temp->next;
                    temp->next=temp->next->next;
                    delete deletedNode;
                    break;
                }
                temp=temp->next;
            }
        }
    }
    void deleteList()   //function to delete the entire list
    {
        Node* current=head;
        Node* next=head;

        while(current!=NULL)
        {
            next=current->next;
            delete current;
            current=next;
        }
        head=NULL;
    }
    void printList()
    {
        if(head==NULL)
        {
            cout<<"Empty List"<<endl;
        }
        else
        {
            Node *temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
    }

    void reverseList()
    {
        Node* temp1=head;
        Node* temp2=head;
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
        }
        else if(head->next==NULL)
        {
            //do nothing
        }
        else if(head->next->next==NULL)
        {
            temp1=head;
            head=head->next;
            head->next=temp1;
            temp1->next=NULL;
        }
        else
        {

            temp1=head;
            temp2=head->next;
            head=head->next->next;
            temp1->next=NULL;
            while(head!=NULL)
            {
                temp2->next=temp1;
                temp1=temp2;
                temp2=head;
                head=head->next;
            }
            temp2->next=temp1;
            head=temp2;
        }
    }
    void reverseList2()     //Smaller implementation of reverse list found on geeksforgeeks
    {
        Node* current=head;
        Node* previous=NULL;
        Node* next=NULL;
        while(current!=NULL)
        {
            next=current->next;
            current->next=previous;
            previous=current;
            current=next;
        }
        head=previous;
    }


};
int main()
{
    LinkedList list;
    list.printList();
    list.addNodeAtEnd(1);
    list.addNodeAtEnd(2);
    list.addNodeAtEnd(3);
    list.addNodeAtEnd(4);
    list.deleteNode(3);
    list.printList();
    list.reverseList2();
    list.printList();
    list.deleteList();
    list.printList();
    return 0;
}
