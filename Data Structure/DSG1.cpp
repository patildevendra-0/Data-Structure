#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node * next;
};

template<class T>
class SinglyLL
{
    public:
        struct node <T>* First;

        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int count();
};
template<class T>
SinglyLL <T>:: SinglyLL()
{
    First = NULL;
}
template<class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct node <T>* newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;

    if(First== NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}
template<class T>
void SinglyLL<T> :: InsertLast(T no)
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
        struct node <T>* temp = First;

        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}
template<class T>
void SinglyLL<T> :: InsertAtPos(T no,int ipos)
{
    int iNodecount = 0;

    iNodecount = count();
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
void SinglyLL<T> :: DeleteFirst()
{
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct node <T>* temp = First;
        First = First->next;
        delete temp;
    }
}
template<class T>
void SinglyLL<T> :: DeleteLast()
{
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct node <T>* temp =First;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}
template<class T>
void SinglyLL<T> :: DeleteAtPos(int ipos)
{
    int iNodecount = count();

    if((ipos<1)||(ipos>iNodecount+1))
    {
        cout<<"invalide position";
    }
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==iNodecount)
    {
        DeleteLast();
    }
    else
    {
        struct node <T>* temp1 = First;
        struct node <T>* temp2 = NULL;
        int iCnt =0 ;
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
void SinglyLL <T>:: Display()
{
    struct node<T> * temp = First;
    cout<<"Elements of linked list are:";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}
template<class T>
int SinglyLL<T> :: count()
{
    int iCnt =0 ;
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
    SinglyLL <int>sobj;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    sobj.InsertLast(101);
    sobj.InsertLast(201);
    sobj.InsertLast(301);
    sobj.Display();

    sobj.InsertAtPos(1001,4);
    sobj.Display();

    sobj.DeleteFirst();
    sobj.Display();
    sobj.DeleteLast();
    sobj.Display();
    sobj.DeleteAtPos(3);
    sobj.Display();

    int iRet = sobj.count();
    cout<<"Nodes in linked list are:"<<iRet<<"\n";

    SinglyLL <float>obj;

    obj.InsertFirst(51.2f);
    obj.InsertFirst(21.3f);
    obj.InsertFirst(11.21f);
    obj.InsertLast(101.2f);
    obj.InsertLast(201.2f);
    obj.InsertLast(301.2f);
    obj.Display();

    obj.InsertAtPos(1001.2f,4);
    obj.Display();

    obj.DeleteFirst();
    obj.Display();
    obj.DeleteLast();
    obj.Display();
    obj.DeleteAtPos(3);
    obj.Display();

     iRet = obj.count();
    cout<<"Nodes in linked list are:"<<iRet<<"\n";

    SinglyLL <char>cobj;

    cobj.InsertFirst('A');
    cobj.InsertFirst('B');
    cobj.InsertFirst('C');
    cobj.InsertLast('D');
    cobj.InsertLast('E');
    cobj.InsertLast('F');
    cobj.Display();

    cobj.InsertAtPos('Z',4);
    cobj.Display();

    cobj.DeleteFirst();
    cobj.Display();
    cobj.DeleteLast();
    cobj.Display();
    cobj.DeleteAtPos(3);
    cobj.Display();

     iRet = cobj.count();
    cout<<"Nodes in linked list are:"<<iRet<<"\n";

    SinglyLL <double>dobj;

    dobj.InsertFirst(51.5);
    dobj.InsertFirst(21.5);
    dobj.InsertFirst(11.5);
    dobj.InsertLast(101.5);
    dobj.InsertLast(201.5);
    dobj.InsertLast(301.5);
    dobj.Display();

    dobj.InsertAtPos(1001.5,4);
    dobj.Display();

    dobj.DeleteFirst();
    dobj.Display();
    dobj.DeleteLast();
    dobj.Display();
    dobj.DeleteAtPos(3);
    dobj.Display();

     iRet = dobj.count();
    cout<<"Nodes in linked list are:"<<iRet<<"\n";


    return 0;
}