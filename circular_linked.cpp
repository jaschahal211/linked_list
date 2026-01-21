#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
class CircularLinkedList{
    private:
    Node* head;
    public:
    CircularLinkedList()
    {
        head=NULL;
    }
    void insert_head(int x)
    {
        Node * newnode=new Node(x);
        if(head==NULL)
        {
            head=newnode;
            newnode->next=newnode;
        }
        else{
            Node *r=head;
            while(r->next!=head)
            {
                r=r->next;
            }
            r->next=newnode;
            newnode->next=head;
            head=newnode;
        }
    }
    void insert_tail(int x)
    {
        Node * newnode=new Node(x);
        if(head==NULL)
        {
            head=newnode;
            newnode->next=newnode;
        }
        else{
            Node *r =head;
            while(r->next!=head)
            {
                r=r->next;
            }
            r->next=newnode;
            newnode->next=head;
        }

    }
    void delete_head()
    {
        Node *r=head,*s=head;
        while(r->next!=head)
        {
            r=r->next;
        }
        r->next=s->next;
        head=s->next;
        delete s;
    }
    void delete_end()
    {
        Node *r,*s=head;
        s=s->next;
        while(s->next!=head)
        {
            r=s;
            s=s->next;
        }
        r->next=head;
        delete s;
    }
    void print()
    {
        Node *s=head->next;
        cout<<head->data<<endl;
        while(s!=head)
        {
        cout<<s->data<<endl;
        s=s->next;
        }
    }
};
int main()
{
    CircularLinkedList c;
    c.insert_head(8);
    c.insert_head(9);
    c.insert_tail(10);
    c.delete_end();
    c.print();
    return 0;
}