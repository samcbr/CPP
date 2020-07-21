#include <iostream>
#define MAX 1000
using namespace std;

class StackArray
{
    int a[MAX];
    int top;
    public:
        StackArray()
        {
            top=-1;
        }
        bool push(int data)
        {
            top++;
            if(top>MAX-1)
            {
                cout<<"Stack overflow"<<endl;
                return false;
            }
            a[top]=data;
            return true;
        }
        int pop()
        {
            if(top<0)
            {
                cout<<"Stack underflow"<<endl;
                return 0;
            }
            int x=a[top];
            cout<<a[top--]<<" popped"<<endl;
            return x;
        }
        int peek()
        {
            if(top==-1)
            {
                cout<<"Stack is empty"<<endl;
                return 0;cout<<"Stack is empty"<<endl;
            }
            else
                cout<<"Top element is "<<a[top]<<endl;
            return a[top];
        }

};
class Node
{

    public:
        int data;
        Node* next;
        Node(int data)
        {
            this->data=data;
            next=NULL;
        }

};
class StackList
{
    Node* top;
    public:
    StackList()
    {
        top=NULL;
    }

    void push(int data)
    {
        Node* newNode=new Node(data);
        if(top==NULL)
        {
            top=newNode;
        }
        else
        {
            newNode->next=top;
            top=newNode;
        }
    }

    void peek()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            cout<<top->data<<endl;
        }
    }

    void pop()
    {
        if(top==NULL)
        {
            cout<<"Stack underflow"<<endl;
        }
        else
        {
            Node* temp=top;
            top=top->next;
            cout<<temp->data<<" popped"<<endl;
            delete temp;
        }
    }
};
int main()
{
    cout << "Hello world!" << endl;
    StackList stackList;
    stackList.peek();
    stackList.pop();
    stackList.push(1);
    stackList.push(2);
    stackList.push(3);
    stackList.push(4);
    stackList.push(5);
    stackList.peek();
    stackList.pop();
    stackList.pop();
    stackList.pop();
    stackList.pop();
    stackList.pop();
    stackList.pop();
    return 0;
}
