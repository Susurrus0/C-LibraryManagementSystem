#include <stdio.h>
#include <stdlib.h>

// Struct for books, with members: author, title, release date, genre, page count.
typedef struct {
    char author[32];
    char title[32];
    unsigned short yearReleased;
    char genre[16];
    unsigned short pageCount;
} book;

// Struct for the Library, with members: bookCount, catalogue.
typedef struct {
    int bookCount;
    book *catalogue;
} Library;

void listBooks(Library *library);
void addBook(Library *library);

int main() {
    Library library = {0};
    Library *libPtr = &library;

    printf("======== Library Manager ========\n");
    printf("|    1. List available books    |\n");
    printf("|         2. Add a book         |\n");
    printf("|       3. Delete a book        |\n");
    printf("|        4. Lend a book         |\n");
    printf("|    5. List borrowed books     |\n");
    printf("|                               |\n");
    printf("|            0. Exit            |\n");
    printf("=================================\n");
    printf("\n");

    printf("\t** libPtr->bookCount = %i\n", libPtr->bookCount);
    printf("\t** sizeof(book) = %i\n", sizeof(book));
    printf("\t** sizeof(Library) = %i\n", sizeof(Library));

    printf("Choice: ");
    unsigned int userInput;
    scanf("%d", &userInput);
    
    addBook(libPtr);

    printf("\t** libPtr->bookCount = %i\n", libPtr->bookCount);

    listBooks(libPtr);

    free(libPtr->catalogue);
    libPtr->catalogue = NULL;
    return 0;
}

// Function for displaying the list of all books in the Library's catalogue.
void listBooks(Library *library) {
    if (library->bookCount < 1) {
        printf("There are no books in the Library.\n");
        return;
    }

    printf("ID\t Author\t\t Title\t\t Year Released\t Genre\t\t Page Count\n");
    for (int i = 0; i < library->bookCount; i++) {
        printf("#%i\t %s\t %s\t %i\t\t %s\t %i\n",
            i, library->catalogue[i].author, library->catalogue[i].title,
            library->catalogue[i].yearReleased, library->catalogue[i].genre, library->catalogue[i].pageCount);
    }
}

// Function for adding a new book to the Library's catalogue.
void addBook(Library *library) {
    book newBook;

    printf("Adding new book...\n");
    printf("Who is the author of the book? ");
    scanf("%s", newBook.author);
    printf("What is the book's title? ");
    scanf("%s", newBook.title);
    printf("What year was the book released in? ");
    scanf("%d", &newBook.yearReleased);
    printf("What genre is the book part of? ");
    scanf("%s", newBook.genre);
    printf("How many pages does the book have? ");
    scanf("%d", &newBook.pageCount);

    // Realloc library to fit 1 more book and add newBook to library
    library->bookCount++;
    library->catalogue = realloc(library->catalogue, sizeof(book) * library->bookCount);

    library->catalogue[library->bookCount - 1] = newBook;

    printf("New book successfully added.\n");
}

// TODO Implement function for deleting an existing book


// TODO Implement function for borrowing books


// TODO Implement function for displaying a list of all borrowed books