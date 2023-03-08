#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node * next;
};

template<class T>
class Stack
{
    public :
        struct node <T>* First;
        int iCount;

        Stack();
        bool IsStackEmpty();
        void Push(T no);
        T Pop();
        void Display();
};
template<class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}
template<class T>
bool Stack<T>::IsStackEmpty()
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
void Stack<T>:: Push(T no)
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
        newn->next = First;
        First = newn;
    }
    iCount++;
    cout<<no<<" gets push into stack successfully..."<<"\n";
}
template<class T>
T Stack<T>:: Pop()
{
    if(First==NULL)
    {
        cout<<"Stack is empty..";
    }
    else
    {
        int value = First->data;
        struct node <T>* temp = First;
        First = First->next;
        iCount--;
        delete temp;
        return value;
    }
    
}
template<class T>
void Stack<T>:: Display()
{
    cout<<"Elements of stack are:.";
    struct node<T> * temp = First;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

int main()
{
    Stack <int>sobj;
    sobj.Push(51);
    sobj.Push(21);
    sobj.Push(11);
    sobj.Display();
    int iRet = sobj.Pop();
    cout<<"poped element is:"<<iRet<<"\n";
    sobj.Display();

    cout<<"\n";
    Stack <float>fobj;
    fobj.Push(51.25f);
    fobj.Push(21.25f);
    fobj.Push(11.25f);
    fobj.Display();
    float fRet = fobj.Pop();
    cout<<"poped element is:"<<fRet<<"\n";
    fobj.Display();

    cout<<"\n";
    Stack <double>dobj;
    dobj.Push(51.21);
    dobj.Push(21.21);
    dobj.Push(11.21);
    dobj.Display();
    double dRet = dobj.Pop();
    cout<<"poped element is:"<<dRet<<"\n";
    dobj.Display();

    cout<<"\n";
    Stack <char>cobj;
    cobj.Push('A');
    cobj.Push('B');
    cobj.Push('C');
    cobj.Display();
    char cRet = cobj.Pop();
    cout<<"poped element is:"<<cRet<<"\n";
    cobj.Display();


    return 0;
}