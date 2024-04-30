import java.*;

class Node {
    char data;
    Node next;

    public Node(char data) {
        this.data = data;
        next = null;
    }
}

class Solution {
    private boolean isVowel(char ch) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    public Node arrangeCV(Node head) {
        Node vowels = new Node('0');
        Node consonants = new Node('0');
        Node v = vowels, c = consonants;
        Node current = head;
        while (current != null) {
            char ch = current.data;
            if (isVowel(ch)) {
                v.next = current;
                v = v.next;
            } else {
                c.next = current;
                c = c.next;
            }
            current = current.next;
        }
        v.next = consonants.next;
        c.next = null;
        return vowels.next;
    }
}

public class ArrangeConsonantsAndVowels {

}