#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

struct Book {
    char bookId[50];
    char bookName[50];
    char bookPrice[50];
    char bookAuthor[50];
    char copyAvailable[50];
    char issueDate[50];
    char issueYear[50];
    int returnDay;
    char bookGenres[50];
};

struct User {
    char userId[50];
    char username[50];
    char password[50];
    char role[20];
};

struct Librarian {
    struct User user;
};


void librarian(void);
void student(void);
void libInfo(void);

// Functions for Librarian
void addBook(void);
void updateBook(void);
void generateReports(void);

FILE *libBook;
FILE *history;
struct Book b;
struct User u;
struct Librarian l;


int main() {
    system("cls");
    int choice;
    while (1) {
    	system("cls");
    	printf("LIBRARAY MANAGMENT SYSTEM\n");
        printf("\t1- Librarian \n\t 2- Student \n\t 3- Library Related information\n");
        printf(" choice----- > ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                librarian();
                break;

            case 2:
                student();
                break;

            default:
                printf("\nInvalid Choice.\n");
        }
    }
    return 0;
}

void librarian() {
	system("cls");
    char id[50], uName[50], pass[50];
    struct User U = {"0773", "mehwishzehra", "fast1234", "librarian"};
        printf("\tLOGIN AS LIBRARIAN:\n");
        printf("LIBRARIAN ID:");
        scanf("%s", id);
        printf("User Name:");
        scanf("%s", uName);
        printf("Password:");
        scanf("%s", pass);
        if (strcmp(pass, U.password) == 0) {
        	system("cls");
            int choice;
            printf("Librarian Menu\n");
            printf("\t1- Add Book \n\t2- Update Book \n\t3- Generate Reports\n");
            printf("choice---: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    addBook();
                    break;

                case 2:
                    updateBook();
                    break;

                case 3:
                    generateReports();
                    break;

                default:
                    printf("\nInvalid Choice\n");
            }
        } else {
            printf("\nInvalid Password\n");
            
        }
    }


