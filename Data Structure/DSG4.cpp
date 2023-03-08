#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};

template<class T>
class DoublyCL
{
    public:
        struct node <T>* First;
        struct node <T>* Last;

        DoublyCL();

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
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
}
template<class T>
void DoublyCL <T>:: InsertFirst(T no)
{
    struct node<T> * newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First = Last = newn;
        First->prev = Last;
        Last->next = First;
    }
    else
    {
        newn->next = First;
        First->next->prev = newn;
        First = newn;
        Last->next = First;
    }
}
template<class T>
void DoublyCL <T>:: InsertLast(T no)
{
    struct node <T>* newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First = Last = newn;
        First->prev = Last;
        Last->next = First;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
        First->prev = Last;
        Last->next = First;
    }
}
template<class T>
void DoublyCL <T>:: InsertAtPos(T no,int ipos)
{
    int NodeCount = Count();
    if((ipos<1)||(ipos>NodeCount+1))
    {
        cout<<"INVALIDE POSITION"<<"\n";
        return;
    }
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==NodeCount+1)
    {
        InsertLast(no);
    }
    else
    {
        int iCnt =0;
        struct node<T> * temp = First;
        struct node <T>* newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

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
void DoublyCL <T>:: DeleteFirst()
{
    if((First==NULL)&&(Last==NULL))
    {
        return;
    }
    else if(First==Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
         First->prev = Last;
        Last->next = First;
       
    }
}
template<class T>
void DoublyCL <T>:: DeleteLast()
{
    if(First == NULL && Last == NULL) // Empty LL
    {
        return;
    }
    else if(First == Last)    // Single node
    {
        delete First;
        First = NULL;
        Last= NULL;
    }
    else    // More than one node
    {
        Last = (Last) -> prev;
        delete (First)->prev;       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}
template<class T>
void DoublyCL <T>:: DeleteAtPos(int ipos)
{
    int NodeCount = Count();
    if((ipos<1)||(ipos>NodeCount+1))
    {
        cout<<"INVALIDE POSITION"<<"\n";
    }
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==NodeCount)
    {
        DeleteLast();
    }
    else
    {
        int iCnt = 0;
        struct node <T>* temp = First;
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
void DoublyCL <T>:: Display()
{
    struct node<T> * temp = First;
    cout<<"Elements of linked list are:"<<"\n";
    do 
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;

    }while(temp!=Last->next);
    cout<<"\n";
}
template<class T>
int DoublyCL <T>:: Count()
{
    int iCnt = 0;
    struct node <T>* temp = First;
    do
    {
        iCnt++;
        temp = temp->next;

    }while(temp!=Last->next);
    return iCnt;
}

int main()
{
    DoublyCL <int>cobj;
    cobj.InsertFirst(51);
    cobj.InsertFirst(21);
    cobj.InsertFirst(11);
    cobj.InsertLast(101);
    cobj.InsertLast(201);
    cobj.InsertLast(301);
    cobj.Display();
    cobj.InsertAtPos(1001,4);
    cobj.Display();
    cobj.DeleteFirst();
    cobj.DeleteLast();
    cobj.DeleteAtPos(3);
    cobj.Display();
    
    int iRet = cobj.Count();
    cout<<"NUMBER OF NODES:"<<iRet<<"\n";

    DoublyCL <char>obj;
    obj.InsertFirst('A');
    obj.InsertFirst('B');
    obj.InsertFirst('C');
    obj.InsertLast('D');
    obj.InsertLast('E');
    obj.InsertLast('F');
    obj.Display();
    obj.InsertAtPos('Z',4);
    obj.Display();
    obj.DeleteFirst();
    obj.DeleteLast();
    obj.DeleteAtPos(3);
    obj.Display();
    
    cout<<"\n";

    DoublyCL <float>fobj;
    fobj.InsertFirst(51.14f);
    fobj.InsertFirst(21.14f);
    fobj.InsertFirst(11.14f);
    fobj.InsertLast(101.14f);
    fobj.InsertLast(201.14f);
    fobj.InsertLast(301.14f);
    fobj.Display();
    fobj.InsertAtPos(1001.14f,4);
    fobj.Display();
    fobj.DeleteFirst();
    fobj.DeleteLast();
    fobj.DeleteAtPos(3);
    fobj.Display();
    
    cout<<"\n";

    DoublyCL <double>dobj;
    dobj.InsertFirst(51.21);
    dobj.InsertFirst(21.21);
    dobj.InsertFirst(11.21);
    dobj.InsertLast(101.21);
    dobj.InsertLast(201.21);
    dobj.InsertLast(301.21);
    dobj.Display();
    dobj.InsertAtPos(1001.21,4);
    dobj.Display();
    dobj.DeleteFirst();
    dobj.DeleteLast();
    dobj.DeleteAtPos(3);
    dobj.Display();
    
    return 0;
}