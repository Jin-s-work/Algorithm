import Foundation

func solution(_ a:Int, _ b:Int, _ c:Int) -> Int {
    
    var ans = 0
    if a == b && b == c && c == a{
        ans = (a + b + c) * (a * a + b * b + c * c) * (a * a * a + b * b * b + c * c * c)
    }
    else if a != b && b != c && c != a{
        ans = a + b + c
    }
    else if (a == b && b != c) || (a == c && b != c) || (b == c && b != a){
        ans = (a + b + c) * (a * a + b * b + c * c)
    }
    
    return ans
}