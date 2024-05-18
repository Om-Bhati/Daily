#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

void printVector(vector<int> str){
    for (int i : str){
        cout << i << " ";
    }
    cout << endl;
}
void printArray(int n ,int arr[]){
    for (int i=0 ; i<n ; i++){
        cout << arr[i] << " " ;
    }
    cout << endl ;
}
void printAllSubsequencPowerset(int n ,string str){
    string sub;
    for (int i=0 ; i<pow(2,n) ; i++){
        sub = "";
        for (int j=0 ; j<n ; j++){
            if (i & (1<<j)){
                sub += str[j];
            }
        }
        cout << sub << endl;
    }
}
void printAllSubsequence(int index, int n , vector<int> ans ,vector<int> str){
    if (index>=n){
        printVector(ans);
        return ;
    }
    ans.push_back(str[index]);
    printAllSubsequence(index+1,n,ans,str);
    ans.pop_back();
    printAllSubsequence(index+1,n,ans,str);
}
void printAllSubstringWithSum(int index, int n ,int s ,int sum , vector<int>& ans , vector<int> str){
    if (index>=n){
        if(s==sum){
            printVector(ans);
        }
        return ;
    }
    // Take condition
    ans.push_back(str[index]);
    s += str[index];
    printAllSubstringWithSum(index+1 , n ,s , sum, ans , str);
    // Not Take condition
    ans.pop_back();
    s -= str[index];
    printAllSubstringWithSum(index+1 , n ,s , sum, ans , str);
}
bool printOneSubstringWithSum(int index, int n ,int s ,int sum , vector<int>& ans , vector<int> str){
    if (index>=n){
        if(s==sum){
            printVector(ans);
            return true ;
        }
        return false;
    }
    // Take condition
    ans.push_back(str[index]);
    s += str[index];
    if (printOneSubstringWithSum(index+1 , n ,s , sum, ans , str)) return true;
    // Not Take condition
    ans.pop_back();
    s -= str[index];
    if (printOneSubstringWithSum(index+1 , n ,s , sum, ans , str)) return true;

    return false;
}

int numberofSubstringWithSumk(int index , int n , int sum , int k , vector<int> ans , vector <int> str){
    if (index >= n){
        if (sum == k){
            printVector(ans);
            return 1; 
        }
        return 0;
    }
    ans.push_back(str[index]);
    sum += str[index];
    int l = numberofSubstringWithSumk(index+1,n,sum,k,ans,str);
    ans.pop_back();
    sum -= str[index];
    int r = numberofSubstringWithSumk(index+1,n,sum,k,ans,str);
    return l+r;
}

int main(){
    vector<int> str = {1,2,1,3,-1};
    vector<int> ans = {};
    int numberofSubstring = numberofSubstringWithSumk(0,str.size(),0,2,ans,str);
    cout << numberofSubstring;
    return 0;
}