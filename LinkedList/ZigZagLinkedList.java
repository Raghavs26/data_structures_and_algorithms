package LinkedList;

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

class Solution {
    private static void swap(Node n1, Node n2) {
        int temp = n1.data;
        n1.data = n2.data;
        n2.data = temp;
    }

    public static Node zigZag(Node head) {
        if (head == null || head.next == null) {
            return head;
        }

        boolean isLess = true;
        Node current = head;

        while (current != null && current.next != null) {
            boolean check1 = isLess && current.data > current.next.data;
            boolean check2 = !isLess && current.data < current.next.data;
            if (check1 || check2) {
                swap(current, current.next);
            }
            current = current.next;
            isLess = !isLess;
        }
        return head;
    }
}

public class ZigZagLinkedList {

}
