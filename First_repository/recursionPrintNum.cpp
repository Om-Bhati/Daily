#include <iostream>
using namespace std ;
void printNum(int num){
    if (num==0){
        return ;
    }
    cout<< num << " " ;
    printNum(num-1);
}
int main(){
    int num ;
    cout<< "Enter a number : ";
    cin>> num ;
    printNum(num);
    return 0;
}