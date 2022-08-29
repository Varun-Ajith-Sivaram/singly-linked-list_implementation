#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list
{
    int info;
    struct linked_list *link;
}LIST;

LIST *head=NULL,*new,*temp,*ptr,*prev,*next;

struct linked_list *allocate_node();
int get_insert_element();
int get_delete_element();
void display();
void insert_beginning();
void insert_end();
void insert_after();
void insert_before();
void delete_beginning();
void delete_element();
void delete_end();
void delete_before();
void delete_after();
void reverse();
void sort_increasing();
void sort_decreasing();
struct linked_list *search(int);

int count = 0;

void main()
{
    int element,ch;
    
    printf("\tImplementation of different operations in Singly Linked List(SLL)\n");
    
    do{
        printf("\n   SLL Operations Available: \n\n");
        printf("\t1.Insert\n");
        printf("\t2.Delete\n");
        printf("\t3.Search\n");
        printf("\t4.Sort\n");
        printf("\t5.Reverse\n");
        printf("\t6.Display\n");
        printf("\t7.Exit\n");
        
        printf("\n   Enter the choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: 
                    do{
                        printf("\n\tInsertion Options: \n\n");
                        printf("\t   1.Insert at beginning\n");
                        printf("\t   2.Insert at end\n");
                        printf("\t   3.Insert before a particular element\n");
                        printf("\t   4.Insert after a particular element\n");
                        printf("\t   5.Go back\n");
        
                        printf("\n\tEnter the choice: ");
                        scanf("%d",&ch);
                        
                        switch(ch)
                        {
                            case 1: insert_beginning();
                                    break;
                                    
                            case 2: insert_end();
                                    break;
                                    
                            case 3: insert_before();
                                    break;
                                    
                            case 4: insert_after();
                                    break;
                                    
                            case 5: break;
                            
                            default: printf("\n\t--> Invalid choice, Enter a valid choice\n");
                        }
                    }while(ch != 5);
            
                    break;
                    
            case 2: 
                    do{
                        printf("\n\tDeletion Options: \n\n");
                        printf("\t   1.Delete from beginning\n");
                        printf("\t   2.Delete a particular element\n");
                        printf("\t   3.Delete from end\n");
                        printf("\t   4.Delete before a particular element\n");
                        printf("\t   5.Delete after a particular element\n");
                        printf("\t   6.Go back\n");
        
                        printf("\n\tEnter the choice: ");
                        scanf("%d",&ch);
                        
                        switch(ch)
                        {
                            case 1: delete_beginning();
                                    break;
                                    
                            case 2: delete_element();
                                    break;
                            
                            case 3: delete_end();
                                    break;
                                    
                            case 4: delete_before();
                                    break;
                                    
                            case 5: delete_after();
                                    break;
                                    
                            case 6: break;
                            
                            default: printf("\n\t--> Invalid choice, Enter a valid choice\n");
                        }
                    }while(ch != 6);
            
                    break;
                    
            case 3: printf("\n   Enter the element to be searched: ");
                    scanf("%d",&element);
                    ptr = search(element);
                    
                    if(ptr == NULL)
                    {
                        printf("\n   --> Element %d not found in list\n",element);
                    }
                    
                    else
                    {
                        printf("\n   --> Element %d found in list\n",element);
                    }
                    
                    break;
                    
            case 4: 
                    do{
                        printf("\n\tSort Options: \n\n");
                        printf("\t   1.Increasing order\n");
                        printf("\t   2.Decreasing order\n");
                        printf("\t   3.Go back\n");
        
                        printf("\n\tEnter the choice: ");
                        scanf("%d",&ch);
                        
                        switch(ch)
                        {
                            case 1: 
                                    sort_increasing();
                                    break;
                                    
                            case 2: sort_decreasing();
                                    break;
                                    
                            case 3: break;
                            
                            default: printf("\n\t--> Invalid choice, Enter a valid choice\n");
                        }
                    }while(ch != 3);
                    
                    break;
                    
            case 5: reverse();
                    printf("\n   --> Linked list is reversed\n");
                    break;
                    
            case 6: display();
                    break;
                    
            case 7: printf("\n   --> Exited from program\n");
                    break;
                    
            default: printf("\n   --> Invalid choice, Enter a valid choice\n");
        }
    }while(ch != 7);
}

