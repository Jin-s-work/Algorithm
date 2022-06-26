

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    // 개수를 0으로 할당해준다.
    
    map<string, int> mp;
    map<string, set<string>> mp_report;
    // 신고한 아이디를 중복을 없애줘야하므로 set으로 처리한다.
    
    for(int i=0;i<id_list.size();i++){
        mp[id_list[i]] = i;
        // 각각의 스트링에 번호를 부여한다.
    }
    
    for(auto re : report){
        stringstream ss(re);
        string a, b;
        ss >> a >> b;
        
        mp_report[b].insert(a);
        // a가 b를 신고하였으므로, b에 a를 넣어줌
        // [신고당한 id, 신고한 id]
    }
    
    for(auto re : mp_report){
        if(re.second.size() >= k){   // k.second는 신고당한 사람에 관해 신고한 사람의 수
            for(auto ch : re.second){   // 즉 second일 경우 신고한 사람들이므로
                answer[mp[ch]]++;       // 그에 관하여 메일을 다 보내주었다.
            }
            // 위에서 mp[ch]에 관해서 번호를 할당해야 answer에서 그에 알맞은 인덱스에 추가됨
        }
    }
    
    
    return answer;
}



// #include <string>
// #include <vector>
// #include <sstream>
// #include <set>
// #include <map>


// using namespace std;

// vector<int> solution(vector<string> id_list, vector<string> report, int k) {
//     vector<int> answer(id_list.size(), 0);
    
//     map<string, int> mp;
//     map<string, set<string>> mp_report;
//     // 각 멤버의 위치를 map에 저장하고
//     // [신고 당한 id, 신고한 id]를 저장하는 map
    
//     for(int i=0;i<id_list.size();i++){
//         mp[id_list[i]] = i;
//         // mp[스트링]에 그 순서인 i를 할당한다.
//     }
    
//     for(auto r : report){
//         stringstream ss(r);
//         string a, b;
//         ss >> a >> b;
        
//         mp_report[b].insert(a);
//         // b에 a를 넣어준다.
//         // [신고당한 id, 신고한 id] 이므로
//     }
    
//     for(auto re : mp_report){
//         if(re.second.size() >= k){  // 신고한 id의 크기가 k 이상일 경우
//             for(auto ch : re.second){
//                 answer[mp[ch]]++;   // 그 id에 관한 수를 증가시킨다.
//             }   // 결과 메일을 받은 횟수가 answer이므로 second에 관해서 그 amp을 증가시킨다.
//         }
//     }
    
    
//     return answer;
// }

// // 한 유저가 같은 유저를 여러 번 신고한 경우 중복 처리됨


// // for(string s: report) {
// //     // 문자열 파싱
// //     int blank = s.find(' ');
// //     string from = s.substr(0, blank);
// //     string to = s.substr(blank);

// // 이렇게 사용해서 띄어쓰기나 다른 문자들 구분도 가능할 듯















