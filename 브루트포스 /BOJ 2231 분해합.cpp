
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
int h, w;



int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    
    int num = 0;
    int sum = 0;
    
    for(int i=0;i<n;i++){
        num = i;
        sum = i;
        
        while(num){
            sum += num % 10;
            num /= 10;
            // num은 각 자리수를 나타내며 더해줌
            // 10을 나누어 가면서
        }
        
        if(sum == n){
            cout << i << '\n';
            return 0;
        }       // 그게 n일 경우 바로 출력해줌
    }           // 작은 수부터 차례대로 올라가기에 가장 먼저 출력하는 것이 최솟값
    
    
    cout << "0";
    // 앞에서 출력이 안됐을 경우 0을 출력
    
    return 0;
}


