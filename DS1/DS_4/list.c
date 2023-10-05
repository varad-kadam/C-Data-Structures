#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void create (struct node *head)
{
	struct node *temp;
	struct node *curr;
	temp=head;
	int i=1;
	char ch='Y';
	while(i==1)
	{
		curr=(struct node*)malloc(sizeof(struct node));
		printf("\nEnter the roll nos\n");
		scanf("%d",&curr->data);
		curr->next=NULL;
		temp->next=curr;
		temp=temp->next;
		printf("\ncontinue 1.Yes\n  2.No\n");
		scanf("%d",&i);
	}
}

void display(struct node *head)
{
	struct node *curr;
	curr=head->next;
	printf("%p \n",head);
	while(curr!=NULL)
	{
		printf("\n %p 	%d	 %p",curr,curr->data,curr->next);
		curr=curr->next;
	}
}

int length(struct node *head)
{
	int count=0;
	struct node *curr;
	curr=head->next;
	while(curr!=NULL)
	{
		count++;
		curr=curr->next;
	}
	return count;
}

void insert( struct node *head,int pos)
{
	int i=1;
	struct node *curr;
	struct node *newnode;
	curr=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("\nInput Roll No.\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	int k=length(head);
	if(pos>k+1)
	{
		printf("\nData cannot be inserted, pick a different index\n");
	}
	
	else
	{
		while(i<pos)
		{
			i++;
			curr=curr->next;
		}
		newnode->next=curr->next;
		curr->next=newnode;
	}
}

void delete(struct node *head,int pos)
{
	struct node *prev;
	struct node *curr;
	prev=head;
	curr=prev->next;
	int cnt=1;
	int k;
	k=length(head);
	if(k<pos)
	{
		printf("Data cant be deleted, pick a different index");
	}
	else
	{
		while(cnt<pos)
		{
			cnt++;
			prev=curr;
			curr=curr->next;
		}
		prev->next=curr->next;
		curr->next=NULL;
		free(curr);
	}
}

struct node* concatination(struct node *head1,struct node *head2)
{
	struct node *p;
	
	if(head1->next==NULL)
	return head2;
	
	if(head2->next==NULL)
	return head1;
	
	p=head1->next;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=head2->next;
	head2->next=NULL;
	free(head2);
	return head1;
}

int main()
{
	int n,*head1;
	
	int ch,w;
	struct node *head;
	head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	do
	{
		printf("\nPick an option:\n 1.Create List\n 2.Display List\n 3.Length of List\n 4.Insert an Element\n 5.Delete an Element\n 6.Concat\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			{
				create(head);
				break;
			}
			case 2:
			{
				display(head);
				break;
			}
			case 3:
			{
				int l=length(head);
				printf("\nThe length of the linked list is -\n %d\n",l);
				break;
			}
			
			case 4:
			{
				printf("\nPick an index where the new element should go:\n");
				scanf("%d",&n);
				insert(head,n);
				printf("\nNew list:\n");
				display(head);
				break;
			}

			case 5:
			{
				printf("\nInput index to delete:\n");
				int n;
				scanf("%d",&n);
				delete(head,n);
				break;
			}

			case 6:
			{
				struct node *headnew;
				headnew=(struct node*)malloc(sizeof(struct node));
				headnew->next=NULL;
				create(head1);
				headnew=concatination(head,head1);
				printf("\nNew List:\n ");
				display(headnew);
			}
			
			default:
			{
				printf("\nTry Again!\n");
				break;
			}
		}
		printf("\n Go again \n1.yes 2. no\n");
		scanf("%d",&w);
	}
	while(w==1);
}