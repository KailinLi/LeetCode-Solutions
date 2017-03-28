/**
 * Definition for an interval.
 * public class Interval {
 *   public var start: Int
 *   public var end: Int
 *   public init(_ start: Int, _ end: Int) {
 *     self.start = start
 *     self.end = end
 *   }
 * }
 */
struct Half {
    let position: Int
    let point: Bool
    init(_ number: Int, _ range: Bool) {
        position = number
        point = range
    }
}


class Solution {
    func merge(_ intervals: [Interval]) -> [Interval] {
        var answer = [Interval]()
        if intervals.isEmpty {
            return answer
        }
        var stack = [Half]()
        
        for item in intervals {
            var new = Half(item.start, true)
            stack.append(new)
            new = Half(item.end, false)
            stack.append(new)
        }
        
        stack.sort(by: {(first, second) in
            if first.position == second.position {
                if first.point && !second.point {
                    return true
                }
                else {
                    return false
                }
            }
            else {
                return first.position < second.position
            }
        })
        
        var left = 0
        var right = 0
        
        while right != stack.count - 1 {
            if stack[right].point {
                right += 1
                continue
            }
            left = right - 1
            while !stack[left].point {
                left -= 1
                continue
            }
            if left == 0 {
                if right - left == 1 {
                    right += 1
                }
                else {
                    right -= 1
                    left += 1
                    stack.removeSubrange(left...right)
                    right = left
                }
            }
            else if !stack[left - 1].point {
                if right - left == 1 {
                    right += 1
                }
                else {
                    right -= 1
                    left += 1
                    stack.removeSubrange(left...right)
                    right = left
                }
            }
            else {
                stack.removeSubrange(left...right)
                right = left
            }
        }
        for i in 0..<stack.count/2 {
            answer.append(Interval(stack[2 * i].position, stack[2 * i + 1].position))
        }
        return answer
    }
}