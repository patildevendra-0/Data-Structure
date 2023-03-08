#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
typedef struct node NODE;
typedef struct node * PNODE;

class DoublyLL
{
    public:
        PNODE First;

        DoublyLL();
        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPos(int no,int ipos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);

        void Display();
        int Count();
};

DoublyLL::DoublyLL()
{
    First = NULL;
}
void DoublyLL:: InsertFirst(int no)
{
    PNODE newn = new NODE;
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
void DoublyLL:: InsertLast(int no)
{
    PNODE newn = new NODE;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
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
        newn->prev = temp;
    }    
}
void DoublyLL:: InsertAtPos(int no,int ipos)
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
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        PNODE temp = First;

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

void DoublyLL:: DeleteFirst()
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
void DoublyLL:: DeleteLast()
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
        PNODE temp = First;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }    
}
void DoublyLL:: DeleteAtPos(int ipos)
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
        PNODE temp = First;

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

void DoublyLL:: Display()
{
    PNODE temp = First;
    cout<<"Elements of linekd list are:"<<"\n";
    cout<<"NULL<=>";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}
int DoublyLL:: Count()
{
    int iCnt= 0;
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
    DoublyLL dobj;
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
    dobj.Display();
    dobj.DeleteLast();
    dobj.Display();
    dobj.DeleteAtPos(3);
    dobj.Display();
    return 0;
}