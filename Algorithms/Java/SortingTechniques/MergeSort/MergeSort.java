package SortingTechniques.MergeSort;

import java.util.Scanner;

/************ Sorting Algorithm : Merge Sort **********************
 *
 * #GENERAL:
 * Merge Sort is a Divide and Conquer algorithm.
 * It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.
 * The merge() function is used for merging two halves.
 * The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
 *
 * #TIME/SPACE COMPLEXITIES:
 * Worst/Average/Best case Time Complexities: O(nLog(n))
 * Auxiliary Space: O(n) [Since extra space is used for maintaining a copy of the array]
 *
 * TIME/SPACE COMPLEXITIES EXPLANATION:
 * #Q: Why is time complexity O(n*Log n)?
 * #A: In merge sort we keep on dividing the array in two halves until the size of array
 *     becomes 1. So let's take an example of array with 8 elements.
 *
 *     How many time we will divide an array of 8 elements by 2 so it becomes 1.
 *     It's 3. The formula is something like this N/2^x=1 or N=2^x,where N is 8(no of elements)
 *     so if we apply log on both sides then x=LogN.Now as we are doing 3 passes as
 *     we have got value of x as 3 which stands for number of passes,
 *     so at each pass n elements are involved so we will multiply x by n,which gives
 *     my time complexity as O(nLog n)
 *
 * #RECURSION IDEA:
 * If r > l
 *      1. Find the middle point to divide the array into two halves:
 *              middle m = l+ (r-l)/2
 *      2. Call mergeSort for first half:
 *              Call mergeSort(arr, l, m)
 *      3. Call mergeSort for second half:
 *              Call mergeSort(arr, m+1, r)
 *      4. Merge the two halves sorted in step 2 and 3:
 *              Call merge(arr, l, m, r)
 *
 * #DRAWBACKS OF MERGE SORT:
 * 1. Slower comparative to the other sort algorithms for smaller tasks.
 * 2. Merge sort algorithm requires additional memory space of 0(n) for the temporary array .
 * 3. It goes through the whole process even if the  array is sorted.
 *
 * #NOTE:
 * Please uncomment the lines in "/*" comment pattern in order to debug and print outputs to console.
 *******************************************************************/
public class MergeSort {
    static void merge(int[] array, int left, int middle, int right) {
        // Find sizes of two sub-arrays to be merged
        int leftSubArraySize = middle - left + 1;
        int rightSubArraySize = right - middle;

        /*
         * System.out.println("leftSubArraySize: " + leftSubArraySize + ", rightSubArraySize: " + rightSubArraySize);
         */

        // Create temp arrays
        int[] leftSubArrayCopy = new int[leftSubArraySize];
        int[] rightSubArrayCopy = new int[rightSubArraySize];

        // Copy data to temp arrays
        if (leftSubArraySize >= 0) System.arraycopy(array, left, leftSubArrayCopy, 0, leftSubArraySize);
        if (rightSubArraySize >= 0) System.arraycopy(array, middle + 1, rightSubArrayCopy, 0, rightSubArraySize);

        // Merge the temp arrays
        // Initial indexes of first and second sub-arrays
        int i = 0, j = 0;

        // Initial index of merged sub-array
        int k = left;
        while (i < leftSubArraySize && j < rightSubArraySize) {
            /*
             System.out.println("i: " + i + ", j: " + j + ", k: " + k);
             System.out.println("Comparing leftSubArrayCopy[i]: " + leftSubArrayCopy[i] + " with rightSubArrayCopy[j]: " + rightSubArrayCopy[j]);
             */
            if (leftSubArrayCopy[i] <= rightSubArrayCopy[j]) {
                array[k] = leftSubArrayCopy[i];
                i++;
            } else {
                array[k] = rightSubArrayCopy[j];
                j++;
            }
            k++;
            /*
             System.out.print("After Swap: --> ");
             printArray(array);
             */
        }

        // Copy remaining elements of leftSubArraySize[] if any
        while (i < leftSubArraySize) {
            array[k] = leftSubArrayCopy[i];
            i++;
            k++;
        }

        // Copy remaining elements of leftSubArraySize[] if any
        while (j < rightSubArraySize) {
            array[k] = rightSubArrayCopy[j];
            j++;
            k++;
        }
        /*
         System.out.println("Array after merge");
         printArray(array);
         */
    }

    // Main function that sorts array[l..r] using
    // runMergeSort()
    static void runMergeSort(int[] array, int left, int right) {
        if (left < right) {
            // Find the middle point
            int middle = left + (right - left) / 2;

            // Sort first half
            /*
             System.out.print("Left Array --> ");
             printArrayFromSpecificStartAndEndPosition(array, left, middle);
             */
            runMergeSort(array, left, middle);

            // Sort second half
            /*
             System.out.print("Right Array --> ");
             printArrayFromSpecificStartAndEndPosition(array, middle + 1, right);
             */
            runMergeSort(array, middle + 1, right);

            // Merge the sorted halves
            /*
             System.out.println();
             System.out.println("Going for merge from array[left]: " + array[left] + " <---> array[right]: " + array[right]);
             System.out.println("l: " + left + ", m: " + middle + ", r: " + right);
             */
            merge(array, left, middle, right);
            /*
            System.out.println();
             */
        } /*
        else {
            System.out.println("------- l: " + left + " !< r: " + right);
        }
        */
    }

    /* A utility function to print array of size n */
    static void printArrayFromSpecificStartAndEndPosition(int[] array, int start, int end) {
        for (int i = start; i <= end; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    /* A utility function to print array of size n */
    static void printArray(int[] array) {
        for (int element : array) System.out.print(element + " ");
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

        runMergeSort(array, 0, array.length - 1);
        System.out.println("Sorted array");
        printArray(array);
    }
}

