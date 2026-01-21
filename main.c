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
    int catalogueSize;
} Library;

void listBooks(Library library);
void addBook(Library library);

int main() {
    Library library = {0};
    library.catalogue = (book*) malloc(sizeof(book) * library.bookCount);
    library.catalogueSize = sizeof(library.catalogue) / sizeof(library.catalogue[0]);

    printf("======== Library Manager ========\n");
    printf("\t** library.catalogueSize = %i\n", library.catalogueSize);
    

    free(library.catalogue);
    library.catalogue = NULL;
    return 0;
}

// Function for displaying the list of all books in the Library's catalogue.
void listBooks(Library library) {
    if (library.catalogueSize < 1) {
        printf("There are no books in the Library.\n");
        return;
    }

    printf("ID\tAuthor\tTitle\tYear Released\tGenre\tPage Count\n");
    for (int i = 0; i < library.catalogueSize; i++) {
        printf("#%i\t%s\t%s\t%i\t%s\t%i\n",
            i, library.catalogue[i].author, library.catalogue[i].title,
            library.catalogue[i].yearReleased,library.catalogue[i].genre, library.catalogue[i].pageCount);
    }
}

// Function for adding a new book to the Library's catalogue.
void addBook(Library library) {
    book newBook;

    printf("Who is the author of the book? ");
    scanf("%s", newBook.author);
    printf("What is the book's title? ");
    scanf("%s", newBook.title);
    printf("What year was the book released in? ");
    scanf("%i", newBook.yearReleased);
    printf("What genre is the book part of? ");
    scanf("%s", newBook.genre);
    printf("How many pages does the book have? ");
    scanf("%i", newBook.pageCount);

    // Realloc library to fit 1 more book and add newBook to library
    library.bookCount++;
    library.catalogue = realloc(library.catalogue, sizeof(book) * library.bookCount);
    library.catalogueSize = sizeof(library.catalogue) / sizeof(library.catalogue[0]);

    library.catalogue[library.bookCount - 1] = newBook;
}

// TODO Implement function for deleting an existing book


// TODO Implement function for borrowing books


// TODO Implement function for displaying a list of all borrowed books