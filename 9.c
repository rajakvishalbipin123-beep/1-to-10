#include <stdio.h> 
#include <stdlib.h> 
struct node 
{ 
int data; 
struct node *left; 
struct node *right; 
}; 
struct node *tree; 
void create_tree(struct node *); 
struct node *insertElement(struct node *, int); 
void preorderTraversal(struct node *); 
void inorderTraversal(struct node *); 
void postorderTraversal(struct node *); 
struct node *findSmallestElement(struct node *); 
struct node *findLargestElement(struct node *); 
struct node *deleteElement(struct node *, int); 
struct node *mirrorImage(struct node *); 
int totalNodes(struct node *); 
int totalExternalNodes(struct node *); 
int totalInternalNodes(struct node *); 
int Height(struct node *); 
struct node *deleteTree(struct node *); 
int main() 
{  
    printf("My name is VISHAL RAJAK\n"); 
    int option, val; 
    struct node *ptr; 
 
    tree = NULL;    
 
    do 
    { 
        printf("\n ******MAIN MENU****** \n"); 
        printf("\n 1. Insert Element"); 
        printf("\n 2. Preorder Traversal"); 
        printf("\n 3. Inorder Traversal"); 
        printf("\n 4. Postorder Traversal"); 
        printf("\n 5. Find the smallest element"); 
        printf("\n 6. Find the largest element"); 
        printf("\n 7. Delete an element"); 
        printf("\n 8. Count total nodes"); 
        printf("\n 9. Count external nodes"); 
        printf("\n 10. Count internal nodes"); 
        printf("\n 11. Height of tree"); 
        printf("\n 12. Mirror image"); 
        printf("\n 13. Delete tree"); 
        printf("\n 14. Exit"); 
 
        printf("\n\n Enter your option : "); 
        scanf("%d", &option); 
 
        switch(option) 
        { 
            case 1: 
                printf("\n Enter value: "); 
                scanf("%d", &val); 
                tree = insertElement(tree, val); 
                break; 
 
            case 2: 
                preorderTraversal(tree); 
                break; 
 
            case 3: 
                inorderTraversal(tree); 
                break; 
 
            case 4: 
                postorderTraversal(tree); 
                break; 
 
            case 5: 
                ptr = findSmallestElement(tree); 
                if(ptr) 
                    printf("\n Smallest = %d", ptr->data); 
                break; 
 
            case 6: 
                ptr = findLargestElement(tree); 
                if(ptr) 
                    printf("\n Largest = %d", ptr->data); 
                break; 
 
            case 7: 
                printf("\n Enter value to delete: "); 
                scanf("%d", &val); 
                tree = deleteElement(tree, val); 
                break; 
 
            case 8: 
                printf("\n Total nodes = %d", totalNodes(tree)); 
                break; 
 
            case 9: 
                printf("\n External nodes = %d", totalExternalNodes(tree)); 
                break; 
 
            case 10: 
                printf("\n Internal nodes = %d", totalInternalNodes(tree)); 
                break; 
 
            case 11: 
                printf("\n Height = %d", Height(tree)); 
                break; 
 
            case 12: 
                tree = mirrorImage(tree); 
                break; 
 
            case 13: 
                tree = deleteTree(tree); 
                break; 
        } 
 
    } while(option != 14); 
 
    return 0; 
} 
 
struct node *insertElement(struct node *tree, int val) 
{ 
    struct node *ptr, *nodeptr, *parentptr; 
 
    ptr = (struct node*)malloc(sizeof(struct node)); 
    ptr->data = val; 
    ptr->left = NULL; 
    ptr->right = NULL; 
 
    if(tree == NULL) 
        return ptr; 
 
    parentptr = NULL; 
    nodeptr = tree; 
 
    while(nodeptr != NULL) 
    { 
        parentptr = nodeptr; 
        if(val < nodeptr->data) 
            nodeptr = nodeptr->left; 
        else 
            nodeptr = nodeptr->right; 
    } 
 
    if(val < parentptr->data) 
        parentptr->left = ptr; 
    else 
        parentptr->right = ptr; 
 
    return tree; 
} 
 
void preorderTraversal(struct node *tree) 
{ 
    if(tree != NULL) 
    { 
        printf("%d ", tree->data); 
        preorderTraversal(tree->left); 
        preorderTraversal(tree->right); 
    } 
} 
 
void inorderTraversal(struct node *tree) 
{ 
    if(tree != NULL) 
    { 
        inorderTraversal(tree->left); 
        printf("%d ", tree->data); 
        inorderTraversal(tree->right); 
    } 
} 
 
void postorderTraversal(struct node *tree) 
{ 
    if(tree != NULL) 
    { 
        postorderTraversal(tree->left); 
        postorderTraversal(tree->right); 
        printf("%d ", tree->data); 
    } 
} 
 
struct node *findSmallestElement(struct node *tree) 
{ 
    if(tree == NULL || tree->left == NULL) 
        return tree; 
    return findSmallestElement(tree->left); 
} 
 
struct node *findLargestElement(struct node *tree) 
{ 
    if(tree == NULL || tree->right == NULL) 
        return tree; 
    return findLargestElement(tree->right); 
} 
 
struct node *deleteElement(struct node *tree, int val) 
{ 
    if(tree == NULL) 
        return NULL; 
 
    if(val < tree->data) 
        tree->left = deleteElement(tree->left, val); 
    else if(val > tree->data) 
        tree->right = deleteElement(tree->right, val); 
    else 
    { 
        if(tree->left == NULL) 
        { 
            struct node *temp = tree->right; 
            free(tree); 
            return temp; 
        } 
        else if(tree->right == NULL) 
        { 
            struct node *temp = tree->left; 
            free(tree); 
            return temp; 
        } 
 
        struct node *temp = findSmallestElement(tree->right); 
        tree->data = temp->data; 
        tree->right = deleteElement(tree->right, temp->data); 
    } 
    return tree; 
} 
 
int totalNodes(struct node *tree) 
{ 
    if(tree == NULL) 
        return 0; 
    return totalNodes(tree->left) + totalNodes(tree->right) + 1; 
} 
 
int totalExternalNodes(struct node *tree) 
{ 
    if(tree == NULL) 
        return 0; 
    if(tree->left == NULL && tree->right == NULL) 
        return 1; 
    return totalExternalNodes(tree->left) + totalExternalNodes(tree->right); 
} 
 
int totalInternalNodes(struct node *tree) 
{ 
    if(tree == NULL || (tree->left == NULL && tree->right == NULL)) 
        return 0; 
    return totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1; 
} 
 
int Height(struct node *tree) 
{ 
    if(tree == NULL) 
        return 0; 
 
    int l = Height(tree->left); 
    int r = Height(tree->right); 
 
    return (l > r ? l : r) + 1; 
} 
 
struct node *mirrorImage(struct node *tree) 
{ 
    if(tree != NULL) 
    { 
        struct node *temp = tree->left; 
        tree->left = mirrorImage(tree->right); 
        tree->right = mirrorImage(temp); 
    } 
    return tree; 
} 
 
struct node *deleteTree(struct node *tree) 
{ 
    if(tree != NULL) 
    { 
        deleteTree(tree->left); 
        deleteTree(tree->right); 
        free(tree); 
    } 
    return NULL; 
}
