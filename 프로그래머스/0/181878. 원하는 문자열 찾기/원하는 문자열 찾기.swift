import Foundation

func solution(_ myString:String, _ pat:String) -> Int {
    
    var st1 = myString.lowercased()
    var st2 = pat.lowercased()
    var ans = 0
    if st1.contains(st2){
        ans = 1
    }
    else{
        ans = 0
    }
    
    return ans
}