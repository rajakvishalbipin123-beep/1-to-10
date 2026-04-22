#include <stdio.h> 
#define MAX 5 
int stack[MAX]; 
int top = -1; 
void push(); 
void pop(); 
void peek(); 
void display(); 
int main() { 
int choice; 
char name[50];   // Variable to store name 
    printf("Enter your name: "); 
    scanf("%s", name);   // Taking name input 
 
    printf("\nWelcome %s!\n", name); 
 
    while (1) { 
        printf("\n1. Push"); 
        printf("\n2. Pop"); 
        printf("\n3. Peek"); 
        printf("\n4. Display"); 
        printf("\n5. Exit"); 
        printf("\nEnter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: push(); break; 
            case 2: pop(); break; 
            case 3: peek(); break; 
            case 4: display(); break; 
            case 5:  
                printf("\nThank you %s!\n", name); 
                return 0; 
            default: printf("Invalid choice\n"); 
        } 
    } 
} 
 
void push() { 
    int value; 
    if (top == MAX - 1) { 
        printf("Stack Overflow\n"); 
    } else { 
        printf("Enter value: "); 
        scanf("%d", &value); 
        top++; 
        stack[top] = value; 
        printf("Pushed: %d\n", value); 
    } 
} 
 
void pop() { 
    if (top == -1) { 
        printf("Stack Underflow\n"); 
    } else { 
        printf("Popped: %d\n", stack[top]); 
        top--; 
    } 
} 
 
void peek() { 
    if (top == -1) { 
        printf("Stack is empty\n"); 
    } else { 
        printf("Top element: %d\n", stack[top]); 
    } 
} 
 
void display() { 
    int i; 
    if (top == -1) { 
        printf("Stack is empty\n"); 
    } else { 
        printf("Stack elements:\n"); 
        for (i = top; i >= 0; i--) { 
printf("%d\n", stack[i]); 
} 
} 
}
