/*
Да се състави рекурсивна функция за създаване на масив 
от цели стойности,отговарящи на цифрите на дадено число.
Например: 32167 a[0]=3, a[1]=2, a[2]=1, a[3]=6, a[4]=7
*/
#include <iostream>
#include <vector>
using namespace std;

vector <int> arr;
int rest;


void getArray(int number){
    if( number > 0 && number < 10){
        arr.push_back(number);
    }else{
       rest = number % 10;
       arr.push_back(rest);
        getArray(number/= 10);
    }
}

vector<int> getReversedArray(int number){
    arr.clear();
    getArray(number);
    reverse(arr.begin(), arr.end());
    return arr;
}


int main(){
    int n;
    cout<<"Enter a integer number:" << endl;
    cin>> n;

    //reverse the array
    getReversedArray(n);

    cout<<"**************" << endl;
    for (int i = 0; i < arr.size(); i++) {
      cout << "arr[" << i << "] = " << arr[i]<<endl;
    }
    cout<<"*************" << endl;
   return 0;
}
