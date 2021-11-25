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
    
    string st;
    cin >> st;
    
    string ans = "quack";
    int sizes = st.size();
    vector<int> v(sizes);
    vector<int> w(sizes);
    
    bool check = true;
    for(int i=0;i<sizes;i++){
        if(st[i] != 'q')
            continue;
        // 처음이 q가 아니면 그냥 다 지나가서 새로
        
        int idx = i;
        int num = 0;
        
        while(num < 5 && idx < sizes){
            if(v[idx] == 0 && st[idx] == ans[num]){
                v[idx] = 1;     // 0이고, 같을 경우 1로 바꾸어 준다.
                num++;          // ans는 quack으로 num을 증가시켜 가면서 맞추어봐준다.
            }
            idx++;
        }
        if(num != 5)
            check = false;
        // 개수가 5개가 아니면 false이다.
        
        for(int j=i;j<idx;j++){
            w[j]++;
        }
    }
    
    int duck = 0;
    for(int i=0;i<sizes;i++){
        duck = max(duck, w[i]);
        
        if(w[i] == 0)
            check = false;
    }
    
    if(check)
        cout << duck;
    else
        cout << "-1";
    
    return 0;

}

// 아 몰라
