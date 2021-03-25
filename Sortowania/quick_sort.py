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


if __name__ == "__main__":
    pass
