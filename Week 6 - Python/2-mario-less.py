def get_height():
    while True:
        try:
            height = int(input("Enter the height (1-8): "))
            if 1 <= height <= 8:
                return height
            else:
                print("Please enter a number between 1 and 8.")
        except ValueError:
            print("Invalid input. Please enter a numeric value.")


def print_triangle(height):
    for i in range(1, height + 1):
        print(" " * (height - i) + "#" * i)


if __name__ == "__main__":
    height = get_height()
    print_triangle(height)