#include<stdio.h>

#include<stdlib.h>

#include<math.h>

struct node

{

    int exp;

    double coeff;

    struct node *next;

};

void create(struct node *head)

{

    struct node *temp;

    struct node *curr;

    temp=head;

    int i=1;

    while (i==1)

    {

        curr=(struct node *)malloc(sizeof(struct node));

        printf("Enter the coeff ");

        scanf("%lf",&curr->coeff);

        printf("Enter the exp of x ");

        scanf("%d",&curr->exp);

        curr->next=head;

        temp->next=curr;

        temp=temp->next;

        printf("Do you wanna continue 1)yes 2)no");

        scanf("%d",&i);

    }

}

void display(struct node *head)

{

    struct node *curr;

    curr=head->next;

    printf("%p \n",head);

    while(curr!=head)

    {

        printf("\n %f x^ %d",curr->coeff,curr->exp);

        curr=curr->next;

    }

}

void add(struct node *head, struct node *head1)

{

            struct node *temp;

            struct node *t;

            struct node *t1;

            struct node *t2;

            struct node *head2;

            head2=(struct node*)malloc(sizeof(struct node));

            head2->next=head;

            head2->exp=-1;

            t2=head2;

            t=head->next;

            t1=head1->next;

            while(t->exp!=-1||t1->exp!=-1)

            {

                        if(t->exp==t1->exp)

                        {

            temp=(struct node *)malloc(sizeof(struct node));

            temp->coeff=t->coeff+t1->coeff;

            temp->exp=t->exp;

            t2->next=temp;

            temp->next=head2;

            t2=temp;

            t=t->next;

            t1=t1->next;

                        }

                        else if((t->exp)<(t1->exp))

                        {

                            temp=(struct node*)malloc(sizeof(struct node));

                            temp->coeff=t1->coeff;

                            temp->exp=t1->exp;

                            t2->next=temp;

                            temp->next=head2;

                            t2=temp;

                            t1=t1->next;

                        }

                        else

                        {

                            temp=(struct node*)malloc(sizeof(struct node));

                            temp->coeff=t->coeff;

                            temp->exp=t->exp;

                            t2->next=temp;

                            temp->next=head2;

                            t2=temp;

                            t=t->next;

                        }

            }

            display(head2);

}

void evaluate(struct node *head,int x)

{

            int sum=0;

            struct node *curr;

            curr=head->next;

            while(curr!=head)

            {

                        sum=sum+(curr->coeff *(pow(x,curr->exp)));

                        curr=curr->next;

            }

            printf("The value of polynomial is = %d",sum);

}

int main()

{

            int ch,w,x;

            struct node *head;

            head=(struct node*)malloc(sizeof(struct node));

            head->next=NULL;

            head->exp=-1;

            struct node *head1;

            head1=(struct node*)malloc(sizeof(struct node));

            head1->next=NULL;

            head1->exp=-1;

            struct node *headf;

            headf=(struct node*)malloc(sizeof(struct node));

            headf->next=NULL;

            do

            {

            printf("Enter choice \n1.Create\n2.Display\n3.Add\n4.Evaluate");

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

                            printf("Enter the second linklist \n");

                                    create(head1);

                                    add(head,head1);

                                    break;

                        }

                        case 4:

                        {

                                    printf("Enter the value of x");

                                    scanf("%d",&x);

                                    evaluate(head,x);

                                    break;

                        }

                        default:

                        {

                                    printf("Wrong choice");

                                    break;

                        }

            }

            printf("\n Go again 1.yes 2. no");

            scanf("%d",&w);

            }

            while(w==1);

            return 0;

}
