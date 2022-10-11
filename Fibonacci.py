# Fibonacci series using for loop

def main():
    a, b = 0, 1
    while b < 10:
        print(b)
        a, b = b, a+b


if __name__ == '__main__':
    main()
