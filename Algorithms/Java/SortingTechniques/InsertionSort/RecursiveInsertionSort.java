package SortingTechniques.InsertionSort;

import java.util.Scanner;

/************ Sorting Algorithm : Insertion Sort **********************
 *
 * #GENERAL:
 * The array is virtually split into a sorted and an unsorted part.
 * Values from the unsorted part are picked and placed at the correct position in the sorted part.
 * The performance of the algorithm in worst case:
 * (n is the array size)
 *
 * #ALGORITHM:
 * 1: Iterate from arr[1] to arr[n] over the array.
 * 2: Compare the current element (key) to its predecessor.
 * 3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.
 *
 * #USES:
 * Insertion sort is used when number of elements is small.
 * It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.
 *
 * #COMPARISONS:
 * No. of comparisons = 1 + 2 + 3+.....n-1= n(n-1)/2 [O(n^2)]
 * No. of swaps = 1 + 2 + 3 +......n-1 = n(n-1)/2 [O(n^2)]
 *
 * #TIME/SPACE COMPLEXITIES:
 * Worst Case Time Complexity : O(n^2) [^ => Exponentiation]
 * Best Case Time Complexity : O(n^2)
 * Auxiliary Space: O(1) [Since No Extra Space is Used] (In Place)
 *
 * #RECURSION:
 * Recursive Insertion Sort has no performance/implementation advantages, but can be a good question to check one’s understanding of Insertion Sort and recursion.
 *
 * #RECURSION IDEA:
 * Base Case: If array size is 1 or smaller, return.
 * Recursively sort first n-1 elements.
 * Insert last element at its correct position in sorted array.
 *
 * #BOUNDARY CASE:
 * Insertion sort takes maximum time to sort if elements are sorted in REVERSE order to what is intended.
 * And it takes minimum time (Order of n) when elements are already sorted.
 *******************************************************************/
public class RecursiveInsertionSort {

    static void runRecursiveInsertionSort(int[] array, int arrayLength) {


        // Base Case
        if (arrayLength <= 1) {
            return;
        }

        // Recursive Function Call by decrementing the size of the array by 1 each time.
        runRecursiveInsertionSort(array, arrayLength - 1);

        /*
         * For Example: arrayLength: 3
         * i.e. we only want to process first 3 elements, and find insertion point for array[2] between index 0 -> 1.
         */
        int lastElementOfSubArray = array[arrayLength - 1];
        int j = arrayLength - 2;

        // Iterate over the sorted sub-array to find insertion point by swapping the elements.
        while (j >= 0 && array[j] > lastElementOfSubArray) {
            array[j + 1] = array[j];
            j--;
        }

        // Update the correct value at insertion point
        array[j + 1] = lastElementOfSubArray;
    }

    /* Prints the array */
    static void printArray(int[] array) {
        for (int j : array) System.out.print(j + " ");
        System.out.println();
    }

    // Driver method to test above
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

        runRecursiveInsertionSort(array, array.length);
        System.out.println("Sorted array");
        printArray(array);
    }
}