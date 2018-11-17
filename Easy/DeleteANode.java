//https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem



    /*
     * For your reference:
     *
     * SinglyLinkedListNode {
     *     int data;
     *     SinglyLinkedListNode next;
     * }
     *
     */
    static SinglyLinkedListNode deleteNode(SinglyLinkedListNode head, int position) {
        if (position == 0){ return head.next; }
        head.next = deleteNode(head.next, position-1);
        return head;
    }

