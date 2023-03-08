#include<stdio.h>
#include<stdlib.h>

# pragma pack(1)
struct node
{
    int data;
    struct node * next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int Count(PNODE First)
{
    int iCnt = 0;
    while(First!=NULL)
    {
        iCnt++;
        First = First->next;
    }
    return iCnt;
}

void Display(PNODE First)
{
    printf("Elements of linkedlist are :");
    while(First!=NULL)
    {
        printf("|%d|->",First->data);
        First = First->next;
    }
    printf("NULL\n");
}

void InsertFirst(PPNODE First,int No)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if(*First==NULL)
    {
        *First = newn;
    }
    else
    {
        newn->next = *First;
        *First = newn;
    }
}

void InsertLast(PPNODE First,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;

    PNODE temp = *First;

    if(*First==NULL)
    {
        *First = newn;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

void InsertAtPos(PPNODE First,int no,int ipos)
{
    int NodeCnt = 0;
    int iCnt = 0;
    
    PNODE newn  = NULL;
    PNODE temp  = NULL;

    NodeCnt = Count(*First);

    if((ipos<1)||(ipos>NodeCnt+1))
    {
        printf("INVALIDE POSITION...");
    }
    if(ipos==1)
    {
        InsertFirst(First,no);
    }
    else if(ipos==NodeCnt+1)
    {
        InsertLast(First,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        temp = *First;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        newn->next=temp->next;
        temp->next = newn;
    }
}

void DeleteFirst(PPNODE First)
{
    PNODE temp = *First;

    if((*First)==NULL)
    {
        return;
    }
    else if((*First)->next==NULL)
    {
        free(*First);
        *First=NULL;
    }
    else
    {
        (*First) = (*First)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE First)
{
    PNODE temp = *First;

    if((*First)==NULL)
    {
        return;
    }
    else if((*First)->next==NULL)
    {
        free(*First);
        *First=NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void DeleteAtPos(PPNODE First,int ipos)
{
    PNODE temp1 = NULL;
    PNODE temp2 = NULL;

    int NodeCnt = 0;
    int iCnt = 0;

    NodeCnt = Count(*First);

    if((ipos<1)||(ipos>NodeCnt+1))
    {
        printf("INVALIDE position");
    }
    if(ipos==1)
    {
        DeleteFirst(First);
    }
    else if(ipos==NodeCnt)
    {
        DeleteLast(First);
    }
    else
    {
        temp1 = *First;
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);


    }
}
int main()
{
    PNODE Head = NULL;
    int iRet = 0;

    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);
    InsertLast(&Head,101);
    InsertLast(&Head,201);
    InsertLast(&Head,301);
    InsertAtPos(&Head,1001,4);
    Display(Head);
    DeleteFirst(&Head);
    Display(Head);
    DeleteLast(&Head);
    Display(Head);
    DeleteAtPos(&Head,3);
    Display(Head);

    iRet = Count(Head);
    printf("Number of nodes in lineked list are :%d\n",iRet);


    return 0;
}