struct linked_list *allocate_node()
{
    new = (struct linked_list *)malloc(sizeof(struct linked_list));
    
    if(new == NULL)
    {
        printf("\n   --> Memory allocation for a new node failed!!\n");
        exit(1);
    }
    
    else
    {
        return(new);
    }
}

int get_insert_element()
{
    int item;
    
    printf("\n\tEnter the element to be inserted: ");
    scanf("%d",&item);
    
    return(item);
}

int get_delete_element()
{
    int item;
    
    printf("\n\tEnter the element to be deleted: ");
    scanf("%d",&item);
    
    return(item);
}

void insert_beginning()
{
    int item = get_insert_element();
    
    new = allocate_node(new);
    new->info = item;
    new->link = head;
    head = new;
    count++;
    printf("\n\t--> Element %d is inserted into list\n",item);
}

void insert_end()
{
    int item = get_insert_element();
    
    new = allocate_node(new);
    new->info = item;
    new->link = NULL;
    
    if(head == NULL)
    {
        head = new;
    }
    
    else
    {
        temp = head;
        
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        
        temp->link = new;
    }
    
    count++;
    printf("\n\t--> Element %d is inserted into list\n",item);
}

void insert_before()
{
    int element,item;
    
    printf("\n\tEnter the element before which insertion is to be performed: ");
    scanf("%d",&element);
    
    ptr = search(element);
    
    if(ptr == NULL)
    {
        printf("\n\t--> Element %d not found in list\n",element);
    }
    
    else
    {
        item = get_insert_element();
        
        new = allocate_node(new);
        new->info = item;
        
        if(prev == NULL)
        {
            new->link = head;
            head = new;
        }
        
        else
        {
            new->link = ptr;
            prev->link = new;
        }
        
        count++;
        printf("\n\t--> Element %d is inserted into list\n",item);
    }
}

void insert_after()
{
    int element,item;
    
    printf("\n\tEnter the element after which insertion is to be performed: ");
    scanf("%d",&element);
    
    ptr = search(element);
    
    if(ptr == NULL)
    {
        printf("\n\t--> Element %d not found in list\n",element);
    }
    
    else
    {
        item = get_insert_element();
        
        new = allocate_node(new);
        new->info = item;
        new->link = ptr->link;
        ptr->link = new;
        
        count++;
        printf("\n\t--> Element %d is inserted into list\n",item);
    }
}

void delete_beginning()
{
    if(head == NULL)
    {
        printf("\n\t--> Linked list is empty\n");
    }
    
    else
    {
        temp = head;
        head = head->link;
        int item = temp->info;
        free(temp);
        
        count--;
        printf("\n\t--> Element %d is deleted from list\n",item);
    }
}

void delete_end()
{
    if(head == NULL)
    {
        printf("\n\t--> Linked list is empty\n");
    }
    
    else
    {
        int item;
        temp = head;
        
        if(temp->link == NULL)
        {
            head = NULL;
            item = temp->info;
            free(temp);
        }
        
        else
        {
            prev = NULL;
            
            while(temp->link != NULL)
            {
                prev = temp;
                temp = temp->link;
            }
            
            item = temp->info;
            prev->link = NULL;
            free(temp);
        }
        
        count--;
        printf("\n\t--> Element %d is deleted from list\n",item);
    }
}

void delete_element()
{
    if(head == NULL)
    {
        printf("\n\t--> Linked list is empty\n");
    }
    
    else
    {
        int item = get_delete_element();
        ptr = search(item);
        
        if(ptr == NULL)
        {
            printf("\n\t--> Element %d not found in list\n",item);
        }
        
        else
        {
            if(head == ptr)
            {
                head = head->link;
                free(ptr);
            }
            
            else
            {
                prev->link = ptr->link;
                free(ptr);
            }
            
            count--;
            printf("\n\t--> Element %d is deleted from list\n",item);
        }
    }
}

