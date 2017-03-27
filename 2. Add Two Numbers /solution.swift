class Solution {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        let list = ListNode.init(0)
        var p = list
        var p1 = l1
        var p2 = l2
        var go = 0
        while true {
            switch (p1, p2) {
            case (nil, nil):
                if go != 0 {
                    p.next = ListNode.init(1)
                    return list
                }
                else {
                    return list
                }
            case (_, nil):
                go = add(p1!.val, go, p)
                p1 = p1!.next
            case (nil, _):
                go = add(p2!.val, go, p)
                p2 = p2!.next
            default:
                go = add(p1!.val + go, p2!.val, p)
                p1 = p1!.next
                p2 = p2!.next
            }
            if p1 != nil || p2 != nil {
                p.next = ListNode.init(0)
                p = p.next!
            }
        }
    }
    func add(_ one: Int, _ two: Int, _ list: ListNode) -> Int {
        let get = one + two
        list.val = get % 10
        return get > 9 ? 1 : 0
    }
}