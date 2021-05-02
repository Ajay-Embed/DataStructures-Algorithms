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
 * #ENHANCEMENT:
 * The idea is to take also the maximum on every pass and place it at its correct position.
 * So in every pass, we keep track of both maximum and minimum and array becomes sorted from both ends.
 *
 * #NOTE:
 * Please uncomment the lines in "/*" comments in order to debug and print important outputs to console.
 *******************************************************************/
public class EnhancedSelectionSort {

    static void runEnhancedSelectionSort(int[] array) {
        int arrayLength = array.length;

        // One by one move boundary of unsorted sub-array from both ends
        for (int i = 0, j = arrayLength - 1; i < j; i++, j--) {
            /*
            printArray(array);
            System.out.println("i: " + i + ", j: " + j);
            System.out.println("array[i]: " + array[i] + ", array[j]: " + array[j]);
             */

            // initialising the minIndex, maxIndex, minValue, maxValue
            int minIndex = i;
            int maxIndex = i;
            int maxValue = array[i];
            int minValue = array[i];

            // Finding minValue, maxValue, minIndex, maxIndex from the unsorted sub-array
            for (int k = i; k <= j; k++) {
                if (array[k] < minValue) {
                    minValue = array[k];
                    minIndex = k;
                } else if (array[k] > maxValue) {
                    maxIndex = k;
                    maxValue = array[k];
                }
            }

            /*
            System.out.println("MinIndex: " + minValue + ", MaxValue: " + maxValue);
            System.out.println("MinValue: " + minValue + ", MaxValue: " + maxValue);
             */

            // Swapping the minIndex Value with the LEFT most index of the unsorted Array.
            swap(array, i, minIndex);

            //Swapping the maxIndex Value with the RIGHT most index of the unsorted array.
            //Shifting the max. The equal condition
            //happens if we shifted the max to arr[min_i]
            //in the previous swap.

            if (array[minIndex] == maxValue) {
                /*
                 System.out.println("array[minIndex]: " + minIndex + " == " + " maxValue: " + maxValue);
                 */
                swap(array, j, minIndex);
            } else
                swap(array, j, maxIndex);
            /*
            System.out.println();
             */
        }
    }

    // Swapping the values present on the provided indexes i and j
    static int[] swap(int[] array, int i, int j) {
        /*
        System.out.println("Swapping: " + array[i] + " with " + array[j]);
        */
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        /*
        printArray(array);
         */
        return array;
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

        runEnhancedSelectionSort(array);
        System.out.println("Sorted array");
        printArray(array);
    }
}