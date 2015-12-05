using namespace std;

class CTest {
    int* integer;
    public:
    CTest(){
        integer=new int(1);
        cout << "CTest object constructed" << endl ;
    }
    ~CTest()
    {
        delete integer;
        cout << "CTest object destroyed" << endl ;
    }
};

void methodA() {
    CTest t;
    cout << *t.integer << endl;
}

int main() {
    cout << "Program begins" << endl;
    methodA();
    cout << "Program ends" << endl;
}
