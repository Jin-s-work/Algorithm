import Foundation

func solution(_ my_strings:[String], _ parts:[[Int]]) -> String {
    
    var ans = ""
    for i in 0..<my_strings.count {
        let currentString = my_strings[i]
        let part = parts[i]
        
        // 현재 문자열에서 시작 인덱스와 종료 인덱스를 가져옵니다.
        let start = part[0]
        let end = part[1]
        
        // 부분 문자열을 잘라내어 결과에 추가합니다.
        let substring = currentString[currentString.index(currentString.startIndex, offsetBy: start)..<currentString.index(currentString.startIndex, offsetBy: end + 1)]
        ans += substring
    }
    
    return ans
}