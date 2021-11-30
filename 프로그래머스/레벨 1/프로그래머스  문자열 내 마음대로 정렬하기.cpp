
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num;
bool cmp(string st1, string st2){
    if(st1[num] != st2[num])
        return st1[num] < st2[num];
    // 다를 경우 오름차순으로 해줌
    else
        return st1 < st2;
    // 인덱스에 같은 문자열이 있을 경우, 앞선 문자열이 앞쪽에 위치하게 한다.
}
// 점점 커지는 식으로 하겠다는 뜻..

vector<string> solution(vector<string> strings, int n) {
    
    num = n;
    sort(strings.begin(), strings.end(), cmp);
    
    
    return strings;
}

// 다른 경우를 확인 하여 정렬해 주어야 하고, num은 전역 변수이므로 설정해 놓으면, 비교 함수에서 사용이 가능하다.











