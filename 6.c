#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create_11(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
int main(int argc, char *argv[])
{
    int option;
    printf("\n My name is Vishal");
    do
    {
        printf("\n\n *****main menu*****");
        printf("\n 1. create a list");
        printf("\n 2. display the list");
        printf("\n 3. add a node at the beginning");
        printf("\n 4. add a node at the end");
        printf("\n 5. add a node before a given node");
        printf("\n 6. add a node after a given node");
        printf("\n 7. delete a node from the beginning");
        printf("\n 8. delete a node from end");
        printf("\n 9. delete a node after a given node");
        printf("\n 10. EXIT");
        printf("\n\n Enter your opinion:");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                start = create_11(start);
                printf("\n LINKED LIST CREATED");
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                start = insert_beg(start);
                break;
            case 4:
                start = insert_end(start);
                break;
            case 5:
                start = insert_before(start);
                break;
            case 6:
                start = insert_after(start);
                break;
            case 7:
                start = delete_beg(start);
                break;
            case 8:
                start = delete_end(start);
                break;
            case 9:
                start = delete_after(start);
                break;
        }
    } while (option != 10);
    return 0;
}
struct node *create_11(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;
        if (start == NULL)
        {
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
        }
        printf("\nEnter the data: ");
        scanf("%d", &num);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if(ptr == NULL)
    {
        printf("\nList is empty");
        return start;
    }
    printf("\nLinked List:");
    while(ptr != NULL)
    {
        printf(" %d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data:");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    printf("\nData inserted.");
    return start;
}
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data:");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    if(start == NULL)
    {
        start = new_node;
        printf("\nData inserted.");
        return start;
    }
    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    printf("\nData inserted.");
    return start;
}
struct node *insert_before(struct node *start)
{
    struct node *ptr, *new_node, *preptr;
    int num, val;
    printf("\n Enter the data:");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted:");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    if(start == NULL)
        return start;
    if(start->data == val)
    {
        new_node->next = start;
        start = new_node;
        printf("\nData inserted.");
        return start;
    }
    ptr = start;
    while(ptr != NULL && ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if(ptr == NULL)
    {
        printf("\nValue not found");
        return start;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    printf("\nData inserted.");
    return start;
}
struct node *insert_after(struct node *start)
{
    struct node *ptr, *new_node;
    int num, val;
    printf("\n Enter the data:");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted:");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr != NULL && ptr->data != val)
        ptr = ptr->next;
    if(ptr == NULL)
    {
        printf("\nValue not found");
        return start;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    printf("\nData inserted.");
    return start;
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    if(start == NULL)
    {
        printf("\nList empty");
        return start;
    }
    ptr = start;
    printf("\nData deleted successfully");
    printf("\nDeleted node: %d", ptr->data);
    start = start->next;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    if(start == NULL)
    {
        printf("\nList empty");
        return start;
    }
    if(start->next == NULL)
    {
        printf("\nData deleted successfully");
        printf("\nDeleted node: %d", start->data);
        free(start);
        start = NULL;
        return start;
    }
    ptr = start;
    while(ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    printf("\nData deleted successfully");
    printf("\nDeleted node: %d", ptr->data);
    preptr->next = NULL;
    free(ptr);
    return start;
}
struct node *delete_after(struct node *start)
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the value after which the node has to deleted:");
    scanf("%d", &val);
    ptr = start;
    while(ptr != NULL && ptr->data != val)
        ptr = ptr->next;
    if(ptr == NULL || ptr->next == NULL)
    {
        printf("\nDeletion not possible");
        return start;
    }
    temp = ptr->next;
    printf("\nData deleted successfully");
    printf("\nDeleted node: %d", temp->data);
    ptr->next = temp->next;
    free(temp);
    return start;
}
