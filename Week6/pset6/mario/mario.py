from cs50 import get_int

def main():
    height = get_int("Height: ")
    while (height <=0 or type(height) != int or height > 8):
        print("Invalid Number.")
        height = get_int("Height: ")
    pyramid_height = height+1
    for i in range(1, pyramid_height):
        for row in range(1,pyramid_height-i):
            print(" ", end="")
        for row in range(i):
            print("#", end="")
            if row == i-1:
                print("")
if __name__ == "__main__":

    main()