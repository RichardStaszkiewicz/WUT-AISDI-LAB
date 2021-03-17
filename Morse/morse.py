import argparse
import sys


MORSE = {
    'a': '.-',
    'b': '-...',
    'c': '-.-.',
    'd': '-..',
    'e': '.',
    'f': '..-.',
    'g': '--.',
    'h': '....',
    'i': '..',
    'j': '.---',
    'k': '-.-',
    'l': '.-..',
    'm': '--',
    'n': '-.',
    'o': '---',
    'p': '.--.',
    'q': '--.-',
    'r': '.-.',
    's': '...',
    't': '-',
    'u': '..-',
    'v': '...-',
    'w': '.--',
    'x': '-..-',
    'y': '-.--',
    'z': '--..'
}


def parse(arguments):
    parser = argparse.ArgumentParser()
    parser.add_argument('file', help='File to translate')
    return parser.parse_args(arguments[1:])


def read_file(handle):
    return [line[:-1].lower() for line in handle]


def translate(line):
    ans = ''
    space = False
    for symbol in line:
        if symbol in MORSE:
            ans += MORSE[symbol]
            ans += ' '
            space = False
        else:
            if symbol == ' ' and not space:
                ans += '/ '
                space = True

    return ans


def main(arguments):
    args = parse(arguments)
    if args.file[-4:] != '.txt':
        return "Program requires file with .txt extension"

    try:
        with open(args.file, 'r') as handle:
            to_translate = read_file(handle)
    except (FileNotFoundError, PermissionError, IsADirectoryError):
        return "Error occurred while reading the file"

    return [translate(item) for item in to_translate]


def expose(ans):
    if type(ans) is not str:
        for item in ans:
            print(item)
    else:
        print(ans)


if __name__ == "__main__":
    ans = main(sys.argv)
    expose(ans)
