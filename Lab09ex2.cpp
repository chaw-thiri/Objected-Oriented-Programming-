#include <cassert>
#include <iostream>
using namespace std;
class Test {
private:
    int m_id;
    int m_data;
    static int count;
public:
    Test() : m_id{ NULL }, m_data{ NULL } {
        
    }
    Test(int data) : m_data{ data }, m_id{Test::count} {
        count++;
    }
    static int NumOfObjects();
    int getData() const {
        return m_data;
    }
    int getID() const {
        return m_id;
    }
};

int Test::count = 0;
int Test::NumOfObjects() {
    return Test::count;
}




int main() {
    cout << "# of objects: ";
    cout << Test::NumOfObjects() << endl;

    Test t1{ 10 }, t2{ 20 }, t3{ 30 }, t4{ 40 };
    cout << "[t1] data: " << t1.getData() << ", id: " << t1.getID() << endl;
    cout << "[t2] data: " << t2.getData() << ", id: " << t2.getID() << endl;
    cout << "[t3] data: " << t3.getData() << ", id: " << t3.getID() << endl;
    cout << "[t4] data: " << t4.getData() << ", id: " << t4.getID() << endl;

    cout << "# of objects: ";
    cout << Test::NumOfObjects() << endl;
    return 0;
}
