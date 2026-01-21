#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*pre;
    Node(int x)
    {
        data=x;
        next=NULL;
        pre=NULL;
    }

};
class DoubleLinked{
private:
Node *head;
Node* tail;
public:
DoubleLinked()
{
    head=NULL;
    tail=NULL;

}

void push_front(int val)
{
    Node *newnode=new Node(val);
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        newnode->next=head;
        head->pre=newnode;
        head=newnode;
    }
}
void push_back(int value)
{
    Node * newnode=new Node(value);
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        Node *s=head;
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=newnode;
    newnode->pre=s;
}
}
void pop_front()
{
    Node *s=head;
    head=s->next;
    head->pre=NULL;
    delete s;
}
void pop_back()
{
    Node *s=head;
    Node*r;
    while(s->next!=NULL)
    {
        r=s;
        s=s->next;
    }
    r->next=NULL;
    delete s;
}
void print()
{
    Node *s=head;
    while(s!=NULL)
    {
        cout<<s->data<<endl;
        s=s->next;

    }

}
};
int main()
{
    DoubleLinked dll;
    dll.push_front(7);
    dll.push_front(8);
    dll.pop_back();
    dll.print();
    return 0;
}