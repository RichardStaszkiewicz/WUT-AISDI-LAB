import time
# start = time.time()
# print("hello")
# end = time.time()
# print(end - start)
# # answer is measured in seconds
def InsertSort(array):
    size = len(array) - 1
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

def MergeSort():
    pass

if __name__ == '__main__':
    pass