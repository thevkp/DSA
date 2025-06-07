#include <iostream>
#include <typeinfo>
#include <cstdlib>
using namespace std;

class sensorData{
    private:
        int data;
    public: 
        sensorData(int value) : data(value) {}

        int resultData(){
            return data * data / 2;
        }
};

int main(){
    system("cls");
    int data = 0;
    cin >> data;
    // static allocation
    sensorData dataCapture(data);

    // Dynamic allocation
    sensorData* sensorCapture = new sensorData(data);

    cout << dataCapture.resultData() << endl;
    cout << sensorCapture->resultData() << endl;

    cout << typeid(dataCapture).name() << endl;
    cout << typeid(sensorCapture).name() << endl;

    return 0;
}