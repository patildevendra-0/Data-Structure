#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

class Queue
{
    public:
        struct node * First;
        int iCount;
        Queue();
        bool IsQueueEmpty();
        void EnQueue(int no);
        int DeQueue();
        void Display();
};
Queue::Queue()
{
    First = NULL;
    iCount = 0;
}
bool Queue::IsQueueEmpty()
{
    if(iCount==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Queue::EnQueue(int no)
{
    struct node * newn = new struct node;
    newn->data = no;
    newn->next = NULL;

    if(First==NULL)
    {
        First = newn;
    }
    else
    {
        struct node * temp = First;
        while(temp->next!=NULL)
        {
            temp =temp->next;
        }
        temp->next = newn;
    }
    cout<<no<<" gets enqueue successfully in queue.."<<"\n";
}
int Queue::DeQueue()
{
    if(First==NULL)
    {
        cout<<"Queue is empty.."<<"\n";
    }
    else
    {
        int value  = First->data;
        struct node * temp = First;
        First = First->next;
        delete temp;
        iCount--;
        return value;
    }
}
void Queue::Display()  
{
    cout<<"Elements of queue are:"<<"\n";
    struct node * temp = First;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}      
int main()
{
    Queue qobj;

    qobj.EnQueue(51);
    qobj.EnQueue(21);
    qobj.EnQueue(11);
    qobj.Display();
    int iRet = qobj.DeQueue();
    cout<<iRet<<" is dequeue from queue.."<<"\n";
    qobj.Display();
    

    return 0;
}