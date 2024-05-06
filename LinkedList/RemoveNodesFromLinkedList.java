package LinkedList;

import java.util.*;

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode removeNodes(ListNode head) {
        LinkedList<ListNode> list = new LinkedList<>();
        ListNode current = head;
        while (current != null) {
            while (!list.isEmpty() && list.peek().val < current.val) {
                list.pop();
            }
            list.push(current);
            current = current.next;
        }
        if (list.isEmpty()) {
            return null;
        }
        ListNode res = null;
        while (!list.isEmpty()) {
            ListNode node = list.pop();
            node.next = res;
            res = node;
        }
        return res;
    }
    // recursive sol
    // public ListNode removeNodes(ListNode head) {
    // if (head == null)
    // return null;
    // head.next = removeNodes(head.next);
    // return head.next != null && head.val < head.next.val ? head.next : head;
    // }
}

public class RemoveNodesFromLinkedList {

}
