#include <iostream>
#include <string>
using namespace std;

class Fruit {
private:
    string m_name;
    string m_color;
public:
    Fruit(string name, string color):m_name{name}, m_color{color}
    {

    }
    string getName() const {
        return m_name;
    }
    string getColor() const {
        return m_color;
    }


};
class Apple : public Fruit {    
public:
    Apple(string color="red") : Fruit("Apple", color)
    {
        
    }

};
class Banana : public Fruit {
public:
    Banana(string name = "banana", string color = "yellow") : Fruit(name, color)
    {

    }

};
class RedBanana : public Banana {
public:
    RedBanana(string name = "red banana", string color = "red") : Banana(name, color) {

    }
};



int main() {
    Apple a{ "red" };
    Banana b;
    RedBanana c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;    
}
