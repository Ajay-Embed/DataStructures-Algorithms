package SortingTechniques.QuickSort;

import java.util.Scanner;

/************ Sorting Algorithm : Merge Sort **********************
 *
 * #GENERAL:
 * QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot.
 * There are many different versions of quickSort that pick pivot in different ways:
 * 1. Always pick first element as pivot.
 * 2. Always pick last element as pivot (implemented below)**
 * 3. Pick a random element as pivot.
 * 4. Pick median as pivot.
 *
 * The key process in quickSort is partition().
 * Target of partitions is, given an array and an element x of array as pivot,
 * put x at its correct position in sorted array and put all smaller elements (smaller than x) before x,
 * and put all greater elements (greater than x) after x. All this should be done in linear time.
 *
 * #TIME/SPACE COMPLEXITIES:
 * Best case Time Complexity: O(nLog(n))
 * Worst case Time Complexity: O(n^2) [^ => Exponentiation]
 * Average case Time Complexity: O(nLog(n))
 * Auxiliary Space: O(1)
 *
 * #RECURSION IDEA:
 * If low > high
 *      1. Decide the pivot and find the right place for the pivot
 *              :in our case we chose the last element to be the pivot
 *      2. Call quickSort for first half:
 *              Call quickSort(arr, low, p-1)
 *      3. Call quickSort for second half:
 *              Call quickSort(arr, p+1, high)
 *
 * #NOTE:
 * Please uncomment the lines in "/*" comment pattern in order to debug and print outputs to console.
 *******************************************************************/

public class QuickSort {

    // A utility function to swap two elements
    static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    // This function takes last element as pivot, places
    // the pivot element at its correct position in sorted
    // array, and places all smaller (smaller than pivot)
    // to left of pivot and all greater elements to right
    // of pivot
    static int partition(int[] arr, int low, int high) {

        // pivot
        int pivot = arr[high];
        /*
        System.out.println("Pivot: " + pivot);
         */

        // Index of smaller element and indicates the right position of pivot found so far
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            // If current element is smaller than the pivot
            /*
            System.out.println("Comparing arr[j]: " + arr[j] + " with pivot: " + pivot);
             */
            if (arr[j] < pivot) {
                // Increment index of smaller element
                i++;
                /*
                System.out.println("--Going to swap " + arr[i] + " with " + arr[j]);
                 */
                swap(arr, i, j);
            }
        }
        /*
        System.out.print("Array before putting the pivot in right place --> ");
        printArrayFromSpecificStartAndEndPosition(arr, low, high);
        System.out.println("--Going to put Pivot in right place by swapping " + arr[i + 1] + " with " + arr[high]);
         */
        swap(arr, i + 1, high);
        return (i + 1);
    }

    // The main function that implements QuickSort
    // arr[] --> Array to be sorted,
    // low --> Starting index,
    // high --> Ending index

    static void quickSort(int[] arr, int low, int high) {
        /*
        System.out.print("Going to Sort --> ");
        printArrayFromSpecificStartAndEndPosition(arr, low, high);
         */
        if (low < high) {
            // pi is partitioning index, arr[p] is now at right place
            int pi = partition(arr, low, high);

            /*
            System.out.print("Array after doing the partition step: ---> ");
            printArrayFromSpecificStartAndEndPosition(arr, low, high);
            System.out.println();
            */
            // Separately sort elements before partition and after partition
            /*
            System.out.print("Left Array --> ");
            printArrayFromSpecificStartAndEndPosition(arr, low, pi - 1);
            System.out.print("Right Array --> ");
            printArrayFromSpecificStartAndEndPosition(arr, pi + 1, high);
             */
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    // A utility function to print array of size n from specific start and end points
    static void printArrayFromSpecificStartAndEndPosition(int[] array, int start, int end) {
        if (start <= end) {
            for (int i = start; i <= end; i++) {
                System.out.print(array[i] + " ");
            }
        } else {
            System.out.print("{}");
        }
        System.out.println();
    }

    // Function to print an array
    static void printArray(int[] arr) {
        for (int j : arr) System.out.print(j + " ");
        System.out.println();
    }

    // Driver Code
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

        quickSort(array, 0, array.length - 1);
        System.out.println("Sorted array");
        printArray(array);
    }
}