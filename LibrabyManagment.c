#include <stdio.h>
#include <string.h>

struct Book
{
    int id;
    char name[50];
    char author[50];
};

struct Book library[100];
int count = 0;

void addBook()
{
    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);

    printf("Enter Book Name: ");
    scanf("%s", library[count].name);

    printf("Enter Author Name: ");
    scanf("%s", library[count].author);

    count++;

    printf("Book added successfully\n\n");
}

void displayBooks()
{
    int i;

    if(count == 0)
    {
        printf("No books in library\n\n");
        return;
    }

    printf("\nLibrary Books:\n");

    for(i = 0; i < count; i++)
    {
        printf("ID: %d\n", library[i].id);
        printf("Name: %s\n", library[i].name);
        printf("Author: %s\n\n", library[i].author);
    }
}

void searchBook()
{
    int id, i, found = 0;

    printf("Enter Book ID to search: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(library[i].id == id)
        {
            printf("Book Found\n");
            printf("Name: %s\n", library[i].name);
            printf("Author: %s\n\n", library[i].author);
            found = 1;
        }
    }

    if(found == 0)
    {
        printf("Book not found\n\n");
    }
}

void deleteBook()
{
    int id, i, j;

    printf("Enter Book ID to delete: ");
    scanf("%d", &id);

    for(i = 0; i < count; i++)
    {
        if(library[i].id == id)
        {
            for(j = i; j < count - 1; j++)
            {
                library[j] = library[j + 1];
            }

            count--;

            printf("Book deleted successfully\n\n");
            return;
        }
    }

    printf("Book not found\n\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("===== Library Management System =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Delete Book\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            addBook();
        }
        else if(choice == 2)
        {
            displayBooks();
        }
        else if(choice == 3)
        {
            searchBook();
        }
        else if(choice == 4)
        {
            deleteBook();
        }
        else if(choice == 5)
        {
            printf("Program closed\n");
            break;
        }
        else
        {
            printf("Invalid choice\n\n");
        }
    }

    return 0;
}