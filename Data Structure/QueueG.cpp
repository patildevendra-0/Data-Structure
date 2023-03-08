#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node * next;
};
template<class T>
class Queue
{
    public:
        struct node<T> * First;
        int iCount;
        Queue();
        bool IsQueueEmpty();
        void EnQueue(T no);
        T DeQueue();
        void Display();
};
template<class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}
template<class T>
bool Queue<T>::IsQueueEmpty()
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
template<class T>
void Queue<T>::EnQueue(T no)
{
    struct node <T>* newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;

    if(First==NULL)
    {
        First = newn;
    }
    else
    {
        struct node<T> * temp = First;
        while(temp->next!=NULL)
        {
            temp =temp->next;
        }
        temp->next = newn;
    }
    cout<<no<<" gets enqueue successfully in queue.."<<"\n";
}
template<class T>
T Queue<T>::DeQueue()
{
    if(First==NULL)
    {
        cout<<"Queue is empty.."<<"\n";
    }
    else
    {
        T value  = First->data;
        struct node <T>* temp = First;
        First = First->next;
        delete temp;
        iCount--;
        return value;
    }
}
template<class T>
void Queue<T>::Display()  
{
    cout<<"Elements of queue are:"<<"\n";
    struct node <T>* temp = First;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}      
int main()
{
    Queue<int> qobj;

    qobj.EnQueue(51);
    qobj.EnQueue(21);
    qobj.EnQueue(11);
    qobj.Display();
    int iRet = qobj.DeQueue();
    cout<<iRet<<" is dequeue from queue.."<<"\n";
    qobj.Display();

    cout<<"\n";
     Queue<char> cobj;

    cobj.EnQueue('A');
    cobj.EnQueue('B');
    cobj.EnQueue('c');
    cobj.Display();
    char cRet = cobj.DeQueue();
    cout<<cRet<<" is dequeue from queue.."<<"\n";
    cobj.Display();

    cout<<"\n";
     Queue<float> fobj;

    fobj.EnQueue(51.12);
    fobj.EnQueue(21.15);
    fobj.EnQueue(11.14);
    fobj.Display();
    float fRet = fobj.DeQueue();
    cout<<fRet<<" is dequeue from queue.."<<"\n";
    fobj.Display();

    cout<<"\n";
     Queue<double> dobj;

    dobj.EnQueue(51.12);
    dobj.EnQueue(21.15);
    dobj.EnQueue(11.48);
    dobj.Display();
    double dRet = dobj.DeQueue();
    cout<<dRet<<" is dequeue from queue.."<<"\n";
    dobj.Display();
    

    return 0;
}