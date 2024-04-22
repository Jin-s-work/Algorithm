import Foundation

func solution(_ str1:String, _ str2:String) -> Int {
    
    var s = 0
    if str1.contains(str2){
        s = 1
    }
    else{
        s = 2
    }
    
    return s
}