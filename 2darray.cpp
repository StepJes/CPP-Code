#include<iostream>
using namespace std;

int main(){
    // This is ho wa 2-D arrays look like cin c++
    // We can use the same to create a multi dimensional array 
    int numgrid[6][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {1,2,3,4},
        {5,6,7,8},
        {1,2,3,4},
        {5,6,7,8}
        };
    cout<<numgrid[1][1];

    // This is a example of neted for loop
    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
            cout<<numgrid[i][j]<<"\t";
        }
    cout<<"\n";
    }
    return 0;
}