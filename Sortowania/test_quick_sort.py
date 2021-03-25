from quick_sort import quick_sort_recursion, quick_sort_iterative
from random import shuffle


def test_quick_sort_recursion_normal():
    table = [4, 5, 2, 1, 8]
    quick_sort_recursion(table, 0, 4)
    assert table == [1, 2, 4, 5, 8]


def test_quick_sort_recursion_sorted_small():
    table = [1, 2, 3, 4, 5, 6, 7]
    quick_sort_recursion(table, 0, 6)
    assert table == [1, 2, 3, 4, 5, 6, 7]


def test_quick_sort_recursion_bigger():
    table = [i for i in range(0, 52152)]
    copy_table = [i for i in range(0, 52152)]
    shuffle(table)
    quick_sort_recursion(table, 0, len(table) - 1)
    assert table == copy_table


def test_quick_sort_recursion_sorted_long():
    table = [i for i in range(0, 1000000)]
    copy_table = [i for i in range(0, 1000000)]
    quick_sort_recursion(table, 0, len(table) - 1)
    assert table == copy_table


def test_quick_sort_recursion_shuffle_long():
    table = [i for i in range(0, 1000000)]
    copy_table = [i for i in range(0, 1000000)]
    shuffle(table)
    quick_sort_recursion(table, 0, len(table) - 1)
    assert table == copy_table


def test_quick_sort_recursion_string():
    table = ['b', 'e', 'q', 'c', 'up']
    quick_sort_recursion(table, 0, len(table) - 1)
    assert table == ['b', 'c', 'e', 'q', 'up']


def test_quick_sort_recursion_string_words():
    table = ['zenek', 'ala', 'kamil']
    quick_sort_recursion(table, 0, len(table) - 1)
    assert table == ['ala', 'kamil', 'zenek']


def test_quick_sort_iterative_normal():
    table = [4, 5, 2, 1, 8]
    quick_sort_iterative(table, 0, len(table) - 1)
    assert table == [1, 2, 4, 5, 8]


def test_quick_sort_iterative_sorted_short():
    table = [2, 3, 4, 5, 6, 7]
    quick_sort_iterative(table, 0, 5)
    assert table == [2, 3, 4, 5, 6, 7]


def test_quick_sort_iterative_medium():
    table = [i for i in range(0, 125125)]
    copy_table = [i for i in range(0, 125125)]
    shuffle(table)
    quick_sort_iterative(table, 0, len(table) - 1)
    assert table == copy_table


def test_quick_sort_iterative_sorted_long():
    table = [i for i in range(0, 1000000)]
    copy_table = [i for i in range(0, 1000000)]
    quick_sort_iterative(table, 0, len(table) - 1)
    assert table == copy_table


def test_quick_sort_iterative_shuffle_long():
    table = [i for i in range(0, 1000000)]
    copy_table = [i for i in range(0, 1000000)]
    shuffle(table)
    quick_sort_iterative(table, 0, len(table) - 1)
    assert table == copy_table


def test_quick_sort_iterative_string():
    table = ['b', 'e', 'q', 'c', 'd']
    quick_sort_iterative(table, 0, len(table) - 1)
    assert table == ['b', 'c', 'd', 'e', 'q']


def test_quick_sort_iterative_string_words():
    table = ['zenek', 'ala', 'kamil']
    quick_sort_iterative(table, 0, len(table) - 1)
    assert table == ['ala', 'kamil', 'zenek']
