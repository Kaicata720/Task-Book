#include "Class Book.h"





int main()
{
    Book book("JAJSDJ", "pesho", 2020);
    Book book1 = book;
    book.printBook();
     book1.printBook();
}


