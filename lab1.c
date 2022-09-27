#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
    struct node *last;
};

void Append(struct node** head, int data){
    if((*head) == NULL) {
        (*head) = (struct node*)malloc(sizeof(struct node));
        (*head)->data = data;
    } else {
        struct node *add = (struct node*)malloc(sizeof(struct node));
        add->data = data;

        struct node *tail = *head;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = add;
        add->last = tail;
        add->next = NULL;
    }

}

void Prepend(struct node **head, int data){
    if(head == NULL){
    	(*head) = (struct node*)malloc(sizeof(struct node));
    	(*head)->data = data;
    }else {
    	struct node *add = (struct node*)malloc(sizeof(struct node));
    	add->data = data;
    	add->next = (*head);
    	(*head)->last = add;
    	(*head) = add;
    }
}

void Reverse(struct node **head){
    if(head == NULL) {
    	printf("Add values to make reversion )) ");
    }else {
    	struct node *tail = *head;
    	while(tail->next != NULL) {
    	    tail = tail->next;
    	}
    	
    	struct node *temp = tail;
    	struct node *trans;
    	
    	while(temp != NULL){
    	    trans = temp->last;
    	    temp->last = temp->next;
    	    temp->next = trans;
    	    temp = temp->next;
    	}
    	(*head) = tail;	
    }
}

int getSize(struct node* node){    
    int size=0;

    while(node!=NULL){
        node = node->next;
        size++;
    }
    return size;
}

//function to insert after nth node
void Addvaluetoaspecificindex(struct node **head,int pos,int data)
{
    int size = getSize(*head);

    struct node* add = (struct node*)malloc(sizeof(struct node)); 
    add->data = data;
    add->next = NULL;

    if(pos < 0 || pos > size) 
        printf("This index is not right, try something else\n"); 
    else if(pos == 0){
        add->next = *head; 
        *head = add;
    }else {
        // traversam linked lists
        struct node *temp = *head; 
        
        while(--pos)
            temp = temp->next;
        
        add->next= temp->next;
        temp->next = add;
    }
}


void RemoveValue(struct node **head, int pos)
{
    if(pos <= 0){
    	printf("Adauga terog o positie valida :)) ");
    }

    struct node* temp = (*head);
    int value = 1;
    
    while(temp != NULL) {
    	if(value == pos){
    	    struct node *remove = temp;
    	    
    	    if(temp->last != NULL) {
    	    	temp->last->next = temp->next;
    	    }
    	    
    	    if(temp->next != NULL){
    	    	temp->next->last = temp->last;
    	    }
    	    
    	    if(value == 1 && temp->next == NULL) {
    	    	*head = NULL;
    	    }
    	    
    	    free(remove);
    	    break;
    	}else {
    	    value++;
    	    temp = temp->next;
    	}
    }
    
    if(value < pos) {
    	printf("This elements were not found :))");
    }
    
}

void SortedInsert(struct node** head, struct node* newNode)
{
    struct node sort;
    struct node* current = &sort;
    sort.next = *head;
 
    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }
 
    newNode->next = current->next;
    current->next = newNode;
    *head = sort.next;
}

void InsertSort(struct node **head)
{
    struct node* result = NULL;     
    struct node* current = *head;  
    struct node* next;
 
    while (current != NULL){
        next = current->next;
        SortedInsert(&result, current);
        current = next;
    }
 
    (*head) = result;
}


bool Searchforavalue(struct node* head, int value)
{
    struct node* temp = head; 
    while (temp != NULL) {
        if (temp->data == value)
            return true;
        temp = temp->next;
    }
    return false;
}

void CombineTwoLists(struct node** head, struct node** head2) {
    struct node* val = *head2;
    while (val != NULL) {
        Append(head, val->data);
        val = val->next;
    }
}

void BackwardsTraversal(struct node **head) {
    struct node *tail = *head;
    
    while (tail->next != NULL)
        tail = tail->next;
    struct node* temp = tail;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->last;
    }
    printf("\n");
}


void Showlist(struct node *head){
    struct node *temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main() {
    int number = 1;
    int element;
    int index;  
    struct node *head = NULL;
    struct node *head2 = NULL;
    int len;
    
    while(number != 12) {
        printf("- 1 Append \n");
        printf("- 2 Prepend \n");
        printf("- 3 Reverse \n");
        printf("- 4 Add value to index \n");
        printf("- 5 Remove a value at index \n");
        printf("- 6 Sort the list \n");
        printf("- 7 Search for a value \n");
        printf("- 8 Add elements for second list to combine the lists : \n");
        printf("- 9 Join two linked lists \n");
        printf("- 10 Backwards traversal \n");
        printf("- 11 Load the data structure \n");
        printf("- 12 Save data in the file \n");
        printf("\n");
        
        printf("Type a number to execute a command : ");

        


    scanf("%d", &number);

         
    switch(number){
        case 1:
            printf("\n Append and element :");
            scanf("%d", &element);
            printf("\n");
            Append(&head, element);
            printf("The list is : ");
            Showlist(head);
            printf("\n");
            break;
        case 2:
            printf("\n Prepend and element :");
            scanf("%d", &element);
            printf("\n");
            Prepend(&head, element);
            printf("The list is : ");
            Showlist(head);
            printf("\n");
            break;
        case 3:
            printf("\n Reverse the list :");
            printf("\n");
            Reverse(&head);
            printf("The reversed list is : ");
            Showlist(head);
            printf("\n");
            break;
        case 4:
            printf("\n Add a value : ");
            scanf("%d", &element);
            printf("\n");
            printf("\n Add a index : ");
            scanf("%d", &index);
            printf("\n");
            Addvaluetoaspecificindex(&head,index,element);
            printf("The list is : ");
            Showlist(head);
            printf("\n");
            break;
        case 5:
            printf("\n Enter the index of number to remove :");
	    scanf("%d", &element);
            RemoveValue(&head, element);
            Showlist(head);
            printf("\n");
            break;
        case 6:
            printf("\n Sort the list :");
            InsertSort(&head);
            Showlist(head);
            printf("\n");
            break;
        case 7:
            printf("\n What number are you looking for :");
            scanf("%d", &element);
            printf("\n");
	    printf("\n");
            Searchforavalue(head,element) ? printf("Exist \n") : printf("Not exist ! \n");
            printf("\n");
            break;
        case 8:
            printf("\n Add and element for second list :");
            scanf("%d", &element);
            printf("\n");
            Append(&head2, element);
            printf("The list is : ");
            Showlist(head2);
            printf("\n");
            break;
        case 9:
            printf("The combined lists : ");
            CombineTwoLists(&head,&head2);
            Showlist(head);
            printf("\n");
            break;
        case 10:
            printf("Backwards traversal: ");
            BackwardsTraversal(&head);
            Showlist(head);
            printf("\n");
            break;
        case 11:
            FILE* fp;
	    fp = fopen("list.txt", "r");

	    int k = 0;
	    while(!feof(fp)) {
		fscanf(fp,"%d ",&element);
		Append(&head, element);
	    }

            fclose(fp);

            printf("The list is : ");
            Showlist(head);
            printf("\n");
            break;
	case 13:
    	    fp = fopen("list.txt", "w");
    	    struct node* ptr = head;
    	    while(ptr != NULL) {
            	fprintf(fp, "%d ", ptr->data);
             	ptr = ptr->next;
    	    }	    
    	    fclose(fp);
            break;
        default:
            printf("Error! Invalid choice.");
            printf("\n");
        }
    }

    return 0;
}
