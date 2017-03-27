class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        for first in 0..<nums.endIndex {
            let minus = target - nums[first]
            for second in (first + 1)..<nums.endIndex {
                if nums[second] == minus {
                    return [first, second]
                }
            }
        }
        return []
    }
}