#include <stdio.h>
#include<stdlib.h>

struct node {
    char data[100];
    struct node *next,*prev;
};

typedef struct node cdll;
cdll * head = NULL;
void insert(char e[]) {
    cdll *t;
    if(head == NULL) {
        head = (cdll *)malloc(sizeof(cdll));
        strcpy(head->data, e);
        head->next = head;
        head->prev = head;
    }
    else {
        for(t = head;t->next != head;t = t->next);
        t->next = (cdll*)malloc(sizeof(cdll));
        strcpy(t->next->data, e);		
        t->next->next = head;
        t->next->prev = t;
        head->prev = t->next;
    }
}
void disp() {
    cdll *t;
    if(head == NULL) {
        printf("Empty Linked List");
    }
    else {
        t = head;
        do {
            puts(t->data);
            t = t->next;
        } while(t!=head);
    }
}
void delete(int e) {
   cdll *t;
    if(head == NULL)  {
        printf("Empty Linked list");

    }
    else if(head->data == e && head->next == head) {
        head = NULL;
    }
    else if(head->data == e) {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
    }
    else  {
        t = head->next;
        while(t !=head && t->data != e) {
            t = t->next;
        }
        if(t == head)
            printf("Not found");
        else {
            
            t->next->prev = t->prev;
            t->prev->next = t->next;
        }
    }
}

int main()
{
	char e[100];
	int ch;
	printf("\nCIRCULAR DOUBLY LINKED LIST");
	printf("\n---------------------------");
	do{
	printf("\n1.Insert\n2.Display\n3.Exit\nChoose your option:");
	scanf("%d", &ch);
	getchar();
	switch(ch){
		case 1:	printf("\nEnter name:");
				gets(e);
		    	insert(e);
	    		break;    		
    	case 2:	disp();
    			break;
    	case 3:exit(1);
			break;	
	}
    }while(1);
    return 0;
}
        

