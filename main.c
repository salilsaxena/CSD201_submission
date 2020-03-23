#include<stdio.h>
#include<stdlib.h>
#include"def.h"
void main()
{
  node* root = NULL;
  int choice,ele1,ele2;
  //menu driven program starts now: 
  printf("Some of these functions may not be able to irregular cases\nSo please use them carefully\n");
  while(1)
  {
    printf("Menu\n\t1.Insert\n\t2.Post order traversal\n\t3.Height\n\t4.No_sibling\n\t5.Cousin_nodes\n\t6.Find left leaves sum\n\t7.Spiral order traversal\n\t8.Exit\n:");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:
        printf("Enter the element you want to insert: ");
        scanf("%d",&ele1);
        root = insert(root,ele1);      
        break;
      case 2:
        postorder(root);
        printf("\n");
        break;
      case 3:
        printf("Height: %d\n",height(root));
        break;
      case 4:
        no_siblings(root);
        printf("\n");
        break;
      case 5:
        printf("Enter 1st element: ");
        scanf("%d",&ele1); 
        printf("Enter 2nd element: ");
        scanf("%d",&ele2);
        cousin_nodes(root,ele1,ele2);
        break;
      case 6:
        printf("Sum of all left leaves: %d\n",leftLeafSum(root));
        break;
      case 7:
        spiralorder_traversal(root);
        printf("\n");
        break;
      case 8: 
        exit(0);
      default:
        printf("try again!\n");
   }
  }
}

