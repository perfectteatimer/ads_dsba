def notStandardSort(alphabet, text):
    sorted_text = ''.join(sorted(text, key=lambda x: alphabet.index(x)))
    print(sorted_text)

if __name__ == '__main__':
    s = input()
    t = input()
    notStandardSort(s, t)