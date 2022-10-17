#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define numberOfStudents 3

struct phoneBook{
    long long phoneNumber;
    char name[25];
    char mail[25];
};

struct phoneBook students[numberOfStudents];
int main(){
    
    
    printf("--------Welcome to Phonebook Management Application---------\n");
    bool k=true;
    while(k==true){
        //printf("You can perform 4 operation\n 1->Enter the elements\n 2->Sort the record\n ");
        printf("------ 1 :for inseting elements\t 2:for sorting\t 3:for printing\t 4: for exit ------\n");
        int choice;
        scanf("%d",&choice);
       switch (choice)
       {
       case 1:
            recordInsertion(students);
        break;

        case 2:
            sorting(students);
        break;

        case 3:
            printRecord(students);
        break;

        case 4:
            k=false;
        break;
       
       default:
       printf("Enter correct choice please\n");
        break;
       }

    }
    return 0;
}

void recordInsertion(struct phoneBook students[]){
    printf("Start Entering the details\n");
    for(int i=0;i<numberOfStudents;i++){
        printf("Enter the name of student: ");
        //fgets(students[i].name,25,stdin);
        //gets(students[i].name);
        scanf(" %[^\n]s",students[i].name);
        //bool m=false;
        //while(m==false){
        printf("Enter the correct phone Number of student:");
        scanf("%lld",&students[i].phoneNumber);
        // if(students[i].phoneNumber >999999999 && students[i].phoneNumber<10000000000){
        //     m=true;
        // }
        //}
        printf("Enter the Email of the student:");
        scanf("%s",students[i].mail);
    }
}

void printRecord(struct phoneBook students[]){
    printf("\n The details of the students are as follows\n");
    for(int i=0;i<numberOfStudents;i++){
        printf("Name: %s phoneNumber: %lld Email: %s\n",students[i].name,students[i].phoneNumber,students[i].mail);
    }
}

void sorting(struct phoneBook students[]){
    printf("Press 1 for Bubble Sort: \t Press 2 for Selection sort :\t Press 3 for insertion sort\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            bubbleSort(students);
            break;
        case 2:
            selectionSort(students);
            break;
        case 3:
            insertionSort(students);
            break;
        default:
            printf("Enter correct choice\n");
            sorting(students);
            break;
    }
}

void insertionSort(struct phoneBook students[]){
    printf("\t Press 1 for sorting using phoneNumber \t Press 2 for sorting using Name \t Press 3 for using Email\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            for(int i=1;i<numberOfStudents;i++){
                int j=i-1;
                while(j>=0 && students[j].phoneNumber>students[i].phoneNumber){
                    students[j+1]=students[j];
                    j--;
                }
                students[j]=students[i];
            }
            printf("Insertion Sorting using phoneNumber is done\n");
            break;
        case 2:
            for(int i=1;i<numberOfStudents;i++){
                int j=i-1;
                
                while(j>=0 && strcmp(students[j].name,students[i].name)>=0){
                    students[j+1]=students[j];
                    j--;
                }
                students[j+1]=students[i];
            }
            printf("Insertion Sorting using name is done\n");
            break;
        case 3:
            for(int i=0;i<numberOfStudents;i++){
                for(int j=0;j<numberOfStudents;j++){
                    int m=strcmp(students[j].mail,students[i].mail);
                    if(m==1){
                        struct phoneBook n;
                        n=students[j];
                        students[j]=students[i];
                        students[i]=n;
                    }
                }
            }
            printf("selection Sorting using mail is done\n");
            break;
        default:
            printf("Enter Right choice only\n");
            bubbleSort(students);
            break;
    }
}

void selectionSort(struct phoneBook students[]){
    printf("\t Press 1 for sorting using phoneNumber \t Press 2 for sorting using Name \t Press 3 for using Email\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            for(int i=0;i<numberOfStudents;i++){
                for(int j=0;j<numberOfStudents;j++){
                    if(students[j].phoneNumber<students[i].phoneNumber){
                        struct phoneBook n;
                        n=students[j];
                        students[j]=students[j+1];
                        students[j+1]=n;
                    }
                }
            }
            printf("selection Sorting using phoneNumber is done\n");
            break;
        case 2:
            for(int i=0;i<numberOfStudents;i++){
                for(int j=0;j<numberOfStudents;j++){
                    int m=strcmp(students[j].name,students[i].name);
                    if(m==1){
                        struct phoneBook n;
                        n=students[j];
                        students[j]=students[i];
                        students[i]=n;
                    }
                }
            }
            printf("selection Sorting using name is done\n");
            break;
        case 3:
            for(int i=0;i<numberOfStudents;i++){
                for(int j=0;j<numberOfStudents;j++){
                    int m=strcmp(students[j].mail,students[i].mail);
                    if(m==1){
                        struct phoneBook n;
                        n=students[j];
                        students[j]=students[i];
                        students[i]=n;
                    }
                }
            }
            printf("selection Sorting using mail is done\n");
            break;
        default:
            printf("Enter Right choice only\n");
            bubbleSort(students);
            break;
    }
}

void bubbleSort(struct phoneBook students[]){
    printf("\t Press 1 for sorting using phoneNumber \t Press 2 for sorting using Name \t Press 3 for using Email\n");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            for(int i=0;i<numberOfStudents;i++){
                for(int j=0;j<numberOfStudents-1-i;j++){
                    if(students[j].phoneNumber>students[j+1].phoneNumber){
                        struct phoneBook n;
                        n=students[j];
                        students[j]=students[j+1];
                        students[j+1]=n;
                    }
                }
            }
            printf("Bubble Sorting using phoneNumber is done\n");
            break;
        case 2:
            for(int i=0;i<numberOfStudents;i++){
                for(int j=0;j<numberOfStudents-i-1;j++){
                    int m=strcmp(students[j].name,students[j+1].name);
                    if(m==1){
                        struct phoneBook n;
                        n=students[j];
                        students[j]=students[j+1];
                        students[j+1]=n;
                    }
                }
            }
            printf("Bubble Sorting using name is done\n");
            break;
        case 3:
            for(int i=0;i<numberOfStudents;i++){
                for(int j=0;j<numberOfStudents-i-1;j++){
                    int m=strcmp(students[j].mail,students[j+1].mail);
                    if(m==1){
                        struct phoneBook n;
                        n=students[j];
                        students[j]=students[j+1];
                        students[j+1]=n;
                    }
                }
            }
            printf("Bubble Sorting using mail is done\n");
            break;
        default:
            printf("Enter Right choice only\n");
            bubbleSort(students);
            break;
    }
}
