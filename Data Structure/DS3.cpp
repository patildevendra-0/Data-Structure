#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node * next;
};

template<class T>
class SinglyCL
{
    public:
       struct node <T>* First;
        struct node <T>* Last;

        SinglyCL();
        
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
SinglyCL<T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
}
template<class T>        
void SinglyCL<T>:: InsertFirst(T no)
{
    struct node<T> * newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First = Last = newn;
        Last->next = First;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = First;
    }
}
template<class T>
void SinglyCL<T>:: InsertLast(T no)
{
    struct node <T>* newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;

    if((First==NULL)&&(Last==NULL))
    {
        First = Last = newn;
        Last->next = First;
    }
    else
    {
        Last->next = newn;
        Last = newn;
        Last->next = First;
    }
}
template<class T>
void SinglyCL<T>:: InsertAtPos(T no,int ipos)
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
    else if(ipos==iNodecount+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> * newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;
        struct node <T>* temp = First;

        int iCnt = 0;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}
template<class T>
void SinglyCL<T>:: DeleteFirst()
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
        Last->next = First;
    }
}
template<class T>
void SinglyCL<T>:: DeleteLast()
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
        struct node<T> * temp = First;
        while(temp->next!=Last)
        {
            temp = temp->next;
        }
        delete temp->next;
        Last = temp;
        Last->next = First;
    }
}
template<class T>
void SinglyCL<T>:: DeleteAtPos(int ipos)
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
    else if(ipos==iNodecount+1)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp1 = First;
        struct node <T>* temp2 = NULL;
        int iCnt = 0;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;
    }
}
template<class T>
void SinglyCL<T>:: Display()
{
    struct node<T> * temp = First;
    cout<<"Elements of linekd list are:"<<"\n";
    do
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }while(temp!=Last->next);
    cout<<"\n";
}
template<class T>
int SinglyCL<T>:: Count()
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
    SinglyCL <int>cobj;
    cobj.InsertFirst(51);
    cobj.InsertFirst(21);
    cobj.InsertFirst(11);
    cobj.InsertLast(101);
    cobj.InsertLast(201);
    cobj.InsertLast(301);
    cobj.Display();
    cobj.InsertAtPos(10001,4);
    cobj.Display();
    cobj.DeleteFirst();
    cobj.DeleteLast();
    cobj.DeleteAtPos(3);
    cobj.Display();

    int iRet = cobj.Count();
    cout<<"NUMBER OF NODES :"<<iRet<<"\n";
    cout<<"\n";
    SinglyCL <char>obj;
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
    SinglyCL <float>fobj;
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
    fobj.DeleteLast();
    fobj.DeleteAtPos(3);
    fobj.Display();

    cout<<"\n";
    SinglyCL <double>dobj;
    dobj.InsertFirst(51.45);
    dobj.InsertFirst(21.45);
    dobj.InsertFirst(11.45);
    dobj.InsertLast(101.45);
    dobj.InsertLast(201.45);
    dobj.InsertLast(301.45);
    dobj.Display();
    dobj.InsertAtPos(10001.45,4);
    dobj.Display();
    dobj.DeleteFirst();
    dobj.DeleteLast();
    dobj.DeleteAtPos(3);
    dobj.Display();

    return 0;
}