from matplotlib import pyplot as plt
import time
import sort


# observations = [10, 25, 50, 100, 500, 1000, 5000, 10000, 20000]
observations = [10, 25, 50]


def exe_time(function):
    def wrapper(*args, **kwargs):
        start = time.time()
        function(*args, **kwargs)
        return time.time() - start
    return wrapper

# @exe_time
# sort.MergeSort

# @exe_time
# sort.quick_sort_iterative

# @exe_time
# sort.quick_sort_recursion

# @exe_time
# sort.InsertSort


def sorted_array():
    IS = []
    QS_REC = []
    QS_IT = []
    MS = []
    for amount in observations:
        array = [x for x in range(0, amount)]
        x = exe_time(sort.InsertSort)(array)
        IS.append(x)
        array = [x for x in range(0, amount)]
        x = exe_time(sort.quick_sort_recursion)(array, 0, amount-1)
        QS_REC.append(x)
        array = [x for x in range(0, amount)]
        x = exe_time(sort.quick_sort_iterative)(array, 0, amount-1)
        QS_IT.append(x)
        array = [x for x in range(0, amount)]
        x = exe_time(sort.MergeSort)(array)
        MS.append(x)
    plt.plot(observations, IS, '-r', label="Insert Sort", markersize=3)
    plt.plot(observations, QS_REC, '-y', label="Quick Sort, Recursive")
    plt.plot(observations, QS_IT, '-b', label="Quick Sort, Iterative")
    plt.plot(observations, MS, '-g', label="Merge Sort", markersize=3)
    plt.legend()
    plt.title(label='Ordered array', loc='center')
    plt.gcf().savefig('Ordered Array', format='png')
    return


if __name__ == "__main__":
    sorted_array()
