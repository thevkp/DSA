#include <iostream>
#include <cstdlib>
using namespace std;

class copyConstructor{
    private:
        int age;
        char gender;
    public:
        copyConstructor(int age, char gender){
            this->age = age;
            this->gender = gender;
        }

        int getAge(){
            return age;
        }

        char getGender(){
            return gender;
        }

        void updateAge(int newAge){
            age = newAge;
        }
};


int main(){
    system("cls");
    copyConstructor obj1(70, 'M');
    cout << obj1.getAge() << endl << obj1.getGender() << endl;


    copyConstructor obj2(obj1); // calls default copy constructor as copyConstructor has no copy constructors defined
    cout << obj2.getAge() << endl << obj1.getGender() << endl;

    obj1.updateAge(71);
    cout << "New age: " << obj1.getAge() << endl;
    cout << "Copied new age: " << obj2.getAge() << endl;

    obj2.updateAge(74); // won't update obj1 data member, because default copy constructor makes a shallow copy
    cout << "Original new age: " << obj1.getAge() << endl;
    cout << "Copied new age: " << obj2.getAge() << endl;

    return 0;
}