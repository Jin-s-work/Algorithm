
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
#include <deque>

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,r;
//int l,k,t;
int h,w;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    bool check = false;
    
    cin >> s >> t;
    
    while(1){
        if(s.length() == t.length()){       // 길이 가 같을 때 같으면 true로 하고 끝
            if(s == t)
                check = true;
            break;
        }
        // 아닐경우 st를 t의 길이-1만큼의 인덱스에 넣어주고 pop해줌
        char st = t[t.length() - 1];
        t.pop_back();
        
        if(st == 'B')           // st가 B일 경우 reverse해준다. (뒤집는다.)
            reverse(t.begin(), t.end());
        
    }
    
    cout << check << '\n';

    return 0;
}


