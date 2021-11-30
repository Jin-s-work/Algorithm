

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    string st = "";
    st = to_string(n);
    // 복잡하게 안하고 그냥 n을 바로 string으로 받아줌
    
    sort(st.begin(),st.end(),greater<int>());   // 내림차순 정렬하고
    
    answer = stoll(st);     // 문자열을 long long으로 바로 한다.
    
    return answer;
}

// 다시 풀어보는 중이지만, 간단하게 할 수 있는 것을 너무 꼬아서 하는 것 같다.