void addBook() {
    system("cls");
    libBook = fopen("LBook.txt", "a");

    if (libBook == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

    printf("Enter Book ID: ");
    scanf(" %[^\n]", b.bookId);

    printf("Enter Book Name: ");
    scanf(" %[^\n]", b.bookName);

    printf("\nEnter Author Name: ");
    scanf(" %[^\n]", b.bookAuthor);
    
    printf("Enter Book Genre: ");
    scanf(" %[^\n]", b.bookGenres);

    printf("Enter Book Price: ");
    scanf(" %[^\n]", b.bookPrice);

    printf("Enter Copy Available: ");
    scanf(" %[^\n]", b.copyAvailable);

    printf("Enter Issue Year: ");
    scanf(" %[^\n]", b.issueYear);

    printf("\nBook Added Successfully.\n");

    fprintf(libBook, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres,b.bookPrice, b.copyAvailable,b.issueYear);
    fclose(libBook);
    
    getch();
     
   
}
void bookPrice();
void bookYear();
void updateBook() {
    system("cls");
    int c;  // Move the declaration outside the switch
    printf("\t1-Book Price\n\t2-Issue Year\n");
    scanf("%d", &c);
    switch (c) {
        case 1:
            bookPrice();
            break;
            
        case 2:
        	bookYear();
        	break; 
    }
}

void bookPrice() {
    system("cls");
    libBook = fopen("LBook.txt", "r");
    while (fscanf(libBook, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookAuthor,b.bookPrice, b.copyAvailable, b.issueYear) != EOF) {
    }
    fclose(libBook);
    char bName[50];
    int found;
    printf("Enter Book Name: ");
    scanf("%s", bName);

    FILE *bUpdate;
    bUpdate = fopen("bup.txt", "w");
    libBook = fopen("LBook.txt", "r");
    while (fscanf(libBook, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear) != EOF) {
        if (strcmp(b.bookName, bName) == 0) {
            found = 1;
            printf("Old Book's Price: %s", b.bookPrice);
            getch();
            printf("\nNew Book's Price: ");
            scanf(" %s", b.bookPrice);
            fprintf(bUpdate, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear);
            printf("\n%s Price Updated Successfully.", b.bookName);
        } else {
            fprintf(bUpdate, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear);
        }
    }
    fclose(libBook);
    fclose(bUpdate);
    remove("LBook.txt");
    rename("bup.txt", "LBook.txt");
    getch();
}

void bookYear(){
    system("cls");
    libBook = fopen("LBook.txt", "r");
    while (fscanf(libBook, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookAuthor,b.bookPrice, b.copyAvailable, b.issueYear) != EOF) {
    }
    fclose(libBook);
    char bName[50];
    int found;
    printf("Enter Book Name: ");
    scanf("%s", bName);

    FILE *bUpdate;
    bUpdate = fopen("bup.txt", "w");
    libBook = fopen("LBook.txt", "r");
    while (fscanf(libBook, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear) != EOF) {
        if (strcmp(b.bookName, bName) == 0) {
            found = 1;
            printf("Old Book's Year: %s", b.issueYear);
            getch();
            printf("\nNew Book's Year: ");
            scanf(" %s", b.issueYear);
            fprintf(bUpdate, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear);
            printf("\n%s Price Updated Successfully.", b.bookName);
        } else {
            fprintf(bUpdate, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear);
        }
    }
    fclose(libBook);
    fclose(bUpdate);
    remove("LBook.txt");
    rename("bup.txt", "LBook.txt");
    getch();

}


void displayAllBooks();
void displayBorrowedBooks();

void generateReports() {
    system("cls");
    int choice;
    
    printf("Reports Menu:\n");
    printf("1. Display All Books\n");
    printf("2. Display Borrowed Books\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            displayAllBooks();
            break;

        case 2:
            displayBorrowedBooks();
            break;

        default:
            printf("\nInvalid Choice\n");
            break;
    }
    getch();
}

void displayAllBooks(){
	system("cls");
	
	libBook = fopen("LBook.txt", "r");
    while (fscanf(libBook, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear) != EOF) {
    }
    fclose(libBook);
	
	if (libBook == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }
	printf("%-20s %-20s %-20s %-20s %-20s %-20s %-20s\n", "Book ID","Book Name","Author Name","Book Genre","Book Price","Copies","Issue Year");
    printf("----------------------------------------------------------------------------------------------------------------------------------\n");
	
	libBook = fopen("LBook.txt", "r");
	while (fscanf(libBook, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear) != EOF) {
		printf("%-20s %-20s %-20s %-20s %-20s %-20s %-20s\n",b.bookId,b.bookName,b.bookAuthor, b.bookGenres,b.bookPrice,b.copyAvailable,b.issueYear);
	}
	fclose(libBook);
	getch();
}
void displayBorrowedBooks(){
	system("cls");
	history=fopen("libHistory.txt","r");
	while(fscanf(history, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear)!=EOF){
		printf("%-25s %-25s %-25s  %-25s %-25s %-25s  %-25s\n", "Book ID", "Book Name", "Author Name", "Book Genres","Book Price","Book's Copy","Issue Year");
    	printf("%-25s %-25s %-25s %-25s %-25s %-25s  %-25s\n",b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear);
    		
	}
	fclose(history);
	getch();
	
	
}


void display();
void borrow();
void rreturn();

void student() {
    system("cls");
    system("cls");
    int choice;
    
    printf("Student Menu:\n");
    printf("1. Display Books(Genre)\n");
    printf("2. Borrow Books\n");
    printf("3. Return Books\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            display();
            break;

        case 2:
            borrow();
            break;

        case 3:
            rreturn();
            break;

        default:
            printf("\nInvalid Choice\n");
            break;
    }
    getch();

}

void display() {
    system("cls");
    struct Book b;
    int flag = 0;
    char gBook[50];
    char tempBook[50];

    printf("Enter Book Genre: ");
    scanf(" %[^\n]", gBook);

    libBook = fopen("LBook.txt", "r");
    if (libBook == NULL) {
        printf("Error opening the file.\n");
    }

    while (fscanf(libBook, "%s %s %s %s %s %s %s %d\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear, &b.returnDay) != EOF) {
        strcpy(tempBook, b.bookGenres);
        if (strcmp(tempBook, gBook) == 0) {
            printf("%-25s %-25s %-25s %-25s %-25s %-25s %-25s\n", "Book ID", "Book Name", "Author Name", "Book Genres", "Book Price", "Book's Copy", "Issue Year");
            printf("%-25s %-25s %-25s %-25s %-25s %-25s %-25s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear);
            flag = 1;
        }
    }

    if (!flag) {
        printf("No books found for the specified genre.\n");
    }

    fclose(libBook);
    getch();

}
	
void borrow() {
    system("cls");
    int flag = 0;
    char sBook[50];
    int returnDay;

    printf("Enter Book Name: ");
    scanf("%s", sBook);

    printf("Enter for how many days you are taking this: ");
    scanf("%d", &returnDay);

    printf("NOTE: \n\tIf you do not return the book in your allocated time, you have to pay extra charges.\n");

    libBook = fopen("LBook.txt", "r");
    history = fopen("libHistory.txt", "a");
    FILE *tempB = fopen("temp.txt", "w");

    if (libBook == NULL || history == NULL || tempB == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    while (fscanf(libBook, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear) != EOF) {
        if (strcmp(b.bookName, sBook) == 0) {
            flag = 1;
            printf("%-25s %-25s %-25s  %-25s %-25s %-25s %-25s %-25s\n", "Book ID", "Book Name", "Author Name", "Book Genres", "Book Price", "Book's Copy", "Issue Year", "Return Days");
            printf("%-25s %-25s %-25s %-25s %-25s %-25s %-25s %-25d\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear, returnDay);
            fprintf(history, "%s %s %s %s %s %s %s %d\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear, returnDay);
            printf("\nBook Issued Successfully.\n");
        } else {
            fprintf(tempB, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear);
        }
    }

    fclose(libBook);
    fclose(history);
    fclose(tempB);

    remove("LBook.txt");
    rename("temp.txt", "LBook.txt");

    if (!flag) {
        printf("\nBook named '%s' does not exist.\n", sBook);
    }

    getch();
}


void rreturn(){
	system("cls");
	char sBook[50];
	int rday;
	libBook=fopen("LBook.txt","r");
	while(fscanf(libBook, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear) != EOF){
	}
	if (libBook == NULL) {
        printf("Error opening the file.\n");
        exit(1);
    }

	fclose(libBook);
	printf("Enter After how many days you are returning Book:");
	scanf("%d",&rday);
	printf("Enter the book You want to return:");
	scanf("%s",sBook);
	 while (fscanf(libBook, "%s %s %s %s %s %s %s\n", b.bookId, b.bookName, b.bookAuthor, b.bookGenres, b.bookPrice, b.copyAvailable, b.issueYear) != EOF) {
        if (strcmp(b.bookName, sBook) == 0) {
            if(b.returnDay<rday){
            	printf("Pay 500 beacuse of you did not return book on time");
			}
			else{
				addBook();
			}
            
        }
    }

	
   
}



