#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}  // Constructor to initialize a node
};

// Function to add two numbers represented by linked lists
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);  // Create a dummy node to simplify code
    ListNode* current = dummyHead;  // Pointer to build the result linked list
    int carry = 0;  // Variable to store carry (when sum is greater than 9)

    // Loop until both lists are empty and no carry left
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int x = (l1 != nullptr) ? l1->val : 0;  // If l1 is not null, take its value; otherwise 0
        int y = (l2 != nullptr) ? l2->val : 0;  // If l2 is not null, take its value; otherwise 0

        int sum = x + y + carry;  // Add the values and the carry from the previous step
        carry = sum / 10;  // If sum is 10 or more, set carry to 1; otherwise 0
        current->next = new ListNode(sum % 10);  // Create a new node with the digit (sum % 10)

        current = current->next;  // Move the current pointer to the next node

        // Move to the next nodes in l1 and l2, if available
        if (l1 != nullptr) l1 = l1->next;
        if (l2 != nullptr) l2 = l2->next;
    }

    // Return the next node after the dummy node, which is the actual result
    return dummyHead->next;
}

// Helper function to create a linked list from an array of integers
ListNode* createList(int arr[], int size) {
    ListNode* head = new ListNode(arr[0]);  // Create the first node
    ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);  // Create new nodes and link them
        current = current->next;  // Move the pointer to the next node
    }

    return head;  // Return the head of the list
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";  // Print the value of each node
        head = head->next;  // Move to the next node
    }
    cout << endl;  // Print a newline after the list is printed
}

int main() {
    // Test the code with two example lists
    int arr1[] = {2, 4, 3};  // First number: 342
    int arr2[] = {5, 6, 4};  // Second number: 465

    ListNode* l1 = createList(arr1, 3);  // Create the first linked list
    ListNode* l2 = createList(arr2, 3);  // Create the second linked list

    ListNode* result = addTwoNumbers(l1, l2);  // Add the two numbers

    // Print the result linked list
    printList(result);  // Output should be 7 0 8 (because 342 + 465 = 807)

    return 0;
}
