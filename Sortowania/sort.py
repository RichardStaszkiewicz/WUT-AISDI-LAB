# import time
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


def quick_sort_recursion(array, start_point=None, end_point=None):
    if end_point - start_point > 0:
        split_point = divide_table(array, start_point, end_point)
        quick_sort_recursion(array, start_point, split_point - 1)
        quick_sort_recursion(array, split_point + 1, end_point)


def divide_table(array, start_point, end_point):
    actual_place = start_point
    split_point = (start_point + end_point - 1) // 2
    value_of_point = array[split_point]
    swap(array, split_point, end_point)
    for i in range(start_point, end_point):
        if array[i] < value_of_point:
            swap(array, i, actual_place)
            actual_place += 1
    swap(array, actual_place, end_point)
    return actual_place


def swap(array, first_position, second_position):
    array[first_position], array[second_position] = array[second_position], array[first_position]


def quick_sort_iterative(array, start_point, end_point):
    stack = [start_point, end_point]
    while stack:
        end_point = stack.pop()
        start_point = stack.pop()
        split_point = divide_table(array, start_point, end_point)
        if split_point - 1 > start_point:
            stack.append(start_point)
            stack.append(split_point - 1)
        if split_point + 1 < end_point:
            stack.append(split_point + 1)
            stack.append(end_point)


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
        for x in array2[p2:]:
            answer.append(x)
    if p2 >= len(array2):
        for x in array1[p1:]:
            answer.append(x)

    return answer


def MergeSort(array):
    if len(array) == 1:
        return array
    middle = len(array) // 2
    return Consolidate(MergeSort(array[:middle]), MergeSort(array[middle:]))


if __name__ == '__main__':
    pass
