#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    // declare the private member variables
    string m_title;
    string m_ISBN;
    double m_price;
public:
    // constructor 
    Book(string title, string ISBN, double price) : m_title{ title }, m_ISBN{ ISBN }, m_price{ price }
    {

    }

    void ShowBookInfo() {
        cout << "Title : " << m_title << endl;
        cout << "ISBN : " << m_ISBN << endl;
        cout << "Price(USD) : " << m_price << endl;
    }
};
class EBook:public Book { // inheriting Book class 
private:
    string m_DMRkey;
    string m_format;


public:
    // constructor 
    EBook(string title, string ISBN, double price,string DMRkey,string format = "Kindle") :Book(title, ISBN, price), m_DMRkey{DMRkey}, m_format{format}
    {

    }
    void ShowEBookInfo() {
        ShowBookInfo(); // calling the function of parent class to print out parent member variables
        cout << "DRM Key: " << m_DMRkey << endl;
        cout << "Format: " << m_format << endl;
        
    }
};
const int MAX_BOOK = 100;

class EBookLibrary {
private:
    EBook* m_books[100];
    int m_cnt = 0;
public:
    
    
    void AddBook(EBook* book) {
        // no more book will be created if the number of books reaches the max
        if (m_cnt == 100) {
            cout << "The library is full. Cannot add more books";
            return;
        }
        m_books[m_cnt] = book;
        m_cnt++;
    }
    void ShowAllBooks(void) {
        if (m_cnt == 0) {
            cout << "Library is empty.";
            return;
        }
        for (int i = 0; i < m_cnt; ++i) {
            m_books[i]->ShowEBookInfo();
            cout << endl;
        }
    }
    ~EBookLibrary() {
        for (int i = 0; i < m_cnt; ++i) {
            delete m_books[i];
        }
    }

};


int main() {
    EBookLibrary elib;
    elib.AddBook(new EBook{ "Book1", "1234567890", 10.99, "AAAAAA", "ePub" });
    elib.AddBook(new EBook{ "Book2", "2345678901", 20.99, "BBBBBB" });
    elib.AddBook(new EBook{ "Book3", "3456789012", 30.99, "CCCCCC", "ePub" });
    elib.AddBook(new EBook{ "Book4", "4567890123", 40.99, "DDDDDD" });
    elib.ShowAllBooks();

    return 0;
}
