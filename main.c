#include <stdio.h>
#include <stdlib.h>

// Struct for books, with members: author, title, release date, genre, page count.
struct book {
    int id;
    char author[32];
    char title[32];
    char releaseDate[16];
    char genre[16];
    int pageCount;
};

void listBooks(struct book *library, int librarySize);

int main() {
    struct book library[0];
    int librarySize = sizeof(library) / sizeof(library[0]);

    printf("======== Library Manager ========\n");
    printf("** librarySize = %i\n", librarySize);
    
    return 0;
}

// Function for displaying the list of all books.
void listBooks(struct book *library, int librarySize) {
    if (librarySize < 1) {
        printf("There are no books in the Library.\n");
        return;
    }

    printf("ID\tAuthor\tTitle\tRelease Date\tGenre\tPage Count\n");
    for (int i = 0; i < librarySize; i++) {
        printf("%i\t%s\t%s\t%s\t%s\t%i\n",
            library[i].id, library[i].author, library[i].title,
            library[i].releaseDate, library[i].genre, library[i].pageCount);
    }
}


// TODO Implement function for adding a new book


// TODO Implement function for deleting an existing book


// TODO Implement function for borrowing books


// TODO Implement function for displaying a list of all borrowed books