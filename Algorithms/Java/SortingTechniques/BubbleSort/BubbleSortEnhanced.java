package SortingTechniques.BubbleSort;

import java.util.Scanner;

/************ Sorting Algorithm : Bubble Sort **********************
 *
 * Bubble sort is a primitive sorting algorithm.
 * It is implemented by comparing two neighbours
 * and swapping if needed them pairwise on each pass.
 *
 * The performance of the algorithm in worst case:
 * (n is the array size)
 *
 * No. of passes = (n-1)
 * No. of comparisons = 1 + 2 + 3+.....n-1= n(n-1)/2 [O(n^2)]
 * No. of swaps = 1 + 2 + 3 +......n-1 = n(n-1)/2 [O(n^2)]
 *
 * Worst Case Time Complexity : O(n^2) [^ => Exponentiation]
 * AuAuxiliary Space: O(1) [Since No Extra Space is Used]
 *
 *
 *
 * ----Best Case Time Complexity : O(n^2) [Due to the "little optimization" by stopping the algorithm if inner loop didn’t cause any swap] ----
 *******************************************************************/
public class BubbleSortEnhanced {

    static void runBubbleSort(int[] array) {
        int arrayLength = array.length;
        /* Outer Loop runs through the Entire List of Elements */
        for (int i = 0; i < arrayLength - 1; i++) {
            boolean isSwapped = false;
            /* Inner Loop runs through index 0 to (arrayLength-1) as Largest Number from the SubArray will be shifted to Last index of the SubArray each time Inner Loop Exits */
            for (int j = 0; j < arrayLength - i - 1; j++) {
                if (array[j] > array[j + 1]) {

                    /* Swap Neighbours: arr[j] and arr[j+1] */
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;

                    /* Set the flag when swapped */
                    isSwapped = true;
                }
            }

            if (!isSwapped) {
                /* If nothing was swapped, the array is sorted */
                break;
            }
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

        runBubbleSort(array);
        System.out.println("Sorted array");
        printArray(array);
    }
}
