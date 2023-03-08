#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
};
typedef struct node NODE;
typedef struct node * PNODE;

class SinglyLL
{
    public:
        PNODE First;

        SinglyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int count();
};
SinglyLL :: SinglyLL()
{
    First = NULL;
}
void SinglyLL :: InsertFirst(int no)
{
    PNODE newn = new NODE;
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
void SinglyLL :: InsertLast(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;

    if(First==NULL)
    {
        First = newn;
    }
    else
    {
        PNODE temp = First;

        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}
void SinglyLL :: InsertAtPos(int no,int ipos)
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
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        PNODE temp = First;
        int iCnt = 0;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        
    }
}

void SinglyLL :: DeleteFirst()
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
        PNODE temp = First;
        First = First->next;
        delete temp;
    }
}
void SinglyLL :: DeleteLast()
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
        PNODE temp =First;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}
void SinglyLL :: DeleteAtPos(int ipos)
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
        PNODE temp1 = First;
        PNODE temp2 = NULL;
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

void SinglyLL :: Display()
{
    PNODE temp = First;
    cout<<"Elements of linked list are:";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}
int SinglyLL :: count()
{
    int iCnt =0 ;
    PNODE temp = First;
    while(temp!=NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

int main()
{
    SinglyLL sobj;

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

    return 0;
}