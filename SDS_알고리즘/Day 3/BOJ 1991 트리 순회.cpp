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

// control i
#define MAX 987654321
#define mod 1000000007
#define pii pair<int, int>
using ll = long long;
using namespace std;
int n,m,k;
int l,r,t;
int h;


struct node{
    char left;
    char right;
};      // 구조체 만든다.

struct node st[101];

void preorder(char root){
    if(root == '.')
        return;
    // .일 경우 그냥 넘어감
    else{
        cout << root;
        preorder(st[root].left);
        preorder(st[root].right);
    }
}

void inorder(char root){
    if(root == '.')
        return;
    // .일 경우 그냥 넘어감
    else{
        inorder(st[root].left);
        cout << root;
        inorder(st[root].right);
    }
}

void postorder(char root){
    if(root == '.')
        return;
    // .일 경우 그냥 넘어감
    else{
        postorder(st[root].left);
        postorder(st[root].right);
        cout << root;
    }
}

// 셋다 붙어서 출력해야되므로 그냥 cout한다.

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> n;
    
    char a, b, c;
    
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        
        st[a].left = b;
        st[a].right = c;
        // 구조체를 사용해 a의 left는 b, right는 c
    }
    
    
    preorder('A');
    cout << '\n';
    
    inorder('A');
    cout << '\n';
    
    postorder('A');
    cout << '\n';
    
    

    return 0;

}


// 전위 순위는
// 1. 노드 출력
// 2. 왼쪽
// 3. 오른쪽

// struct 구조체 사용 익히기..!
