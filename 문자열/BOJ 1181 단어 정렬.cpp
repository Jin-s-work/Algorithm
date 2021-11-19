
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

bool cmp(string s1, string s2){
    if(s1.size() == s2.size())
        return s1 < s2;
    else
        return s1.size() < s2.size();
    // 크기가 같으면 알파벳 순서대로 아니면, 크기대로
}


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> n;
    
    vector<string>v;
    
    for(int i=0;i<n;i++){
        
        string st;
        cin >> st;
        
        v.push_back(st);
        
    }
    
    sort(v.begin(), v.end(), cmp);
    
    string check;
    for(int i=0;i<n;i++){
        if(check == v[i])
            continue;
        cout << v[i] << '\n';
        
        check = v[i];
    }
    // 위와 같이 중복된 것을 피하기 위해 이렇게 해줘야 한다. 이것때문에 틀림

    
    return 0;

}


// while이랑 for문이랑 뭐가 다른지 했더니 위에서 while로 n을 이미 줄여버려서 밑에가 아예 안됨...
// 바보..
