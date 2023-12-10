#include <iostream>
#include <string>
using namespace std;
class Book {
private:
    string m_name;
    string m_ISBN;
    double m_price;
public:
    Book(string name, string id, double price) : m_name{ name }, m_ISBN{ id }, m_price{ price } {

    }
    void ShowBookInfo() {
        cout << "Title: " << m_name << '\n';
        cout << "ISBN: " << m_ISBN << "\n";
        cout << "Price: " << m_price << "\n";
    }

    
};

class EBook :public Book {
private:
    string m_key;
    string m_format;
public:
    EBook(string name, string id, double price,string key, string f="kindle") :m_key{key}, m_format{f}, Book(name, id, price)
    {

    }
    void ShowEBookInfo() {
        Book::ShowBookInfo();
        cout << "DRMKey " << m_key << '\n';
        cout << "Format: " << m_format << "\n";
    

    }
};


int main() {
    Book book("Modern C++ Programming Cookbook", "1800208987", 49.99);
    book.ShowBookInfo();
    cout << endl;

    EBook ebook("Modern C++ Programming Cookbook(ebook)", "1800208987", 34.99, "dkb34x!@*~");
    ebook.ShowEBookInfo();

    return 0;
}
