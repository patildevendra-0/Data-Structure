#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void Display(PNODE First,PNODE Last)
{
    printf("Elements of linekd list are:");
    do
    {
        printf("|%d|<=>",First->data);
        First = First->next;
    }while(First!=Last->next);
    printf("\n");
}
int Count(PNODE First,PNODE Last)
{
    int iCnt = 0;
    do
    {
        iCnt++;
        First = First->next;
    }while(First!=Last->next);
    return iCnt;
}
void InsertFirst(PPNODE First,PPNODE Last,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*First ==NULL)&&(*Last==NULL))
    {
        *First = *Last = newn;
        (*First)->prev = *Last;
        (*Last)->next = *First;
    }
    else
    {
        newn->next = *First;
        (*First)->prev = newn;
        *First = newn;
        (*Last)->next = *First;
        (*First)->prev = *Last;
    }
}
void InsertLast(PPNODE First,PPNODE Last,int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if((*First ==NULL)&&(*Last==NULL))
    {
        *First = *Last = newn;
        (*First)->prev = *Last;
        (*Last)->next = *First;
    }
    else
    {
        (*Last)->next = newn;
        newn->prev = *Last;
        *Last = newn;
        (*Last)->next = *First;
       (*First)->prev = *Last;
    }
}
void InsertAtPos(PPNODE First,PPNODE Last,int no,int ipos)
{
    int iCnt = 0;
    int iNodeCnt = 0;
    PNODE temp = *First;
    PNODE newn = NULL;

    iNodeCnt = Count(*First,*Last);
    if((ipos<1)&&(ipos>iNodeCnt+1))
    {
        printf("INVALIDE POSITION");
    }
    if(ipos==1)
    {
        InsertFirst(First,Last,no);
    }
    else if(ipos==iNodeCnt+1)
    {
        InsertLast(First,Last,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
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

void DeleteFirst(PPNODE First,PPNODE Last)
{
    if((*First==NULL)&&(*Last==NULL))
    {
        return;
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        *First = (*First)->next;
        free((*Last)->next);
        (*Last)->next = *First;
        (*First)->prev = *Last;

    }
}

void DeleteLast(PPNODE First,PPNODE Last)
{
    if((*First==NULL)&&(*Last==NULL))
    {
        return;
    }
    else if(*First == *Last)
    {
        free(*First);
        *First = NULL;
        *Last = NULL;
    }
    else
    {
        *Last = (*Last)->prev;
        free((*First)->prev);
        (*First)->prev = *Last;
        (*Last)->next = *First;
    }    
}
void DeleteAtPos(PPNODE First,PPNODE Last,int ipos)
{
    int iCnt = 0;
    int iNodeCnt = 0;
    PNODE temp = *First;
    

    iNodeCnt = Count(*First,*Last);
    if((ipos<1)&&(ipos>iNodeCnt+1))
    {
        printf("INVALIDE POSITION");
    }
    if(ipos==1)
    {
        DeleteFirst(First,Last);
    }
    else if(ipos==iNodeCnt+1)
    {
        DeleteLast(First,Last);
    }
    else
    {
        for(iCnt=1;iCnt<ipos-1;iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
    }

}
int main()
{
    PNODE Head = NULL;
    PNODE Tail = NULL;
    int iRet = 0;
    InsertFirst(&Head,&Tail,51);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,11);
    Display(Head,Tail);
    InsertLast(&Head,&Tail,101);
    InsertLast(&Head,&Tail,201);
    InsertLast(&Head,&Tail,301);
    Display(Head,Tail);
    InsertAtPos(&Head,&Tail,1001,4);
    Display(Head,Tail);

    DeleteFirst(&Head,&Tail);
    DeleteLast(&Head,&Tail);
    Display(Head,Tail);

    DeleteAtPos(&Head,&Tail,3);
    Display(Head,Tail);

    iRet = Count(Head,Tail);
    printf("number of nodes in linkedlist are:%d\n",iRet);
    return 0;
}