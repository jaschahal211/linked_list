#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int x){
        data=x;
        next=NULL;
    }

};
class List
{
    private:
    Node * head;
    Node* tail;
    public:
    List()
    {
        head=NULL;
        tail=NULL;
    }
    void push_front(int val)
    {
        Node *newnode=new Node(val);
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
    }
    void push_back(int val)
    {
        Node *newnode=new Node(val);
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else{
            Node *q=head;
            q->next=newnode;
            q=newnode;
        }
    }
    void pop_front()
    {
        Node * r=head;
        if(head!=NULL)
        {
            head=r->next;
            r=head;
        }
    }
    void pop_back()
    {
        Node*s=head;
        Node *r;
        while(s->next!=NULL)
        {
            r=s;
            s=s->next;
        }
        r->next=NULL;
        tail=s;

    }
    void print()
    {
        Node *p=head;
        while(p!=NULL)
        {
            printf("%d\n",p->data);
            p=p->next;
        }
    }
    void insertpos(int val,int pos)
    {
        Node*temp=head;
        Node* newnode=new Node(val);
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;

    }
    void serachnode(int x){
        Node *m=head;
        int pos=0;
        while(m->data !=x)
        {
            pos++;
            m=m->next;
        }
        cout<<"position is:"<<pos;

    }


};
int main()
{
    List l;
    l.push_back(7);
    l.push_back(8);
    l.print();
    l.insertpos(9,2);
    l.print();
    l.serachnode(9);
    return 0;
}
