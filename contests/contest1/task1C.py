def merge_sort(arr):
    if len(arr) > 1:
        midIndex = len(arr) // 2
        leftArray = arr[:midIndex]  # left subarray
        rightArray = arr[midIndex:]

        # merging left and right subarray
        merge_sort(leftArray)
        merge_sort(rightArray)

        left = right = arrayIndex = 0

        while left < len(leftArray) and right < len(rightArray):
            if leftArray[left] < rightArray[right]:
                arr[arrayIndex] = leftArray[left]
                left += 1
            else:
                arr[arrayIndex] = rightArray[right]
                right += 1
            arrayIndex += 1

        # add the elements that are left in leftArray
        while left < len(leftArray):
            arr[arrayIndex] = leftArray[left]
            left += 1
            arrayIndex += 1

        # add the elements that are left in rightArray
        while right < len(rightArray):
            arr[arrayIndex] = rightArray[right]
            right += 1
            arrayIndex += 1

def printArray(arr):
    for i in range(len(arr)):
        print(arr[i], end=" ")


if __name__ == '__main__':
    n = int(input())
    array = list(map(int, input().split()))
    merge_sort(array)
    printArray(array)
