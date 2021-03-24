import time
# start = time.time()
# print("hello")
# end = time.time()
# print(end - start)
# # answer is measured in seconds


def InsertSort(array):
    size = len(array)
    for i in range(1, size):
        current = array[i]
        j = i - 1
        while (j >= 0) and (array[j] > current):
            array[j + 1] = array[j]
            j = j - 1
        array[j + 1] = current
    return array


def QuickSortREC():
    pass


def QuickSortITR():
    pass


def Consolidate(array1, array2):
    p1 = 0
    p2 = 0
    answer = []
    while (p1 < len(array1)) and (p2 < len(array2)):
        if array1[p1] > array2[p2]:
            answer.append(array2[p2])
            p2 += 1
        else:
            answer.append(array1[p1])
            p1 += 1
    if p1 >= len(array1):
        for x in array1[p1:]:
            answer.append(x)
    if p2 >= len(array2):
        for x in array2[p2:]:
            answer.append(x)

    return answer


def MergeSort(array):
    if len(array) == 1:
        return array
    middle = len(array) // 2
    return Consolidate(MergeSort(array[:middle]), MergeSort(array[middle:]))


if __name__ == '__main__':
    print(InsertSort([1, 43, -23, 23, 54, 23]))
    print(MergeSort([1, 43, -23, 23, 54, 23]))
