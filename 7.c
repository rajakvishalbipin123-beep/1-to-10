#include <stdio.h> 
#include <stdlib.h> 
struct queue { 
int no; 
struct queue *next; 
}; 
struct queue *front = NULL, *rear = NULL; 
 
// Insert at rear 
void insertrear(int val) { 
    struct queue *q = (struct queue *)malloc(sizeof(struct queue)); 
    q->no = val; 
    q->next = NULL; 
 
    if (front == NULL) { 
        front = rear = q; 
    } else { 
        rear->next = q; 
        rear = q; 
    } 
} 
 
// Insert at front 
void insertfront(int val) { 
    struct queue *q = (struct queue *)malloc(sizeof(struct queue)); 
    q->no = val; 
    q->next = NULL; 
 
    if (front == NULL) { 
        front = rear = q; 
    } else { 
        q->next = front; 
        front = q; 
    } 
} 
 
// Delete from front 
int deletefront() { 
    if (front == NULL) { 
        printf("\nQueue is Empty"); 
        return -999; 
    } 
 
    struct queue *q = front; 
    int val = q->no; 
 
    if (front == rear) { 
        front = rear = NULL; 
    } else { 
        front = front->next; 
    } 
 
    free(q); 
    return val; 
} 
 
// Delete from rear 
int deleterear() { 
    if (front == NULL) { 
        printf("\nQueue is Empty"); 
        return -999; 
    } 
 
    int val = rear->no; 
 
    if (front == rear) { 
        free(front); 
        front = rear = NULL; 
    } else { 
        struct queue *q = front; 
 
        while (q->next != rear) 
            q = q->next; 
 
        free(rear); 
        rear = q; 
        rear->next = NULL; 
    } 
 
    return val; 
} 
 
// Display 
void show() { 
    struct queue *q = front; 
 
    if (q == NULL) { 
        printf("\nQueue is Empty"); 
        return; 
    } 
 
    printf("\nDeque elements: "); 
    while (q != NULL) { 
        printf("%d -> ", q->no); 
        q = q->next; 
    } 
    printf("NULL"); 
} 
 
int main() { 
    int ch, n; 
 
�
�    printf("Program by Vishal Rajak\n");   //  Your name added here 
 
    do { 
        printf("\n\n1. Insert Front"); 
        printf("\n2. Insert Rear"); 
        printf("\n3. Delete Front"); 
        printf("\n4. Delete Rear"); 
        printf("\n5. Display"); 
        printf("\n0. Exit"); 
        printf("\nEnter choice: "); 
        scanf("%d", &ch); 
 
        switch (ch) { 
        case 1: 
            printf("Enter number: "); 
            scanf("%d", &n); 
            insertfront(n); 
            break; 
 
        case 2: 
            printf("Enter number: "); 
            scanf("%d", &n); 
            insertrear(n); 
            break; 
 
        case 3: 
            n = deletefront(); 
            if (n != -999) 
                printf("%d deleted from front", n); 
            break; 
 
        case 4: 
            n = deleterear(); 
            if (n != -999) 
                printf("%d deleted from rear", n); 
            break; 
 
        case 5: 
            show(); 
            break; 
 
        case 0: 
            printf("Exiting..."); 
            break; 
 
        default: 
            printf("Invalid choice"); 
        } 
 
    } while (ch != 0); 
 
    return 0; 
}
