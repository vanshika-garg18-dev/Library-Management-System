#include <stdio.h>
#include <string.h>

#define MAX 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int quantity;
};

struct Book library[MAX];
int count = 0;

// Add Book
void addBook() {
    printf("\nEnter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", library[count].title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", library[count].author);

    printf("Enter Quantity: ");
    scanf("%d", &library[count].quantity);

    count++;
    printf("\nBook Added Successfully!\n");
}

// Display Books
void displayBooks() {
    if (count == 0) {
        printf("\nNo Books Available!\n");
        return;
    }

    printf("\n-------------------------------------------------------------------\n");
    printf("ID\tTitle\t\t\tAuthor\t\tQuantity\n");
    printf("-------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%-20s\t%-15s\t%d\n",
               library[i].id,
               library[i].title,
               library[i].author,
               library[i].quantity);
    }
}

// Search Book
void searchBook() {
    int id;
    printf("\nEnter Book ID to Search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            printf("\nBook Found!\n");
            printf("Book ID : %d\n", library[i].id);
            printf("Title   : %s\n", library[i].title);
            printf("Author  : %s\n", library[i].author);
            printf("Quantity: %d\n", library[i].quantity);
            return;
        }
    }

    printf("\nBook Not Found!\n");
}

// Issue Book
void issueBook() {
    int id;

    printf("\nEnter Book ID to Issue: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {

            if (library[i].quantity > 0) {
                library[i].quantity--;
                printf("\nBook Issued Successfully!\n");
            } else {
                printf("\nBook Out of Stock!\n");
            }

            return;
        }
    }

    printf("\nBook Not Found!\n");
}

// Return Book
void returnBook() {
    int id;

    printf("\nEnter Book ID to Return: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            library[i].quantity++;
            printf("\nBook Returned Successfully!\n");
            return;
        }
    }

    printf("\nBook Not Found!\n");
}

// Delete Book
void deleteBook() {
    int id;

    printf("\nEnter Book ID to Delete: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {

        if (library[i].id == id) {

            for (int j = i; j < count - 1; j++) {
                library[j] = library[j + 1];
            }

            count--;
            printf("\nBook Deleted Successfully!\n");
            return;
        }
    }

    printf("\nBook Not Found!\n");
}

int main() {
    int choice;

    do {
        printf("\n==============================");
        printf("\n   LIBRARY MANAGEMENT SYSTEM");
        printf("\n==============================");
        printf("\n1. Add Book");
        printf("\n2. Display Books");
        printf("\n3. Search Book");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Delete Book");
        printf("\n7. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                deleteBook();
                break;

            case 7:
                printf("\nThank You!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while (choice != 7);

    return 0;
}