from matplotlib import pyplot as plt
import time
import sort


observations = [10, 25, 50, 100, 500, 1000, 5000, 10000, 25000, 50000]


def exe_time(function):
    def wrapper(*args, **kwargs):
        summ = 0
        for _ in range(3):
            start = time.time()
            function(*args, **kwargs)
            summ += time.time() - start
        return summ / 3
    return wrapper


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
    plt.gcf().savefig('Ordered Array.png', format='png')
    plt.clf()
    return


def PT_read(handle, amount):
    data = []
    while len(data) < amount:
        line = handle.readline()
        line = line.split(' ')
        for token in line:
            data.append(token)
    return data[:amount]


def PT_file_sorting():
    IS = []
    QS_REC = []
    QS_IT = []
    MS = []
    for amount in observations:
        with open('pan-tadeusz.txt', 'r') as handle:
            array = PT_read(handle, amount)
        backup = array.copy()
        x = exe_time(sort.InsertSort)(array)
        IS.append(x)
        array = backup.copy()
        x = exe_time(sort.quick_sort_recursion)(array, 0, amount-1)
        QS_REC.append(x)
        array = backup.copy()
        x = exe_time(sort.quick_sort_iterative)(array, 0, amount-1)
        QS_IT.append(x)
        array = backup.copy()
        x = exe_time(sort.MergeSort)(array)
        MS.append(x)
    plt.plot(observations, IS, '-r', label="Insert Sort", markersize=3)
    plt.plot(observations, QS_REC, '-y', label="Quick Sort, Recursive")
    plt.plot(observations, QS_IT, '-b', label="Quick Sort, Iterative")
    plt.plot(observations, MS, '-g', label="Merge Sort", markersize=3)
    plt.xscale('log')
    plt.yscale('log')
    plt.legend()
    plt.title(label='Pan Tadeusz text file', loc='center')
    plt.gcf().savefig('Pan Tadeusz text file.png', format='png')
    plt.clf()
    return


if __name__ == "__main__":
    sorted_array()
    PT_file_sorting()
