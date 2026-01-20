"""
    Bubble sort is a sorting algorithm in which every element is compared and swapped so that the last index is filled
    with the correct element first
"""


def bubble_sort(arr, order=None):
    """
    :param arr: array which needs to be sorted
    :param order: Order of sorting, '1' for Descending, otherwise Ascending
    :return: Sorted Array is returned

    Time Complexity:  O(n^2)
    Space Complexity: O(1)
    """
    arr_len = len(arr)
    for i in range(arr_len - 1):
        for j in range(arr_len - 1 - i):
            if order == '1':
                if arr[j] < arr[j + 1]:
                    arr[j + 1], arr[j] = arr[j], arr[j + 1]
            else:
                if arr[j] > arr[j + 1]:
                    arr[j + 1], arr[j] = arr[j], arr[j + 1]
    return arr


if __name__ == "__main__":
    n = input("Enter space separated values of the array: ")
    input_arr = list()
    for ele in n.split(" "):
        try:
            input_arr.append(int(ele))
        except ValueError:
            continue
    print(f"Input Array: {input_arr}")
    direction = input("Press 1 for Descending Order: ")
    print(f"Sorted Array: {bubble_sort(input_arr, direction)}")
