#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
typedef struct node * PNODE;

class DoublyCL
{
    public:
        PNODE First;
        PNODE Last;

        DoublyCL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

DoublyCL::DoublyCL()
{
    First = NULL;
    Last = NULL;
}
void DoublyCL :: InsertFirst(int no)
{
    PNODE newn = new NODE;
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
void DoublyCL :: InsertLast(int no)
{
    PNODE newn = new NODE;
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
void DoublyCL :: InsertAtPos(int no,int ipos)
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
        PNODE temp = First;
        PNODE newn = new NODE;
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
void DoublyCL :: DeleteFirst()
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

void DoublyCL :: DeleteLast()
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
void DoublyCL :: DeleteAtPos(int ipos)
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
        PNODE temp = First;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
    }
}
void DoublyCL :: Display()
{
    PNODE temp = First;
    cout<<"Elements of linked list are:"<<"\n";
    do 
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;

    }while(temp!=Last->next);
    cout<<"\n";
}
int DoublyCL :: Count()
{
    int iCnt = 0;
    PNODE temp = First;
    do
    {
        iCnt++;
        temp = temp->next;

    }while(temp!=Last->next);
    return iCnt;
}

int main()
{
    DoublyCL cobj;
    cobj.InsertFirst(51);
    cobj.InsertFirst(21);
    cobj.InsertFirst(11);
    cobj.Display();
    cobj.InsertLast(101);
    cobj.InsertLast(201);
    cobj.InsertLast(301);
    cobj.Display();
    cobj.InsertAtPos(1001,4);
    cobj.Display();

    cobj.DeleteFirst();
    cobj.Display();
    cobj.DeleteLast();
    cobj.Display();
    cobj.DeleteAtPos(3);
    cobj.Display();
    
    int iRet = cobj.Count();
    cout<<"NUMBER OF NODES:"<<iRet<<"\n";
    return 0;
}