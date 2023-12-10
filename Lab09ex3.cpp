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
    Banana(string color = "yellow") : Fruit("Banana", color)
    {

    }

};




int main() {
    Apple a{ "red" };
    Banana b;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";

    return 0;    
}
