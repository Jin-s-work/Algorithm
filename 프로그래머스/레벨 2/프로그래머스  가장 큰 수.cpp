

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a + b > b + a;
}
// 함수는 {}를 생략하면 안되고 그대로 적어줘야 한다.
// 서로 같이 문자열로 추가를 해서 a+b가 b+a보다 크게 정렬

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string>v;
    for(int i=0;i<numbers.size();i++){
        v.push_back(to_string(numbers[i]));
    }
    
    sort(v.begin(), v.end(), cmp);
    // 합하였을때 문자열이 제일 크게 비교
    
    for(int i=0;i<v.size();i++)
        answer += v[i];
    // 각각 넣어주면 끝
    
    if(answer[0] == '0')
        return "0";
    
    
    return answer;
}










// 전에 했던 긴 풀이
// 위에께 난 더 마음에 든다.
// 인줄 알았는데 next_permutation은 O(N)이어서 쓰면 안된다..
