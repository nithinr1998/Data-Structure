#include<stdio.h>
#include<stdlib.h>
void bitwiseor();
void bitwiseand();
void differance();
void equality();
int n1,n2,i,j,size1,size2,k,flag=0,a[50],b[50],c[50],d[50];
void main()
{
   printf(" 1.UNION \n 2.INTERSECTION \n 3.DIFFERECE \n 4.EQUALITY \n 5.EXIT \n");
   int choice=0;
   while(choice!=5)
   {
   printf("ENTER THE CHOICE \n");
   scanf("%d",&choice);
   switch(choice)
        {
            case 1:
            bitwiseor();
            break;
            case 2:
            bitwiseand();
            break;
            case 3:
            difference();
            break;
            case 4:
            equality();
             case 5:
            exit(0);
            break;
            default : printf("Enter a valid choice \n");
        }
   }
}
void bitwiseor()
{
    printf("Enter size of first  set\n");
   scanf("%d",&size1);
   printf("Enter size of second set \n");
   scanf("%d",&size2);
   printf("Enter the first set elements \n");
   for(i=0;i<size1;i++)
    {
      scanf("%d",&a[i]);
    }
   printf("Enter the second set \n");
   for(i=0;i<size2;i++)
    {
      scanf("%d",&b[i]);
    }
   if(size1!=size2)
   {
       printf("The sets are not equal");
   }
   else
   {
   for(i=0;i<size1;i++)
   {
    c[i]=a[i] || b[i];
    printf("%d ",c[i]);
   }
}
printf("is the union\n");
return 0;
}
void bitwiseand()
{
    printf("Enter size of first  set\n");
   scanf("%d",&size1);
   printf("Enter size of second set \n");
   scanf("%d",&size2);
   printf("Enter the first set elements \n");
   for(i=0;i<size1;i++)
    {
      scanf("%d",&a[i]);
    }
   printf("Enter the second set \n");
   for(i=0;i<size2;i++)
    {
      scanf("%d",&b[i]);
    }
   if(size1!=size2)
   {
       printf("The sets are not equal");
   }
   else
   {
   for(i=0;i<size1;i++)
   {
    c[i]=a[i] && b[i];
    printf("%d ",c[i]);
   }
}
printf("is the intercestion \n");
return 0;
}
void difference()
{
    printf("Enter size of first  set\n");
   scanf("%d",&size1);
   printf("Enter size of second set \n");
   scanf("%d",&size2);
   printf("Enter the first set elements \n");
   for(i=0;i<size1;i++)
    {
      scanf("%d",&a[i]);
    }
   printf("Enter the second set \n");
   for(i=0;i<size2;i++)
    {
      scanf("%d",&b[i]);
    }
   if(size1!=size2)
   {
       printf("The sets are not equal");
   }
   else
   {
   for(i=0;i<size1;i++)
   {
    c[i]=!b[i];
   }
   for(i=0;i<size2;i++)
   {
       d[i]=c[i] && a [i];
       printf("%d",d[i]);
   }
}
printf(" is the difference \n");
return 0;
}
void equality()
{
    printf("Enter size of first  set\n");
   scanf("%d",&size1);
   printf("Enter size of second set \n");
   scanf("%d",&size2);
   printf("Enter the first set elements \n");
   for(i=0;i<size1;i++)
    {
      scanf("%d",&a[i]);
    }
   printf("Enter the second set \n");
   for(i=0;i<size2;i++)
    {
      scanf("%d",&b[i]);
    }
   if(size1!=size2)
   {
       printf("The sets are not equal");
   }
   else
   {
   for(i=0;i<size1;i++)
   {
       if(a[i]!=b[i])
       {
           printf("The sets are not equal");
           return 0;
       }
   }
   printf("The given sets are equal");
}
}

