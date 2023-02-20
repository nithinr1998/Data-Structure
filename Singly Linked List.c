#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
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
        printf("choose a Option\n\n");
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
    if(ptr == NULL)
    {
        printf("Invalid\n");
    }
    else
    {
        printf("\nEnter the value\n");
        scanf("%d",&item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nValue has been inserted at begining");
    }
}
void insatlast()
{
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("invalid\n");
    }
    else
    {
        printf("\nEnter the value?\n");
        scanf("%d",&item);
        ptr->data = item;
        if(head == NULL)
        {
            ptr -> next = NULL;
            head = ptr;
            printf("\n Inserted at end ");
        }
        else
        {
            temp = head;
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("\nNode inserted\n");

        }
    }
}
void insatrandom()
{
    int i,loc,item;
    struct node *newnode, *temp;
    newnode= (struct node *) malloc (sizeof(struct node));
    if(newnode== NULL)
    {
        printf("The list is empty");
    }
    else
    {
        printf("\nEnter the value to be inserted");
        scanf("%d",&item);
        newnode->data = item;
        printf("\n Enter the location after which you want to insert ");
        scanf("\n%d",&loc);
        temp=head;
        while(temp->data!=loc)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\n insertion impossible\n");
                return;
            }
        }
        newnode ->next = temp ->next;
        temp ->next = newnode;
        printf("\nNode inserted after %d",loc);
    }
    struct node;
    temp=head;
   printf("\n\n Elements in the list are \n");
   while(temp->next!=NULL)
      {
       printf("%d ->",temp->data);
       temp = temp->next;
      }
     printf("%d ->NULL",temp->data);
}
void delatfirst()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }



   else  {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the beginning ...\n");
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
void delatrandom()
{
    struct node *ptr,*ptr1;
    int loc,i;
    if(head == NULL)
    {
        printf("\nList is empty\n");

    }
    else
    {
    printf("\n Enter the element which you want to delete \n");
    scanf("%d",&loc);
    ptr=head;
   while (ptr->data!=loc && ptr!=NULL)
    {
            ptr1=ptr;
            ptr = ptr->next;
        }
    ptr1 ->next = ptr ->next;
        ptr ->next = ptr1;
        free(ptr);
        printf("\nNode deleted");
    }
}
void display()
{
    ptr = head;
    if(ptr == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("\n The given list  \n");
        while (ptr->next!=NULL)
        {
            printf("%d->",ptr->data);
            ptr = ptr -> next;
        }
         printf("%d->NULL",ptr->data); }
}
