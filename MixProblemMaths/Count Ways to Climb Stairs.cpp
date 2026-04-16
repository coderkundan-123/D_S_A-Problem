#include<iostream>
using namespace std;

int countWay(int n){
    if(n == 0 || n == 1){
        return 1;
    }

    return countWay(n-1) + countWay(n-2);
}

int main(){
    int num = 4;
    int ans = countWay(num);
    cout << ans << endl;
    return 0;
}
