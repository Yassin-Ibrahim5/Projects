# Mazen Ahmed Mohamed ElShazly 20230579
# Yassin Ibrahim Samir Hafez Mohamed 20230463
# Ziyad Mohamed Ahmed ElHawary 20230564

def decimal_to_binary(decimal_number):
    binary_number = ""
    while decimal_number > 0:
        remainder = decimal_number % 2
        binary_number = str(remainder) + binary_number
        decimal_number //= 2
    return binary_number if binary_number != "" else "0"


def decimal_to_octal(decimal_number):
    octal_number = ""
    while decimal_number != 0:
        remainder = decimal_number % 8
        octal_number = str(remainder) + octal_number
        decimal_number = decimal_number // 8
    return octal_number if octal_number != "" else "0"


def decimal_to_hexadecimal(decimal_number):

    hexadecimal_number = []
    while decimal_number > 0:
        remainder = decimal_number % 16
        hexadecimal_remainder = remainder
        if remainder == 10:
            hexadecimal_remainder = "A"
        elif remainder == 11:
            hexadecimal_remainder = "B"
        elif remainder == 12:
            hexadecimal_remainder = "C"
        elif remainder == 13:
            hexadecimal_remainder = "D"
        elif remainder == 14:
            hexadecimal_remainder = "E"
        elif remainder == 15:
            hexadecimal_remainder = "F"
        hexadecimal_number.insert(0, hexadecimal_remainder)
        decimal_number = decimal_number // 16
    return hexadecimal_number if hexadecimal_number != '' else '0'


def binary_to_decimal(binary_number):
    decimal_number = 0
    binary_number = binary_number[::-1]
    for digit in range(len(binary_number)):
        if binary_number[digit] == "1":
            decimal_number += 2 ** digit
    return decimal_number


def binary_to_octal(binary_number):
    decimal_number = binary_to_decimal(binary_number)
    return decimal_to_octal(decimal_number)


def binary_to_hexadecimal(binary_number):
    decimal_number = binary_to_decimal(binary_number)
    return decimal_to_hexadecimal(decimal_number)


def octal_to_decimal(octal_number):
    decimal_number = 0
    octal_number = octal_number[::-1]
    for digit in range(len(octal_number)):
        decimal_number += int(octal_number[digit]) * (8 ** digit)
    return decimal_number


def octal_to_binary(octal_number):
    decimal_number = octal_to_decimal(octal_number)
    return decimal_to_binary(decimal_number)


def octal_to_hexadecimal(octal_number):
    decimal_number = octal_to_decimal(octal_number)
    return decimal_to_hexadecimal(decimal_number)


def hexadecimal_to_decimal(hexadecimal_number):
    decimal_number = 0
    hex_characters = "0123456789ABCDEF"
    hexadecimal_number = hexadecimal_number[::-1]
    for digit in range(len(hexadecimal_number)):
        decimal_number += hex_characters.index(hexadecimal_number[digit].upper()) * (16 ** digit)
    return decimal_number


def hexadecimal_to_binary(hexadecimal_number):
    decimal_number = hexadecimal_to_decimal(hexadecimal_number)
    return decimal_to_binary(decimal_number)


def hexadecimal_to_octal(hexadecimal_number):
    decimal_number = hexadecimal_to_decimal(hexadecimal_number)
    return decimal_to_octal(decimal_number)


def main():
    while True:
        print("** numbering system converter **")
        print("A) Insert a new number")
        print("B) Exit program")
        first_choice = input("Your choice: ").upper()

        if first_choice == "A":
            number = input("Please insert a number: ")
            print("** Please select the base you want to convert a number from **")
            print("A) Decimal")
            print("B) Binary")
            print("C) Octal")
            print("D) Hexadecimal")
            first_base = input("Your choice: ").upper()

            if first_base in ["A", "B", "C", "D"]:
                print("** Please select the base you want to convert a number to **")
                print("A) Decimal")
                print("B) Binary")
                print("C) Octal")
                print("D) Hexadecimal")
                second_base = input("Your choice: ").upper()

                if second_base in ["A", "B", "C", "D"]:
                    try:
                        if first_base == "A":
                            decimal_number = int(number)
                        elif first_base == "B":
                            decimal_number = binary_to_decimal(number)
                        elif first_base == "C":
                            decimal_number = octal_to_decimal(number)
                        elif first_base == "D":
                            decimal_number = hexadecimal_to_decimal(number)
                        else:
                            print("Invalid choice for first base.")
                            continue

                        if second_base == "A":
                            result = decimal_number
                        elif second_base == "B":
                            result = decimal_to_binary(decimal_number)
                        elif second_base == "C":
                            result = decimal_to_octal(decimal_number)
                        elif second_base == "D":
                            result = decimal_to_hexadecimal(decimal_number)
                        else:
                            print("Invalid choice for second base.")
                            continue

                        print(f"Result: {result}")

                    except ValueError:
                        print("Invalid number input.")
                else:
                    print("Please select a valid choice for first base.")
            else:
                print("Please select a valid choice for second base.")

        elif first_choice == "B":
            print("Exiting program.")
            break

        else:
            print("Please select a valid choice.")


if __name__ == "__main__":
    main()
