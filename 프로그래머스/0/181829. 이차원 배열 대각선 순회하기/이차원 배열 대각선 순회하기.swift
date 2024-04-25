import Foundation

func solution(_ board:[[Int]], _ k:Int) -> Int {
    
    var ans = 0
    let n = board.count
    let m = board[0].count
    for i in 0..<n{
        for j in 0..<m{
            if i + j <= k{
                ans += Int(board[i][j])
            }
        }
    }
    
    return ans
}