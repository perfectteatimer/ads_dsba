from collections import Counter

def makePalindrome(tex):
    dict = Counter(tex)  # словарь буква - сколько встречалась раз
    left_part = []
    right_part = []
    center_part = []
    odd_added = False

    for letter, count in sorted(dict.items()):  # прохожусь по букве и сколько раз встречается
        if count % 2 != 0:  #  если кол-во нечетное значит нельзя составить палиндром и просто вставляем в центр
            if not odd_added:  # проверяем была ли уже добавлена нечетная буква
                center_part.append(letter)
                odd_added = True
        # если кол-во четное - можно составить палиндром
        left_part += letter * (count // 2)
        right_part += letter * (count // 2)

    right_part.sort(reverse=True)
    answer = ''.join(left_part) + ''.join(center_part) + ''.join(right_part)
    print(answer)

if __name__ == '__main__':
    length = int(input())
    text = input()
    makePalindrome(text)

