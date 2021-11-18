
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
    
    while(1){
        string st;
        getline(cin, st);
    
        if(st == "END"){
            break;
        }
        
        for(int i=st.length()-1;i>=0;i--)
            cout << st[i];
        cout << '\n';
    }
    
    
    return 0;

}

// 줄 자체를 받을 때는 getline
// reverse를 쓸 경우에는 띄어쓰기를 빼고 단어들 자체를 돌려줌
