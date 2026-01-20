#include <stdio.h>
#include <stdlib.h>

// Struct for books, with members: author, title, release date, genre, page count.
struct book {
    char author[32];
    char title[32];
    char releaseDate[16];
    char genre[16];
    int pageCount;
};

int main() {
    struct book library[0];

    printf("===== Library Manager =====\n");
    
    return 0;
}

// TODO Implement function for displaying a list of all books


// TODO Implement function for adding a new book


// TODO Implement function for deleting an existing book


// TODO Implement function for borrowing books


// TODO Implement function for displaying a list of all borrowed books