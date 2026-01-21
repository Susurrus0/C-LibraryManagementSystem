#include <stdio.h>
#include <stdlib.h>

// Struct for books, with members: id, author, title, release date, genre, page count.
struct book {
    int id;
    char author[32];
    char title[32];
    int yearReleased;
    char genre[16];
    int pageCount;
};

// Struct for the Library, with members: bookCount, catalogue.
struct Library {
    int bookCount;
    struct book *catalogue;
};

void listBooks(struct book *library, int librarySize);
void addBook(struct book *library, int librarySize);

int main() {
    struct book *library = NULL;
    library = (struct book*) malloc(sizeof(struct book)*0);
    int librarySize = sizeof(library) / sizeof(library[0]);

    printf("======== Library Manager ========\n");
    printf("\t** librarySize = %i\n", librarySize);
    
    return 0;
}

// Function for displaying the list of all books.
void listBooks(struct book *library, int librarySize) {
    if (librarySize < 1) {
        printf("There are no books in the Library.\n");
        return;
    }

    printf("ID\tAuthor\tTitle\tYear Released\tGenre\tPage Count\n");
    for (int i = 0; i < librarySize; i++) {
        printf("%i\t%s\t%s\t%i\t%s\t%i\n",
            library[i].id, library[i].author, library[i].title,
            library[i].yearReleased, library[i].genre, library[i].pageCount);
    }
}

// TODO Implement function for adding a new book
void addBook(struct book *library, int librarySize) {
    struct book newBook;
    newBook.id = library[librarySize - 1].id + 1;

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

}

// TODO Implement function for deleting an existing book


// TODO Implement function for borrowing books


// TODO Implement function for displaying a list of all borrowed books