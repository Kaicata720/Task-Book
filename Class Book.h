#ifndef BOOK
#define BOOK



class Book {
private:
    char* title;
    char* author;
    int publishYear;

public:

    Book();
    Book(const Book&);
    ~Book(); 
    Book(const char* title, const char* author, int publishYear);
    const char* getTitle()const;
    const char* getAuthor()const;
    int getPublishYear()const;

    void setTitle(const char* newTitle);
    void setAuthor(const char* newAuthor);
    void setPublishYear(int newYear);

    void printBook();
    void operator=(const Book&);
    void operator<<(std::ostream&,const Book&);

};
#endif // !BOOK

