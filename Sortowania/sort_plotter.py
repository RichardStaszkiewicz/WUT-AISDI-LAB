from matplotlib import pyplot as plt
import time
import sort


# observations = [10, 25, 50, 100, 500, 1000, 5000, 10000, 20000]
observations = [10, 25, 50]


def exe_time(function):
    def wrapper(*args, **kwargs):
        start = time.time()
        function(*args, **kwargs)
        return start - time.time()
    return wrapper


def sorted_array():
    IS = []
    QS_REC = []
    QS_IT = []
    MS = []
    for amount in observations:
        array = [x for x in range(0, amount)]
        IS.append(exe_time(sort.InsertSort(array)))
        array = [x for x in range(0, amount)]
        QS_REC.append(exe_time(sort.quick_sort_recursion(array, 0, amount)))
        array = [x for x in range(0, amount)]
        QS_IT.append(exe_time(sort.quick_sort_iterative(array, 0, amount)))
        array = [x for x in range(0, amount)]
        MS.append(exe_time(sort.MergeSort(array)))
    plt.plot(observations, IS, '-r', label="Insert Sort", markersize=3)
    plt.plot(observations, QS_REC, '-y', label="Quick Sort, Recursive", markersize=3)
    plt.plot(observations, QS_IT, '-b', label="Quick Sort, Iterative", markersize=3)
    plt.plot(observations, MS, '-g', label="Merge Sort", markersize=3)
    plt.legend()
    plt.title(label='Ordered array', loc='center')
    plt.gcf().savefig('Ordered Array', format='png')
    return


if __name__ == "__main__":
    sorted_array()
