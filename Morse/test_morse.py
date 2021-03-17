from morse import read_file, translate, expose
import pytest


def test_read_file():
    with open('text.txt', 'r') as handle:
        result = read_file(handle)
    answer = ['ala ma kota', 'a kot ma ale', 'a12b 3 c']
    assert result == answer


def test_read_file_wrong():
    with pytest.raises(FileNotFoundError):
        with open('xas.txt') as handle:
            result = read_file(handle)


def test_translate():
    text = 'ala ma kota a kot ma ale a12b 3 c'
    result = translate(text)
    answer = ".- .-.. .- / -- .- / -.- --- - .- / .- / -.- --- - / -- .- / .- .-.. . / .- -... / -.-. "
    assert result == answer


def test_translate_another():
    text = 'maciek gra'
    result = translate(text)
    answer = "-- .- -.-. .. . -.- / --. .-. .- "
    assert result == answer


def test_expose():
    text = "-- .-- .--"
    assert expose(text) == print(text)


def test_expose_another():
    text = ["-- .-- .--"]
    last_text = "-- .-- .--"
    assert expose(text) == print(last_text)
