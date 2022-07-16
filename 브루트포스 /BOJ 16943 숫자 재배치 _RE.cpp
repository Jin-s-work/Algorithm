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

// control i
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

    string a;
    int b;
    cin >> a >> b;
    
    sort(a.begin(), a.end());
    
    int Max = -1;
    do{
        
        int num = stoi(a);              // a는 string이므로 그때 그때 num으로 해준다.
        if(a[0] != '0' && num <= b){    // 처음이 0이면 안되고 num도 b이하여야 된다.
            if(Max < num || Max == -1)  // Max가 더 작고 -1일 경우 갱신
                Max = num;
        }
        // 앞이 0이 아닐경우와 -1일 경우를 잘 고려해 저ㅜ야 할 거 같다.
        
    }while(next_permutation(a.begin(), a.end()));
    
    
    cout << Max;
    
    
    return 0;

}
