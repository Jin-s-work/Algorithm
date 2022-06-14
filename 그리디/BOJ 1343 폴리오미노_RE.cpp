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

    
    string st;
    string ans;
    cin >> st;
    
    for(int i=0;i<st.length();){
        
        if(st[i] == '.'){
            ans += '.';
            i += 1;
            
            continue;
            // .이 나왔을 경우에는 밑에를 생략하고 넘어간다.
        }
        
        int num = 0;
        
        // 이 밑은 .이 아닐 때 즉 X가 나올때
        for(int j=i;j < st.size() && st[j] == 'X';j++){
            num++;
        }
        // 인덱스인 i부터 범위 내에서 X가 나오는 때마다 num을 더해다 준다.
        
        i += num;
        // 인덱스인 i도 num만큼 더해서 X가 끝나는 곳 까지 가기
        
        if(num % 2 != 0){
            cout << "-1" << '\n';
            return 0;
        }
        // num이 2로 안나누어지면 불가능
        
        
        while(1){
            if(num >= 4){
                ans += "AAAA";
                num -= 4;
            }
            // 4보다 클 경우
            else if(num == 2){
                ans += "BB";
                num -= 2;
            }
            else
                break;
        }
    }
    
    cout << ans;
    
    
    
    return 0;

}



//string s;
//cin >> s;
//
//while (s.find("XXXX") != string::npos)
//s = s.replace(s.find("XXXX"), 4, "AAAA");
//while (s.find("XX") != string::npos)
//s = s.replace(s.find("XX"), 2, "BB");
//if (s.find("X") != string::npos)
//cout << -1;
//else
//cout << s;

// 이 처럼 그냥 replace로도 그냥 할 수 있는 듯..?
