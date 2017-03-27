/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public var val: Int
 *     public var next: ListNode?
 *     public init(_ val: Int) {
 *         self.val = val
 *         self.next = nil
 *     }
 * }
 */
class Solution {
    func oddEvenList(_ head: ListNode?) -> ListNode? {
        if head == nil || head!.next == nil {
            return head;
        }
        var ping = true
        let save: ListNode = head!.next!
        var odd: ListNode = head!.next!
        var even: ListNode = head!;
        while odd.next != nil && even.next != nil {
            if ping {
                even.next = odd.next
                even = odd.next!
                ping = false
                
            }
            else {
                odd.next = even.next
                odd = even.next!
                ping = true
            }
        }
        if ping {
            even.next = nil
        }
        else {
            odd.next = nil
        }
        even.next = save
        return head
    }
}