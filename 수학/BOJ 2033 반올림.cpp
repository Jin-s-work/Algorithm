#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <functional>
#include <map>
#include <set>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    
    int digit = 10;
    int num = 0;
    while(n > digit){
        num = n % digit;
        // n을 digit으로 나눈 나머지
        // 10, 100, 1000, 10000,,,,
        n -= num;
        // n에서 빼준다.
        // 내림한 것과 같음
        
        if(num >= 5 * (digit / 10))
            n += digit;
        // 5보다 크면 반올림 해야 하므로 다시 더해준다.
        // 올림해야하는 경우는 다시 올려줌
        
        digit *= 10;
    }
    
    cout << n;
    

    return 0;

}
