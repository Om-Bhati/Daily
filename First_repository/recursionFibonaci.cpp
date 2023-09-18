#include <iostream>
using namespace std ;

int Fibo(int num){
    if (num == 0 || num == 1){
        return num ;
    }
    return Fibo(num-1)+Fibo(num-2);
}
int main(){
    int num ;
    cout<< "Enter a number : ";
    cin>> num ;
    int ans = Fibo(num);
    cout<< ans << endl;
    return 0;
}