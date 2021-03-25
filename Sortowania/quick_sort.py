def quick_sort_recursion(array, start_point, end_point):
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


def quick_sort_linear():
    pass


if __name__ == "__main__":
    k = [7, 6, 5, 4, 3, 2, 1]
    quick_sort_recursion(k, 0, 6)
    print(k)
