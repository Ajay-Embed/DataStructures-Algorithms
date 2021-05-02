package SortingTechniques.BubbleSort;

import java.util.Scanner;

/************ Sorting Algorithm : Bubble Sort **********************
 *
 * #GENERAL:
 * Bubble sort is a primitive sorting algorithm.
 * It is implemented by comparing two neighbours
 * and swapping if needed them pairwise on each pass.
 *
 * #COMPARISONS:
 * No. of passes = (n-1)
 * No. of comparisons = 1 + 2 + 3+.....n-1= n(n-1)/2 [O(n^2)]
 * No. of swaps = 1 + 2 + 3 +......n-1 = n(n-1)/2 [O(n^2)]
 *
 * #TIME/SPACE COMPLEXITIES:
 * Worst Case Time Complexity : O(n^2) [^ => Exponentiation]
 * Best Case Time Complexity : O(n^2)
 * Auxiliary Space: O(1) [Since No Extra Space is Used]
 *
 * #RECURSION
 * Recursive Bubble Sort has no performance/implementation advantages, but can be a good question to check one’s understanding of Bubble Sort and recursion.
 *
 * #RECURSION IDEA:
 *
 * 1. Base Case: If array size is 1, return.
 * 2. Do One Pass of normal Bubble Sort. This pass fixes last element of current sub-array.
 * 3. Recur for all elements except last of current sub-array.
 *
 *******************************************************************/
public class RecursiveBubbleSort {

    static void runBubbleSort(int[] array, int arrayLength) {

        /*Base Case*/
        if (arrayLength == 1)
            return;

        /* One pass of bubble sort. After this pass, the largest element is shifted to the end. */
        for (int i = 0; i < arrayLength - 1; i++) {
            if (array[i] > array[i + 1]) {
                /* Swap Neighbours: arr[j] and arr[j+1] */
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
            runBubbleSort(array, arrayLength - 1);
        }
    }


    /* Prints the array */
    static void printArray(int[] array) {
        for (int j : array) System.out.print(j + " ");
        System.out.println();
    }

    // Driver method
    public static void main(String[] args) {
        // Using Scanner for Getting Input from User
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of elements in the array : ");
        int totalElements = scanner.nextInt();
        int[] array = new int[totalElements];

        System.out.println("Enter array elements:");
        for (int i = 0; i < totalElements; i++) {
            System.out.println("Enter " + i + " element: ");
            array[i] = scanner.nextInt();
        }

        System.out.println("Your input array :");
        printArray(array);

        runBubbleSort(array, totalElements);
        System.out.println("Sorted array");
        printArray(array);
    }
}
