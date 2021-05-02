package SortingTechniques.InsertionSort;

import java.util.Arrays;
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
 * #BOUNDARY CASES:
 * Insertion sort takes maximum time to sort if elements are sorted in REVERSE order to what is intended.
 * And it takes minimum time (Order of n) when elements are already sorted.
 *
 *******************************************************************/
public class BinaryInsertionSort {

    static void runBinaryInsertionSort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int key = array[i];

            /*
             * Arrays.binarySearch() return Index of the search key, if it is contained in the array; otherwise, (-(insertion point) – 1).
             * The insertion point is defined as the point at which the key would be inserted into the array.
             * The index of the first element greater than the key, or array.length if all elements in the array are less than the specified Key.
             */
            int insertionPointOfKey = Arrays.binarySearch(array, 0, i, key);
            int j = Math.abs(insertionPointOfKey + 1);

            /*
             * Uncomment these lines to print the values for better visualisation
             */
            // System.out.println("i: " + i + ", Key: " + key + ", Index: " + insertionPointOfKey);
            // System.out.println("Value of j: " + j);

            // Shifting array to one location right
            System.arraycopy(array, j, array, j + 1, i - j);

            // Placing element at its correct location
            array[j] = key;
        }
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

        runBinaryInsertionSort(array);
        System.out.println("Sorted array");
        printArray(array);
    }
}