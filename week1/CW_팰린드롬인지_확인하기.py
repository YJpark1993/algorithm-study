def check_palindrome(word):
    if len(word) < 2:
        return 1

    if word[0] != word[-1]:
        return 0
    
    return check_palindrome(word[1:-1])



def main():
    word = input()
    result = check_palindrome(word)
    print(result)


if __name__ == "__main__":
    main()
