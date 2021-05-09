package LinkedList;

import java.util.Scanner;

public class SinglyLinkedList {
    Node head; // head of list
    private static Scanner scanner;

    // Linked list Node.
    // This inner class is made static so that main() can access it
    static class Node {
        int data;
        Node next;

        // Constructor
        Node(int data) {
            this.data = data;
            this.next = null;
        }
    }

    // Method to insert a new node
    public static void insertAtEnd(SinglyLinkedList list, int data) {
        // Create a new node with given data
        Node newNode = new Node(data);
        newNode.next = null;

        // If the Linked List is empty, then make the new node as head
        if (list.head == null) {
            list.head = newNode;
        } else {
            // Else traverse till the last node and insert the new_node there
            Node currentNode = list.head;
            while (currentNode.next != null) {
                currentNode = currentNode.next;
            }

            // Insert the new_node at last node
            currentNode.next = newNode;
        }
    }

    // Method to insert a new node
    public static void insertAtBeginning(SinglyLinkedList list, int data) {
        // Create a new node with given data
        Node newNode = new Node(data);

        // If the Linked List is empty, then make the new node as head
        if (list.head != null) {
            newNode.next = list.head;
        }
        list.head = newNode;
    }

    // Method to print the LinkedList.
    public static void printList(SinglyLinkedList list) {
        Node currNode = list.head;

        System.out.print("LinkedList: ");

        // Traverse through the LinkedList
        while (currNode != null) {
            // Print the data at current node
            System.out.print(currNode.data + " ");

            // Go to next node
            currNode = currNode.next;
        }
        System.out.println();
    }

    private static void insertionOfValueAtPositionImplementation(SinglyLinkedList list, int position, int data) {
        //create new node.
        Node newNode = new Node(data);
        if (list.head == null) {
            //if head is null and position is not zero then exit.
            if (position != 0) {
                list.head = newNode;
                return;
            } else { //node set to the head.
                list.head = newNode;
            }
        }

        if (position == 0) {
            newNode.next = list.head;
            list.head = newNode;
            return;
        }

        Node currNode = list.head;
        Node prevNode = null;

        int i = 0;
        while (i < position - 1) {
            prevNode = currNode;
            currNode = currNode.next;
            if (currNode == null) {
                break;
            }
            i++;
        }

        newNode.next = currNode;
        prevNode.next = newNode;
    }

    private static void deletionAtPositionImplementation(SinglyLinkedList list, int position) {
        // Store head node
        Node currNode = list.head;
        Node prevNode = null;
        int deletedNodeData;

        // CASE 1:
        // If index is 0, then head node itself is to be deleted
        if (position == 1 && currNode != null) {
            deletedNodeData = list.head.data;
            list.head = currNode.next; // Changed head
            // Display the message
            System.out.println(position + " position element: " + deletedNodeData + " deleted");
            return;
        }

        // CASE 2:
        // If the index is greater than 0 but less than the size of LinkedList
        // The counter
        int counter = 1;

        // Count for the index to be deleted, keep track of the previous node as it is needed to change currNode.next
        while (currNode != null) {
            if (counter == position) {
                // Since the currNode is the required position Unlink currNode from linked list
                deletedNodeData = currNode.data;
                prevNode.next = currNode.next;

                // Display the message
                System.out.println(position + " position element: " + deletedNodeData + " deleted");
                break;
            } else {
                // If current position is not the index continue to next node
                prevNode = currNode;
                currNode = currNode.next;
                counter++;
            }
        }

        // CASE 3:
        // The index is greater than the size of the LinkedList
        // If the position element was found, it should be at currNode, Therefore the currNode shall not be null
        if (currNode == null) {
            // Display the message
            System.out.println(position + " position element not found");
        }
    }

    private static void deletionByKeyImplementation(SinglyLinkedList list, int key) {
        // Store head node
        Node currNode = list.head;
        Node prevNode = null;

        // CASE 1:
        // If head node itself holds the key to be deleted
        if (currNode != null && currNode.data == key) {
            list.head = currNode.next; // Changed head
            // Display the message
            System.out.println(key + " found and deleted");
            return;
        }

        // CASE 2:
        // If the key is somewhere other than at head
        // Search for the key to be deleted, keep track of the previous node as it is needed to change currNode.next
        while (currNode != null && currNode.data != key) {
            // If currNode does not hold key
            // continue to next node
            prevNode = currNode;
            currNode = currNode.next;
        }

        // If the key was present, it should be at currNode. Therefore the currNode shall not be null
        if (currNode != null) {
            // Since the key is at currNode
            // Unlink currNode from linked list
            prevNode.next = currNode.next;

            // Display the message
            System.out.println(key + " found and deleted");
        }

        // CASE 3: The key is not present
        // If key was not present in linked list.
        // currNode should be null
        if (currNode == null) {
            // Display the message
            System.out.println(key + " not found");
        }
    }

    private static int lengthOfLinkedList(SinglyLinkedList list) {

        int lengthOfLinkedList = 1;
        if (list.head == null) {
            return 0;
        } else {
            Node currNode = list.head;
            while (currNode.next != null) {
                currNode = currNode.next;
                lengthOfLinkedList++;
            }
            return lengthOfLinkedList;
        }
    }

    private static void deletionByKey(SinglyLinkedList list) {
        System.out.println("Enter the position you want to delete the element from");
        System.out.print("Enter the Key: ");
        int key = scanner.nextInt();

        deletionByKeyImplementation(list, key);
        printList(list);
    }

    private static void deletionAtPosition(SinglyLinkedList list) {
        System.out.println("Enter the position you want to delete the element from");
        System.out.print("Enter the Position: ");
        int position = scanner.nextInt();

        deletionAtPositionImplementation(list, position);
        printList(list);
    }

    private static void insertionAtPosition(SinglyLinkedList list) {
        System.out.println("Enter the position and Value for new insertion");
        System.out.print("Enter the position: ");
        int position = scanner.nextInt();
        System.out.print("Enter the value: ");
        int value = scanner.nextInt();

        insertionOfValueAtPositionImplementation(list, position, value);
        printList(list);
    }

    // Driver code
    public static void main(String[] args) {

        // Using Scanner for Getting Input from User
        scanner = new Scanner(System.in);
        System.out.print("Enter the number of elements in the array : ");
        int totalElements = scanner.nextInt();

        /* Start with the empty list. */
        SinglyLinkedList list = new SinglyLinkedList();

        System.out.println("Please choose the insertion strategy:\nEnter 1 to Insert Elements at End\nEnter 2 to Insert Elements at Beginning");
        int insertionStrategy = scanner.nextInt();
        System.out.println("Enter array elements:");
        for (int i = 1; i <= totalElements; i++) {
            System.out.println("Enter " + i + " element: ");
            if (insertionStrategy == 1) {
                insertAtEnd(list, scanner.nextInt());
            } else {
                insertAtBeginning(list, scanner.nextInt());
            }
        }

        // Print the LinkedList
        printList(list);

        System.out.println("***************** Insertion at Position *****************");
        insertionAtPosition(list);

        System.out.println("***************** Deletion at Position *****************");
        deletionAtPosition(list);

        System.out.println("***************** Deletion by Key *****************");
        deletionByKey(list);

        System.out.println("Length of Linked List: " + lengthOfLinkedList(list));
    }
}