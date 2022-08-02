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
#include <unordered_map>
#include <set>
#include <sstream>

// control i처
#define MAX 987654321
#define mod 10007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;




int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int e, s;
    cin >> e >> s >> m;
    
    int i = 1;
    while(1){
        if((i - e) % 15 == 0 && (i - s) % 28 == 0 && (i - m) % 19 == 0){
            break;
            // i % 15 == e 와 (i - e) % 15 == 0 의 차이가 먼지는 모르겟지만 그냥 바꾸어서 냄
        }
        i++;
        
        // 주어진 값이 어디까지인지 모르므로 for로 범위를 제한하기 보다 while로 끝날때까지 그냥 계속 해주는 게 나을 것이다.
    }
    
    
    cout << i << '\n';

    
    return 0;

}



