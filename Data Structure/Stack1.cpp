#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

class Stack
{
    public :
        struct node * First;
        int iCount;

        Stack();
        bool IsStackEmpty();
        void Push(int no);
        int Pop();
        void Display();
};

Stack::Stack()
{
    First = NULL;
    iCount = 0;
}
bool Stack:: IsStackEmpty()
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
void Stack:: Push(int no)
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
        newn->next = First;
        First = newn;
    }
    iCount++;
    cout<<no<<" gets push into stack successfully..."<<"\n";
}
int Stack:: Pop()
{
    if(First==NULL)
    {
        cout<<"Stack is empty..";
    }
    else
    {
        int value = First->data;
        struct node * temp = First;
        First = First->next;
        iCount--;
        delete temp;
        return value;
    }
    
}
void Stack:: Display()
{
    cout<<"Elements of stack are:.";
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
    Stack sobj;
    sobj.Push(51);
    sobj.Push(21);
    sobj.Push(11);

    sobj.Display();

    int iRet = sobj.Pop();
    cout<<"poped element is:"<<iRet<<"\n";
    sobj.Display();

    return 0;
}