#include <cstring>
#include "strngbad.h"
using std::cout;
using std::endl;

// initializing static class member
int StringBad::num_strings = 0;


// class methods

// construct StringBad from C string
StringBad::StringBad(const char* s){
    len = std::strlen(s);    // set size
    str = new char[len + 1];  // allot storage
    std::strcpy(str, s);      // initialize pointer
    num_strings++;
}

StringBad::StringBad()      // default constructor
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++");
    num_strings++;
    // cout << num_strings << ": \"" << str    
        // << "\" default object created\n";  
}

StringBad::~StringBad()   // necessary destructor
{
    --num_strings;   // required
    delete [] str;   // require to free the heap
}

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
        os << st.str;
        return os;
}

void callme1(StringBad & rsb)
    {
        cout << "String passed by reference:\n" << endl;
        cout << rsb << endl;
    }
void callme2(StringBad);

int main(){
    system("cls");
    StringBad headline("Celery Stalks at Midnight");
    callme1(headline);

    return 0;
}