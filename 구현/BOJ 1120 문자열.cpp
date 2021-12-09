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
    
    string a, b;
    cin >> a >> b;
    int Min = MAX;
    
    for(int i=0;i<b.length() - a.length() + 1;i++){
        int num = 0;
        
        for(int j=0;j<a.length();j++){
            if(a[j] != b[j+i])
                num++;
        }   // a를 조사 할때 0부터 하면서  최대의 차이(b-a+1)만큼까지만 움직이면서 확인해서 다르면
            // num을 증가시켜준다.
        
        Min = min(Min, num);
        // 최소의 num일 경우 갱신
    }
    
    cout << Min;
    
    // 여기서 말하는 차이가 길이가 아니라 문자간의 차이였다.
    
    return 0;
    
}