void delete_before()
{
    if(head == NULL)
    {
        printf("\n\t--> Linked list is empty\n");
    }
    
    else
    {
        int item,element;
        
        printf("\n\tEnter the element before which deletion is to be performed: ");
        scanf("%d",&element);
    
        ptr = search(element);
        
        if(ptr == NULL)
        {
            printf("\n\t--> Element %d not found in list\n",element);
        }
        
        else if(ptr == head)
        {
            printf("\n\t--> Deletion not possible, %d is the starting element in list\n",element);
        }
        
        else if(head->link == ptr)
        {
            temp = head;
            item = temp->info;
            head = ptr;
            free(temp);
            
            count--;
            printf("\n\t--> Element %d is deleted from list\n",item);
        }
        
        else
        {
            reverse();
            
            temp = ptr->link;
            item = temp->info;
            ptr->link = temp->link;
            free(temp);
            
            count--;
            printf("\n\t--> Element %d is deleted from list\n",item);
            
            reverse();
            
        }
    }
}

void delete_after()
{
    if(head == NULL)
    {
        printf("\n\t--> Linked list is empty\n");
    }
    
    else
    {
        int item,element;
        
        printf("\n\tEnter the element after which deletion is to be performed: ");
        scanf("%d",&element);
    
        ptr = search(element);
        
        if(ptr == NULL)
        {
            printf("\n\t--> Element %d not found in list\n",element);
        }
        
        else if(ptr->link == NULL)
        {
            printf("\n\t--> Deletion not possible, %d is the last element in list\n",element);
        }
        
        else
        {
            temp = ptr->link;
            item = temp->info;
            ptr->link = temp->link;
            free(temp);
            
            count--;
            printf("\n\t--> Element %d is deleted from list\n",item);
        }
    }
}

struct linked_list *search(int element)
{
    temp = head;
    prev = NULL;
    
    while(temp != NULL && temp->info != element)
    {
        prev = temp;
        temp = temp->link;
    }
    
    return(temp);
}

void reverse()
{
    if(head == NULL)
    {
        printf("\n   --> Linked list is empty\n");
    }
    
    else
    {
        prev = head;
        temp = head->link;
        next = NULL;
        
        while(temp != NULL)
        {
            next = temp->link;
            temp->link = prev;
            prev = temp;
            temp = next;
        }
        
        head->link = NULL;
        head = prev;
    }
}

void sort_increasing()
{
    if(head == NULL)
    {
        printf("\n\t--> Linked list is empty\n");
    }
    
    else if(head->link == NULL)
    {
        printf("\n\t--> Linked list is sorted\n");
    }
    
    else
    {
        temp = head;
        
        while(temp != NULL)
        {
            next = temp->link;
        
            while(next != NULL)
            {
                if(temp->info > next->info)
                {
                    int data = temp->info;
                    temp->info = next->info;
                    next->info = data;
                }
            
                next = next->link;
            }
        
            temp = temp->link;
        }
        
        printf("\n\t--> Linked list is sorted\n");
    }
}

void sort_decreasing()
{
    if(head == NULL)
    {
        printf("\n\t--> Linked list is empty\n");
    }
    
    else if(head->link == NULL)
    {
        printf("\n\t--> Linked list is sorted\n");
    }
    
    else
    {
        temp = head;
        
        while(temp != NULL)
        {
            next = temp->link;
        
            while(next != NULL)
            {
                if(temp->info < next->info)
                {
                    int data = temp->info;
                    temp->info = next->info;
                    next->info = data;
                }
            
                next = next->link;
            }
        
            temp = temp->link;
        }
        
        printf("\n\t--> Linked list is sorted\n");
    }
}

void display()
{
    temp = head;
    
    if(temp == NULL)
    {
        printf("\n   --> Linked list is empty\n");
    }
    
    else
    {
        printf("\n   Number of elements in the list: %d\n",count);
        printf("\n   Elements in the list:  "); 
        
        while(temp->link!=NULL)
        {
            printf("%d --> ",temp->info);
            temp=temp->link;
        }
        printf("%d\n\n",temp->info);
    }
}