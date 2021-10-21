
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
int h;

vector<int>v;

void get(string s){
    
    int m = s.size();
    v.resize(s.size(), 0);      // v를 string 만큼 사이즈로 크기를 조정해준다음
    int j = 0;      // j는 움직이는 인덱스를 생각하면 댐
    
    for(int i=1;i<m;i++){
        while((j > 0) && (s[i] != s[j])){       // j가 양수이고 s의 i위치와 j위치가 다를 경우
            j = v[j-1];         // 다를 경우 v[j-1]로 다시 가서 j에 넣어준다.
        }
        if(s[i] == s[j]){       // 같을 경우
            j++;                // j를 늘려서
            v[i] = j;           // v[i]에 j를 저장해준다.
        }
        // 이런식으로 같으면 계속 j를 늘리고 아닐 경우 j를 0으로 해서 다시 해준다.
    }           // 문자열 접미사 접두사를 확인하는 배열을 만든다.
}

bool KMP(string s, string p){
    int n = s.size();
    int m = p.size();
    int j = 0;
    
    for(int i=0;i<n;i++){
        while((j > 0) && (s[i] != p[j])){
            j = v[j-1];
        }               // s와 p를 비교해서 그 곳이 다를 경우
        
        if(s[i] == p[j]){           // 같을 경우
            if(j == m - 1){         // 그리고 j가 맨 마지막까지 갔을 경우
                return true;        // true를 리턴하고 빼준다.
                break;
            }
            else                    // 아직 j가 m-1이 아닐 경우 계속 증가시켜줌
                j++;
        }
    }
    return false;
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s, p;
    
    cin >> s >> p;
    
    get(s);
    cout <<  KMP(s, p);
    
    
    
    return 0;
}
