#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL , *end=NULL;
int count=0;
void create_nodes()
void display()
void create_nodes()
{
	int info;
	struct node *newnode;
    newnode=(struct node*)malloc(1*sizeof(struct node));
}
if(newnode==NULL)
{
	printf("Overflow");
	return;
}
printf("Enter data into a node");
scanf("%d",&info);
newnode-data=info;
newnode-next=NULL;
if(head==NULL)
{
	head=end=newnode;
}
else
{
	end-next=newnode;
	end=newnode;
}
count++;
printf("\n node is created or added");
void display()
{
	struct node *temp;
	if(head=NULL)
	{
		printf("\n list is empty");
		return 0;
	}
	temp=head;
	while(temp!=NULL)
	{
		printf("%d-",temp-data);
		temp=temp-next;
	}
}
int main()
{
	int i;
	for(i=0;i<4;i++)
	create_nodes();
	display();
}