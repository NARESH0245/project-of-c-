
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 50
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 50

// Struct to represent a book
struct Book {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
};

// Array to store library books
struct Book library[MAX_BOOKS];

// Function to add a book to the library
void addBook(int id, const char *title, const char *author) {
    if (id >= 1 && id <= MAX_BOOKS) {
        if (library[id - 1].id == 0) {
            library[id - 1].id = id;
            strncpy(library[id - 1].title, title, MAX_TITLE_LENGTH - 1);
            library[id - 1].title[MAX_TITLE_LENGTH - 1] = '\0';
            strncpy(library[id - 1].author, author, MAX_AUTHOR_LENGTH - 1);
            library[id - 1].author[MAX_AUTHOR_LENGTH - 1] = '\0';
            printf("Book added successfully: ID %d, Title: %s, Author: %s\n", id, title, author);
        } else {
            printf("Book with ID %d already exists.\n", id);
        }
    } else {
        printf("Invalid book ID.\n");
    }
}

// Function to remove a book from the library
void removeBook(int id) {
    if (id >= 1 && id <= MAX_BOOKS) {
        if (library[id - 1].id != 0) {
            printf("Book removed: ID %d, Title: %s, Author: %s\n", library[id - 1].id, library[id - 1].title, library[id - 1].author);
            library[id - 1].id = 0;
            library[id - 1].title[0] = '\0';
            library[id - 1].author[0] = '\0';
        } else {
            printf("Book with ID %d does not exist.\n", id);
        }
    } else {
        printf("Invalid book ID.\n");
    }
}

// Function to display all books in the library
void displayBooks() {
    printf("Library Books:\n");
    printf("ID\tTitle\t\t\tAuthor\n");
    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (library[i].id != 0) {
            printf("%d\t%-30s\t%-20s\n", library[i].id, library[i].title, library[i].author);
        }
    }
}

int main() {
    int choice, id;
    char title[MAX_TITLE_LENGTH], author[MAX_AUTHOR_LENGTH];

    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Display Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d", &id);
                printf("Enter book title: ");
                scanf("%s", title);
                printf("Enter book author: ");
                scanf("%s", author);
                addBook(id, title, author);
                break;
            case 2:
                printf("Enter book ID to remove: ");
                scanf("%d", &id);
                removeBook(id);
                break;
            case 3:
                displayBooks();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
