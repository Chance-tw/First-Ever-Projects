#include <iostream>
#include <iomanip>
#include "inputs.hpp"
using namespace std;

int main(){
    inputs arrays;
    double avg = arrays.average();
    cout<<setprecision(1)<<fixed<<"The average rainfall for ";
    for (int i=0; i<arrays.size; i++){
        cout<<arrays.months[i];
        if (i!=(arrays.size-1)){
            if (i!=(arrays.size-2)){
                cout<<", ";
                continue;
            }
            cout<<", and ";
        }
    }
    cout<<setprecision(2)<<fixed<<" is "<<avg<<" inches.";
    return 0;
}
