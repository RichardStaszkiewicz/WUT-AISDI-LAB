from sort import InsertSort, MergeSort
from random import shuffle
# from time import time


def test_IS_normal_n10():
    array = [i for i in range(0, 10)]
    copy = [i for i in range(0, 10)]
    shuffle(array)
    assert InsertSort(array) == copy


def test_IS_normal_n1e4():
    array = [i for i in range(0, 10000)]
    copy = [i for i in range(0, 10000)]
    shuffle(array)
    assert InsertSort(array) == copy


def test_IS_unoptimal():
    array = [i for i in range(1000, 0, -1)]
    copy = [i for i in range(1, 1001)]
    assert InsertSort(array) == copy


def test_MS_normal_n10():
    array = [i for i in range(0, 10)]
    copy = [i for i in range(0, 10)]
    shuffle(array)
    assert MergeSort(array) == copy


def test_MS_normal_n1e4():
    array = [i for i in range(0, 10000)]
    copy = [i for i in range(0, 10000)]
    shuffle(array)
    assert MergeSort(array) == copy


def test_MS_unoptimal():
    array = [i for i in range(1000, 0, -1)]
    copy = [i for i in range(1, 1001)]
    assert MergeSort(array) == copy


if __name__ == "__main__":
    test_MS_normal_n10()
