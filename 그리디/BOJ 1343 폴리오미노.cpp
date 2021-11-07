
#include <iostream>  // stdio.h 와 같은 것
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <cstring>
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

string st;
string ans;


int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    
    cin >> st;
    
    
    for(int i=0;i<st.size();){
        // 계속 왜 밑에 i+=1이나 i+=num이 있는지 의문이었는데, 앞의 제시문에서 .이 있는 경우나
        // X를 센 수인 num만큼 더해주는 것임을 알 수 있었다.
        
        if(st[i] == '.'){
            ans += '.';
            i += 1;
            
            continue;
            // .이 나올 경우 i를 그냥 증가시켜주고 넘어간다.
        }
        
        int num = 0;
        
        for(int j=i;j<st.size() && st[j] == 'X';j++){
            num++;
            // j가 i부터 사이즈보다 작고, 계속 X일때는 num을 증가시켜준다.
        }
        
        i += num;
        // i도 이 num에 따라 더해진다.
        
        if(num % 2 != 0){
            cout << "-1" << '\n';
            return 0;
        }
        // num이 홀수이면 안되므로 바로 -1을 리턴한다.
        
        while(1){
            if(num >= 4){
                ans += "AAAA";
                num -= 4;
            }
            // num이 4이상이면 AAAA 추가
            else if(num == 2){
                ans += "BB";
                num -= 2;
            }
            // num이 마지막으로 2면 BB 추가
            else
                break;
            // 끝나면 그냥 break
        }
        
        
    }
    
    
    cout << ans;
    
    return 0;
}

