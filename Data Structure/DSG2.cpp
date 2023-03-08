#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node * next;
    struct node * prev;
};

template<class T>
class DoublyLL
{
    public:
        struct node<T> * First;

        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};
template<class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
}
template<class T>
void DoublyLL<T>:: InsertFirst(T no)
{
    struct node <T>* newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
}
template<class T>
void DoublyLL<T>:: InsertLast(T no)
{
    struct node <T>* newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        struct node <T>* temp = First;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }    
}
template<class T>
void DoublyLL<T>:: InsertAtPos(T no,int ipos)
{
    int iNodecount = Count();

    if((ipos<1)||(ipos>iNodecount+1))
    {
        cout<<"INVALIDE POSITION"<<"\n";
    }
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos ==iNodecount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        struct node<T> * temp = First;

        int iCnt = 0;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        
    }    
}
template<class T>
void DoublyLL<T>:: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }
}
template<class T>
void DoublyLL<T>:: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct node<T> * temp = First;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }    
}
template<class T>
void DoublyLL<T>:: DeleteAtPos(int ipos)
{
    int iNodecount = Count();

    if((ipos<1)||(ipos>iNodecount+1))
    {
        cout<<"INVALIDE POSITION"<<"\n";
    }
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos ==iNodecount+1)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp = First;

        int iCnt = 0;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}
template<class T>
void DoublyLL<T>:: Display()
{
    struct node <T>* temp = First;
    cout<<"Elements of linekd list are:"<<"\n";
    cout<<"NULL<=>";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}
template<class T>
int DoublyLL<T>:: Count()
{
    int iCnt= 0;
    struct node <T>* temp = First;
    while(temp!=NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;

}

int main()
{
    DoublyLL<int> dobj;
    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    dobj.InsertLast(101);
    dobj.InsertLast(201);
    dobj.InsertLast(301);
    dobj.Display();
    dobj.InsertAtPos(10001,4);
    dobj.Display();
    dobj.DeleteFirst();
    dobj.DeleteLast();
    dobj.DeleteAtPos(3);
    dobj.Display();

    cout<<"\n";

    DoublyLL<float> fobj;
    fobj.InsertFirst(51.2f);
    fobj.InsertFirst(21.2f);
    fobj.InsertFirst(11.2f);
    fobj.InsertLast(101.2f);
    fobj.InsertLast(201.2f);
    fobj.InsertLast(301.2f);
    fobj.Display();
    fobj.InsertAtPos(10001.2f,4);
    fobj.Display();
    fobj.DeleteFirst();
    fobj.Display();
    fobj.DeleteLast();
    fobj.Display();
    fobj.DeleteAtPos(3);
    fobj.Display();

    cout<<"\n";

    DoublyLL<char> cobj;
    cobj.InsertFirst('D');
    cobj.InsertFirst('C');
    cobj.InsertFirst('B');
    cobj.InsertLast('A');
    cobj.InsertLast('Y');
    cobj.InsertLast('Z');
    cobj.Display();
    cobj.InsertAtPos('M',4);
    cobj.Display();
    cobj.DeleteFirst();
    cobj.DeleteLast();
    cobj.DeleteAtPos(3);
    cobj.Display();

    cout<<"\n";

    DoublyLL<double> obj;
    obj.InsertFirst(51.23);
    obj.InsertFirst(21.26);
    obj.InsertFirst(11.24);
    obj.InsertLast(101.45);
    obj.InsertLast(201.24);
    obj.InsertLast(301.45);
    obj.Display();
    obj.InsertAtPos(10001.25,4);
    obj.Display();
    obj.DeleteFirst();
    obj.DeleteLast();
    obj.DeleteAtPos(3);
    obj.Display();
    return 0;
}