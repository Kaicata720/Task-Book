#include "Class Book.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

// ==> Default constuctor
Book::Book()  :title(nullptr), author(nullptr), publishYear(0)
{
   
}

// ==> Copy constructor
Book::Book(const Book& other) {
    size_t titleLength = strlen(other.title) + 1;
    size_t authorLength = strlen(other.author) + 1;
    this->author = new char[authorLength];
    this->title = new char[titleLength];
    
    strcpy_s(this->title, titleLength, other.title);
    strcpy_s(this->author,authorLength, other.author);
    this->publishYear = other.publishYear;
}

// ==> Parametric constructor
Book::Book(const char* title, const char* author, int publishYear) :title(nullptr), author(nullptr), publishYear(0)
{
    size_t titleLength = strlen(title) + 1;
    size_t authorLength = strlen(author) + 1;

    this->title = new char[titleLength];
    this->author = new char[authorLength];

    strcpy_s(this->title, titleLength, title);
    strcpy_s(this->author, authorLength, author);
    this->publishYear = publishYear;
}

// ==> Destructor
Book::~Book() {
    delete[] title;
    delete[] author;
    
}

// ==> Getters
const char* Book::getTitle()const {
    return title;
}
const char* Book::getAuthor()const {
    return author;
}
int Book::getPublishYear()const {
    return publishYear;
}

// ==> Setters
void Book::setTitle(const char* newTitle) {

    // ==> We add +1 for terminal 0
    size_t newTitleLength = strlen(newTitle) + 1;

    if (strcmp(newTitle, "") == 0) {
        cout << "There is no name" << endl;
        return;
    }

    delete[] this->title;
    this->title = new char[newTitleLength];
    strcpy_s(this->title, newTitleLength, newTitle);
}

void Book::setAuthor(const char* newAuthor) {

    if (strcmp(newAuthor, "") == 0) {
        cout << "There is no name" << endl;
        return;
    }

    delete[] this->author;
    this->author = new char[strlen(newAuthor) + 1];
    strcpy_s(this->author, strlen(newAuthor) + 1, newAuthor);
}

void Book::setPublishYear(int newYear) {
    if (newYear <= 0) {
        cout << "Invalid year: " << newYear << endl;
        return;
    }
    this->publishYear = newYear;        
}


void Book::operator=(const Book& other) {
    //if missing here for samoprisvoqvane
    delete[] this->author;
    delete[] this->title;
    size_t titleLength = strlen(other.title) + 1;
    size_t authorLength = strlen(other.author) + 1;
    this->author = new char[authorLength];
    this->title = new char[titleLength];

    strcpy_s(this->title, titleLength, other.title);
    strcpy_s(this->author, authorLength, other.author);
    this->publishYear = other.publishYear;


}

void Book::operator<<(std::ostream& Output,const Book& book) {
    
}
void Book::printBook() {
    cout << title << endl;
    cout << author << endl;
    cout << publishYear << endl;
}