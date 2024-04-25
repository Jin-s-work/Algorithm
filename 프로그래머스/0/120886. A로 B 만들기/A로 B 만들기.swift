import Foundation

func solution(_ before:String, _ after:String) -> Int {
    
    var st1 = Array(before)
    var st2 = Array(after)
    
    st1.sort()
    st2.sort()
    
    if st1 == st2{
        return 1
    }
    else{
        return 0
    }
    
    return 0
}