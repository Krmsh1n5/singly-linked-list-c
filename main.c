#include <stdio.h>
#include <stdlib.h>

struct node {
    int num;
    struct node *nextptr;
};

struct node *head = NULL;

int readInt(void) {
    int value;
    int c;
    while (scanf("%d", &value) != 1) {
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("Please enter a valid integer: ");
    }
    return value;
}

void freeList(void) {
    struct node *tmp;
    while (head != NULL) {
        tmp = head;
        head = head->nextptr;
        free(tmp);
    }
}

void createNodeList(int n) {
    struct node *newNode, *tmp;
    int i;
    if (n <= 0) {
        printf("Number of nodes must be positive.\n");
        return;
    }
    freeList();
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory can not be allocated.\n");
        return;
    }
    printf("Input data for node 1: ");
    head->num = readInt();
    head->nextptr = NULL;
    tmp = head;
    for (i = 2; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory can not be allocated.\n");
            break;
        }
        printf("Input data for node %d: ", i);
        newNode->num = readInt();
        newNode->nextptr = NULL;
        tmp->nextptr = newNode;
        tmp = tmp->nextptr;
    }
}

int NodeCount(void) {
    int ctr = 0;
    struct node *tmp = head;
    while (tmp != NULL) {
        ctr++;
        tmp = tmp->nextptr;
    }
    return ctr;
}

void displayList(void) {
    struct node *tmp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->num);
        tmp = tmp->nextptr;
    }
    printf("\n");
}

void displayReverse(struct node *tmp) {
    if (tmp == NULL)
        return;
    displayReverse(tmp->nextptr);
    printf("%d ", tmp->num);
}

void NodeInsertatBegin(int num) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory can not be allocated.\n");
        return;
    }
    newNode->num = num;
    newNode->nextptr = head;
    head = newNode;
}

void NodeInsertatEnd(int num) {
    struct node *newNode, *tmp;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory can not be allocated.\n");
        return;
    }
    newNode->num = num;
    newNode->nextptr = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    tmp = head;
    while (tmp->nextptr != NULL)
        tmp = tmp->nextptr;
    tmp->nextptr = newNode;
}

void insertNodeAtMiddle(int num, int pos) {
    int i;
    struct node *newNode, *tmp;
    if (head == NULL || pos <= 1) {
        NodeInsertatBegin(num);
        return;
    }
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory can not be allocated.\n");
        return;
    }
    newNode->num = num;
    newNode->nextptr = NULL;
    tmp = head;
    for (i = 2; i <= pos - 1; i++) {
        tmp = tmp->nextptr;
        if (tmp == NULL)
            break;
    }
    if (tmp != NULL) {
        newNode->nextptr = tmp->nextptr;
        tmp->nextptr = newNode;
    } else {
        printf("Insert is not possible to the given position.\n");
        free(newNode);
    }
}

void FirstNodeDeletion(void) {
    struct node *toDelptr;
    if (head == NULL) {
        printf("There are no nodes in the list.\n");
        return;
    }
    toDelptr = head;
    head = head->nextptr;
    printf("Deleted node data: %d\n", toDelptr->num);
    free(toDelptr);
}

void LastNodeDeletion(void) {
    struct node *toDelLast, *preNode;
    if (head == NULL) {
        printf("There is no element in the list.\n");
        return;
    }
    toDelLast = head;
    preNode = head;
    while (toDelLast->nextptr != NULL) {
        preNode = toDelLast;
        toDelLast = toDelLast->nextptr;
    }
    if (toDelLast == head)
        head = NULL;
    else
        preNode->nextptr = NULL;
    printf("Deleted node data: %d\n", toDelLast->num);
    free(toDelLast);
}

void MiddleNodeDeletion(int pos) {
    int i;
    struct node *toDelMid, *preNode;
    if (head == NULL) {
        printf("There are no nodes in the list.\n");
        return;
    }
    if (pos <= 1) {
        FirstNodeDeletion();
        return;
    }
    toDelMid = head;
    preNode = head;
    for (i = 2; i <= pos; i++) {
        preNode = toDelMid;
        toDelMid = toDelMid->nextptr;
        if (toDelMid == NULL)
            break;
    }
    if (toDelMid != NULL) {
        preNode->nextptr = toDelMid->nextptr;
        toDelMid->nextptr = NULL;
        printf("Deleted node data: %d\n", toDelMid->num);
        free(toDelMid);
    } else {
        printf("Deletion can not be possible from that position.\n");
    }
}

int searchNode(int num) {
    struct node *tmp = head;
    int pos = 1;
    while (tmp != NULL) {
        if (tmp->num == num)
            return pos;
        tmp = tmp->nextptr;
        pos++;
    }
    return -1;
}

int main(void) {
    int choice, sub, value, pos, n, loc;
    int running = 1;

    printf("Create your linked list first.\n");
    printf("How many nodes do you want to create? ");
    n = readInt();
    createNodeList(n);

    while (running) {
        printf("\n===== Singly Linked List =====\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Delete\n");
        printf("4. Count\n");
        printf("5. Search\n");
        printf("6. Create a new list\n");
        printf("0. Exit\n");
        printf("Choose an operation: ");
        choice = readInt();

        switch (choice) {
        case 1:
            printf("\nInsert:\n");
            printf("  1. At the beginning\n");
            printf("  2. At a given position\n");
            printf("  3. At the end\n");
            printf("Choose insertion type: ");
            sub = readInt();
            if (sub == 1) {
                printf("Enter value to insert: ");
                value = readInt();
                NodeInsertatBegin(value);
            } else if (sub == 2) {
                printf("Enter value to insert: ");
                value = readInt();
                printf("Enter position: ");
                pos = readInt();
                insertNodeAtMiddle(value, pos);
            } else if (sub == 3) {
                printf("Enter value to insert: ");
                value = readInt();
                NodeInsertatEnd(value);
            } else {
                printf("Invalid insertion type.\n");
            }
            break;
        case 2:
            printf("\nDisplay:\n");
            printf("  1. Ascending (head to tail)\n");
            printf("  2. Descending (tail to head)\n");
            printf("Choose display order: ");
            sub = readInt();
            if (sub == 1) {
                displayList();
            } else if (sub == 2) {
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    displayReverse(head);
                    printf("\n");
                }
            } else {
                printf("Invalid display order.\n");
            }
            break;
        case 3:
            printf("\nDelete:\n");
            printf("  1. At the beginning\n");
            printf("  2. At the end\n");
            printf("  3. At a given position\n");
            printf("Choose deletion type: ");
            sub = readInt();
            if (sub == 1) {
                FirstNodeDeletion();
            } else if (sub == 2) {
                LastNodeDeletion();
            } else if (sub == 3) {
                printf("Enter position: ");
                pos = readInt();
                MiddleNodeDeletion(pos);
            } else {
                printf("Invalid deletion type.\n");
            }
            break;
        case 4:
            printf("Number of nodes: %d\n", NodeCount());
            break;
        case 5:
            printf("Enter value to search: ");
            value = readInt();
            loc = searchNode(value);
            if (loc == -1)
                printf("Value %d not found in the list.\n", value);
            else
                printf("Value %d found at position %d.\n", value, loc);
            break;
        case 6:
            printf("How many nodes do you want to create? ");
            n = readInt();
            createNodeList(n);
            break;
        case 0:
            running = 0;
            break;
        default:
            printf("Invalid operation.\n");
        }
    }

    freeList();
    printf("List freed. Goodbye.\n");
    return 0;
}
