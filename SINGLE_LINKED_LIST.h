#ifndef _SINGLE_LINKED_LIST_H_
#define _SINGLE_LINKED_LIST_H_
#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
enum error_state
{
    SEARCH_FAILED = 2,
};
typedef s32 dtype;
typedef struct Node
{
    dtype data;
    struct Node* next;
    dtype len;
} Node;
void insert_last(Node **head,dtype val)
{
    if (*head==NULL)
    {
        *head = (Node*)malloc(sizeof(Node));
        (*head)->data = val;
        (*head)->next = NULL;
        (*head)->len = 0;
    }
    else
    {
        Node*tmp = (Node*)malloc(sizeof(Node));
        tmp->data = val;
        tmp->next = NULL;
        Node* cur = *head;
        while (cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next = tmp;
    }
    (*head)->len++;
}
void print(Node **head)
{
    Node *tmp = *head;
    while (tmp)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    puts("");
}
void delete_first(Node **head)
{
    if (*head==NULL)
    {
        return;
    }
    Node* tmp = (*head)->next;
    free(*head);
    *head = tmp;
    (*head)->len--;
}
void delete_last(Node **head)
{
    if(*head != NULL)
    {
        if((*head)->next == NULL)
        {
            *head = NULL;
        }
        else
        {
            Node* temp = *head;
            while(temp->next->next != NULL)
                temp = temp->next;
            Node* lastNode = temp->next;
            temp->next = NULL;
            free(lastNode);
            (*head)->len--;
        }
    }
}
void insert_first(Node **head,dtype value)
{
    if (!*head)(*head)->len = 0;
    Node *tmp = (Node*)malloc(sizeof(Node));
    tmp->data = value;
    tmp->next = *head;
    *head = tmp;
    (*head)->len++;
}
void insert_pos(Node **head,dtype index, dtype val)
{
    if (index<1 || index>(*head)->len+1)
    {
        printf("invalid position\n");
        return;
    }
    if (!*head)
    {
        *head = (Node*)malloc(sizeof(Node));
        (*head)->data = val;
        (*head)->next = NULL;
        (*head)->len = 0;
    }
    else
    {
        Node *added = (Node *)malloc(sizeof(Node));
        added->data = val;
        if (index==1)
        {
            added->next =(*head);
            (*head) = added;
        }
        else
        {
            u32 cur = 1;
            Node *tmp = (*head);
            while (tmp && cur<index-1)
            {
                cur++;
                tmp = tmp->next;
            }
            Node *after = tmp->next;
            tmp->next = added;
            added->next = after;
        }
    }
    printf("Node with value %d inserted succefully at index %d\n",val,index);
    (*head)->len++;
}
void delete_pos(Node **head,dtype index)
{
    if (index<1 || index>(*head)->len)
    {
        printf("invalid position\n");
        return;
    }
    if (index==1)
    {
        delete_first(head);
        return;
    }
    Node* prev = NULL;
    Node* tmp = *head;
    u32 cur = 1;
    while (cur!=index)
    {
        prev = tmp;
        tmp= tmp->next;
        cur++;
    }
    prev->next = tmp->next;
    free(tmp);
    tmp = NULL;
}
u8 search(Node **head,dtype val)
{
    for (Node *cur = *head; cur!=NULL; cur=cur->next)
    {
        if (cur->data==val)return 1;
    }
    exit(SEARCH_FAILED);
}
void update(Node **head,dtype index, dtype val)
{
    if (*head==NULL ||index<1 || index>(*head)->len)
    {
        printf("invalid position\n");
        return;
    };
    dtype cur = 1;
    Node *tmp = *head;
    while (cur!=index)
    {
        cur++;
        tmp = tmp->next;
    }
    tmp->data = val;
}
void sort(Node **head)
{
    for (Node *first = *head; first!=NULL; first= first->next)
    {
        Node* mini = first;
        for (Node * second=first->next; second !=NULL; second=second->next)
        {
            if (second->data<mini->data)mini = second;
        }
        u32 val = first->data;
        first->data = mini->data;
        mini->data = val;
    }
}
#endif // _SINGLE_LINKED_LIST_H_
