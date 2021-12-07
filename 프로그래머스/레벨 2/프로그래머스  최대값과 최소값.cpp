

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 벡터에는 즉 문자열로 수들이 들어가있으므로 그를 비교해주는 함수를 만들어 sort
bool cmp(string a, string b){
    int x = stoi(a);
    int y = stoi(b);
    
    if(x <= y)
        return true;
    else
        return false;
}
// 즉 오름차순 형으로 정리해준다. 내림차순도 상관은 없다.

string solution(string s) {
    string answer = "";
    
    string tmp = "";
    vector<string>v;        // string을 받는 벡터로 해야한다.
    
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            v.push_back(tmp);
            tmp = "";
            continue;
        }
        else{
            tmp += s[i];
        }
    }
    v.push_back(tmp);
    // 마지막 남은 tmp도 넣어준다.
    
    sort(v.begin(), v.end(), cmp);
    // 위의 함수를 통하여 정렬
    
    answer += v[0];
    answer += " ";
    answer += v[v.size() - 1];
    
    
    return answer;
}

// 예전에는 그냥 공백이 보이고, 마이너스 기호가 보이면, 그 다음 숫자를 넣었는데 여기서는
// 잘 되지 않는다. (이는 원래 첫 항도 따로 처리해야 해서 귀찮았음)

// 그러나, 그 전까지 모든 기호를 넣다가 공백이 나오면 벡터에 추가하는 방법이 훨씬 간편해 보인다.













