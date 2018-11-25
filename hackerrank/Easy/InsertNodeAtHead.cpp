//https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem



/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    SinglyLinkedListNode * head = new SinglyLinkedListNode(data);
    head->data = data;
    head->next = llist;

    return head;
}


