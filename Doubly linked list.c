#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL,*ptr;
void insatbegin();
void insatlast();
void insatrandom();
void delatfirst();
void delatlast();
void delatrandom();
void display();
void main()
{
    int choice=0;
    while(choice!=8)
    {
        printf("Choose a Option\n\n");
        printf(" 1.insert at beginning\n 2.insert at end\n 3.insert at a certain  position\n 4.delete at first\n 5.delete at last\n 6.delete a value \n 7.display the list\n 8.exit \n");
        printf("\n Enter the choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insatbegin();
            break;
            case 2:
            insatlast();
            break;
            case 3:
            insatrandom();
            break;
            case 4:
            delatfirst();
            break;
            case 5:
            delatlast();
            break;
            case 6:
            delatrandom();
            break;
            case 7:
            display();
            break;
            default:;
            printf("Enter a valid choice: \n");
        }
    }
}
void insatbegin()
{
    struct node *ptr;
    int item;
    ptr = (struct node *) malloc(sizeof(struct node *));
    printf("\nEnter the value\n");
    scanf("%d",&item);
    ptr->data=item;
    if(head == NULL)
    {
        ptr->next=NULL;
        ptr->prev=NULL;
        head=ptr;
    }
    else
    {
        ptr->next = head;
        ptr->prev=NULL;
        head = ptr;
        printf("\nValue has been inserted at beginning \n");
    }
}
void insatlast()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the value?\n");
    scanf("%d",&item);
    ptr->data = item;
    if(head == NULL)
    {
        ptr->next=NULL;
        ptr->prev=NULL;
        head = ptr;
        printf("\nValue inserted at end ");
    }
    else
    {
     temp=head;
     while(temp->next!=NULL)
        {
            temp = temp -> next;
        }
        temp->next=ptr;
        ptr->next=NULL;
        ptr->prev=temp;
        printf("\nNode inserted at end \n");
    }
}
void insatrandom()
{
    int loc,item;
    struct node *newnode, *temp;
    newnode= (struct node *) malloc (sizeof(struct node));
    printf("\nEnter the value to be inserted");
    scanf("%d",&item);
    newnode->data = item;
    printf("\n Enter the location after which you want to insert ");
    scanf("\n%d",&loc);
    if(head==NULL)
    {
        printf("The list is empty \n");
    }
     else
        {
        temp=head;
        while(temp->data!=loc)
        {
            if(temp->next!=loc)
            {
                printf("\n Location not found \n");
                return 0;

            }
            temp=temp->next;
        }

           if(temp->data==loc && temp->next!=NULL && temp->prev!=NULL)
           {
           newnode->next=temp->next;
           temp->next->prev=newnode;
           temp ->next = newnode;
           newnode->prev=temp;
           printf("\nNode inserted after %d",loc);
           }
           else if(temp->data==loc && temp->next==NULL && temp->prev!=NULL)
           {
               temp->next=newnode;
               newnode->next=NULL;
               newnode->prev=temp;
           }
           else if(temp->data==loc && temp->next!=NULL && temp->prev==NULL)
           {
               newnode->next=temp->next;
               temp->next=newnode;
               newnode->prev=temp;
               newnode->next->prev=newnode;
           }
           else if(temp->data)
           {
               printf("\n Given data not found on the List");
           }
           else
           {
               printf("\n The given value not found on the list");
           }
       }
}

void display()
{
    ptr = head;
    if(ptr == NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        printf("\n The given list  \n");
        while (ptr->next!=NULL)
        {
            printf("%d<=>",ptr->data);
            ptr = ptr -> next;
        }
         printf("%d->NULL \n",ptr->data);

    }
}
void delatlast()
{
    struct node *ptr,*ptr1;
    if(head == NULL)
    {
        printf("\n list is empty");
    }
    else if(head -> next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly 1 node and it has been deleted\n");
    }
    else
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr ->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted the last node\n");
    }
}
void delatfirst()
{
    struct node *ptr,*ptr1;
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        free(head);
        printf("\nDeleted the only 1 node which belonged to the list\n");
    }
    else
    {
        ptr = head;
        head=ptr->next;
        ptr->next->prev=NULL;
        free(ptr);
        printf("\nNode deleted from the beginning ...\n");
    }
}
void delatrandom()
{
    struct node *ptr,*ptr1,*temp;
    int loc,count=0;
    printf("\n Enter the element which you want to delete \n");
    scanf("%d",&loc);

    if(head == NULL)
    {
        printf("\nList is empty\n");

    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data==loc)
            {
                count++;
            }
            temp=temp->next;
        }
    if(count==0)
    {
        printf("The location not found on list \n");
    }
    else
    {
    ptr=head;
    if(head->data==loc&&head->next==NULL)
    {
        ptr=head;
        head=NULL;
        free(ptr);
        printf("\nOnly one node and it has been deleted\n");
    }
    else
    {
    while (ptr->data!=loc && ptr!=NULL)
    {

            ptr1=ptr;
            ptr = ptr->next;

    }
    if(ptr->data==loc && ptr->prev!=NULL && ptr->next==NULL)
    {

        ptr1->next=NULL;
        free(ptr);
        printf("\nNode deleted \n");

    }
    else if(ptr->data==loc && ptr1->prev==NULL && ptr->next!=NULL)
    {
         ptr1->next=ptr->next;
         ptr1->next->prev=ptr1;
        free(ptr);
        printf("\nNode deleted \n");

    }
    else if(ptr->data==loc && ptr->prev!=NULL && ptr->next!=NULL)
    {
        ptr1->next=ptr->next;
         ptr1->next->prev=ptr1;
        free(ptr);
        printf("\nNode deleted \n");

    }
    }
    }
}
}
