package SortingTechniques.SelectionSort;

import java.util.Scanner;
/************ Sorting Algorithm : Selection Sort **********************
 *
 * #GENERAL:
 * The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order)
 * from unsorted part and putting it at the beginning.
 * The algorithm maintains two sub-arrays in a given array:
 *      1) The sub-array which is already sorted.
 *      2) Remaining sub-array which is unsorted.
 *
 * In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted sub-array is picked
 * and moved to the sorted sub-array.
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
 * #RECURSION:
 *  * Recursive Bubble Sort has no performance/implementation advantages, but can be a good question to check one’s understanding of Selection Sort and recursion.
 *
 * #RECURSION IDEA:
 * 1. Base Case: If index == arraySize, return.
 * 2. Find minimum element in sub-array, then put it at the right place in sorted sub-array.
 * 3. Recur for all elements except last of current sub-array.
 *
 *******************************************************************/
public class RecursiveSelectionSort {
    // Return minimum index
    static int findMinIndex(int[] array, int startPoint, int endPoint)
    {
        if (startPoint == endPoint)
            return startPoint;

        // Find minimum of remaining elements
        int minIndex = findMinIndex(array, startPoint + 1, endPoint);

        // Return minimum of current and remaining.
        return (array[startPoint] < array[minIndex])? startPoint : minIndex;
    }

    // Recursive selection sort. n is size of a[] and index
    // is index of starting element.
    static void runRecursiveSelectionSort(int[] array, int arrayLength, int index)
    {
        // Return when starting and size are same
        if (index == arrayLength)
            return;

        // calling minimum index function for minimum index
        int minIndex = findMinIndex(array, index, arrayLength-1);

        // Swapping when index nd minimum index are not same
        if (minIndex != index){
            // swap
            int temp = array[minIndex];
            array[minIndex] = array[index];
            array[index] = temp;
        }
        // Recursively calling selection sort function
        runRecursiveSelectionSort(array, arrayLength, index + 1);
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

        runRecursiveSelectionSort(array, array.length, 0);
        System.out.println("Sorted array");
        printArray(array);
    }
}
