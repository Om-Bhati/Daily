#include <iostream>
using namespace std ;
int Factorial(int num){
    int fact ;
    if (num <= 1){
        return 1 ;
    }
    fact = num * Factorial(num-1);
    return fact ;
}
int getFactorial(int num){
    if (num <= 1){
        return 1;
    }
    int aage_ka_factorial = getFactorial(num-1);
    int ans = num * aage_ka_factorial ;
    return ans;
}
int main(){
    int num ;
    cout<< "Enter a number : ";
    cin>> num ;
    int ans = Factorial(num);
    cout<< ans << endl;
    int answer = getFactorial(num);
    cout<< answer ;
    return 0;
}