#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct phoneBook{
    long long number;
    char name[25];
    char email[25];
    struct phoneBook *next;
};
char newName[25];
char Email[25];
long long mNumber=0;

struct phoneBook* createRecord();
void insert();
void delete();
void search();
void searching(int);
void deletion(struct phoneBook*,struct phoneBook*);
void printRecords();

struct phoneBook *head=NULL,*back=NULL;

int main(){
    printf("--------Welcome to phoneBook program using Linked list----------\n");
    short k=0;
    while(k==0){
        printf("You have 4 options : 1. Add Record\t 2. Delete record\t 3. Search Record\t 4. Print Record\t 5.Exit : ");
        int choice =-1;
        scanf("%d",&choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            insert();
            break;

        case 2:
            delete();
            break;

        case 3:
            search();
            break;
        
        case 4:
            printRecords();
            break;

        case 5:
            k=1;
            break;
        
        default:
            break;
        }
    }
     
return 0;
}

void printRecords(){
    struct phoneBook* newnode=head;
    int count=1;
    while(newnode!=NULL){
        printf("Record Number: %d\n",count);
        printf("----Name : %s----\n",newnode->name);
        printf("----Number : %lld----\n",newnode->number);
        printf("----Email : %s----\n",newnode->email);
        printf("\n");
        newnode=newnode->next;
        count++;
    }
}
struct phoneBook* createRecord(){
    struct phoneBook * newNode=(struct phoneBook*)malloc(sizeof(struct phoneBook));
    printf("Enter name: ");
    scanf(" %[^\n]s",newNode->name);
    printf("Enter Email: ");
    scanf("%s",newNode->email);
    printf("Enter phoneNumber: ");
    scanf("%lld",&newNode->number);
    printf("\n");
    newNode->next=NULL;
    return newNode;
}

void insert(){
    if(head==NULL){
        head=createRecord();
        back=head;
        return;
    }
    struct phoneBook * newNode=createRecord();
    printf("Succesfully Inserted\n");
    back->next=newNode;
    back=newNode;
}

void searching(int m){
    if(head==NULL){
        printf("Records are empty\n");
        return;
    }
    printf("Using which data you want to operate\n");
    printf(" 1. Name\t 2. Email \t 3. Number  :");
    int choice;
    scanf("%d",&choice);
    printf("\n");
    struct phoneBook * newnode=head,*vemp=head;
    switch (choice){
    case 1:
        printf("Enter name you want to operate :");
        scanf(" %[^\n]s",newName);
        printf("\n");
        if(newnode->next==NULL){
            short y=strcmp(newnode->name,newName);
            if(y==0){
                printf("Record exists\n");
                if(m==1) {
                head=NULL;
                return;
            }
                return;
            }
                printf("Record doesn't exist\n");
                return;
        }
        short y=strcmp(newnode->name,newName);
        if(y==0){
            printf("Record exist\n");
            if(m==1){
                newnode=newnode->next;
                return;
            }
            return;
        }
        newnode=newnode->next;
        while(newnode!=NULL){
            if(newnode->name==newName){
                printf("Record is present\n");
                if(m==1) deletion(vemp,newnode);
                return;
            }
            newnode=newnode->next;
            vemp=vemp->next;

        }
        printf("Record is not there \n");
        return;
        break;

    case 2:
        printf("Enter Email Record you want to operate :");
        scanf("%s",Email);
        printf("\n");
        if(newnode->next==NULL){
            short z=strcmp(newnode->email,Email);
            if(z==0){
                printf("Record exists\n");
                if(m==1) {
                head=NULL;
                return;
            }
            return;
            }
                printf("Record doesn't exist\n"); 
                return;
        }
        short z=strcmp(newnode->email,Email);
        if(z==0){
            printf("Record exist\n");
            if(m==1){
                newnode=newnode->next;
                return;
            }
            return;
        }
        newnode=newnode->next;
        while(newnode!=NULL){
            short z=strcmp(newnode->email,Email);
            if(z==0){
                printf("Record is present\n");
                if(m==1) deletion(vemp,newnode);
                return;
            }
            newnode=newnode->next;
            vemp=vemp->next;

        }
        printf("Record is not there \n");
        return;
        break;

    case 3:
        printf("Enter Number record which you want to operate: ");
        scanf("%lld",&mNumber);
        printf("\n");
        if(newnode->next==NULL){
            if(mNumber==newnode->number){
                printf("Record exists\n");
                if(m==1) {
                head=NULL;
                return;
            }
            return;
            }
                printf("Record doesn't exist\n");
                return;
        }
        if(newnode->number==mNumber){
            printf("Record exist\n");
            if(m==1){
                newnode=newnode->next;
                return;
            }
            return;
        }
        newnode=newnode->next;
        while(newnode!=NULL){
            if(newnode->number==mNumber){
                printf("Record is present\n");
                if(m==1) deletion(vemp,newnode);
                return;
            }
            newnode=newnode->next;
            vemp=vemp->next;

        }
        printf("Record is not there \n");
        return;
        break;


    
    default:
        printf("Enter valid Input\n");
        break;
    }
    }


void deletion(struct phoneBook * temp,struct phoneBook* newNode){
    temp->next=newNode->next;
    free(newNode);
    printf("Record is successfully deleted\n");
    return;
}

void search(){
    searching(0);
}

void delete(){
        searching(1);
    // if(head==NULL){
    //     printf("Records are empty\n");
    //     return;
    // }
    // printf("Using which data you want to delete Record\n");
    // printf(" 1. Name\t 2. Email \t 3. Number  :");
    // int choice;
    // scanf("%d",&choice);
    // printf("\n");
    // switch (choice)
    // {
    // case 1:
    //     char newName[25];
    //     printf("Enter name you want to delete :");
    //     scanf(" %[^\n]s",newName);
    //     printf("\n");
    //     if(head->next==NULL){
    //         head=NULL;
    //         return;
    //     }
    //     struct phoneBook * newNode=head->next,*temp=head;
    //     while(newNode!=NULL){
    //         if(newNode->name==newName){
    //             temp->next=newNode->next;
    //             free(newNode);
    //             return;
    //         }
    //         newNode=newNode->next;
    //         temp=temp->next;

    //     }
    //     printf("Record is not there \n");
    //     return;
    //     break;

    // case 2:
    //     char Email[25];
    //     printf("Enter Email Record you want to delete :");
    //     scanf(" %[^\n]s",Email);
    //     printf("\n");
    //     if(head->next==NULL){
    //         head=NULL;
    //         return;
    //     }
    //     struct phoneBook * newNode=head->next,*temp=head;
    //     while(newNode!=NULL){
    //         if(newNode->email==Email){
    //             temp->next=newNode->next;
    //             free(newNode);
    //             return;
    //         }
    //         newNode=newNode->next;
    //         temp=temp->next;

    //     }
    //     printf("Record is not there \n");
    //     return;
    //     break;

    // case 3:
    //     long long mNumber;
    //     printf("Enter Number record which you want to delete: ");
    //     scanf("%lld",&mNumber);
    //     printf("\n");
    //     if(head->next==NULL){
    //         head=NULL;
    //         return;
    //     }
    //     struct phoneBook * newNode=head->next,*temp=head;
    //     while(newNode!=NULL){
    //         if(newNode->number==mNumber){
    //             temp->next=newNode->next;
    //             free(newNode);
    //             return;
    //         }
    //         newNode=newNode->next;
    //         temp=temp->next;

    //     }
    //     printf("Record is not there \n");
    //     return;
    //     break;


    
    // default:
    //     printf("Enter valid Input\n");
    //     break;
    // }
    }