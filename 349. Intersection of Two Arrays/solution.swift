class Solution {
    func intersection(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        return Array(Set(nums1+nums2))
    }
}