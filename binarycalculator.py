# Mazen Ahmed Mohamed ElShazly 20230579
# Yassin Ibrahim Samir Hafez Mohamed 20230463
# Ziyad Mohamed Ahmed ElHawary 20230564

print("**Binary Calculator**\nA)Insert New Numbers\nB)Exit")
while True:
    choice1 = str(input()).upper()
    if choice1 == 'A':
        Num1 = input("Enter the first number")
        valid_digits = '01'
        for n in Num1:
            if n not in valid_digits:
                print("Please enter a binary number")
                Num1 = input()
        print("**Please select the operation**\nA)Compute One's Complement\nB)Compute Two's Complement\nC)Addition\nD)Subtraction")
        choice2 = str(input()).upper()
        if choice2 != 'A' and choice2 != 'B' and choice2 != 'C' and choice2 != 'D':
            print("Please select a valid operation")
        if choice2 == 'A':
            Num1 = Num1
            solution1s = list()

            def ones_complement(x):
                for digit in x:
                    if int(digit) == 0:
                        solution1s.append(1)  # Checks if the integer is 0, then replaces it with 1 if true
                    elif int(digit) == 1:
                        solution1s.append(0)  # Checks if the integer is 1, then replaces it with 0 if true
                for digit in solution1s:
                    print(digit, end="")

            ones_complement(Num1)

        if choice2 == 'B':
            Num1 = Num1

            def twos_complement(x):
                solution2s = list()
                mono1 = 1
                mono1 = "1"
                for x in Num1:
                    if int(x) == 0:
                        solution2s.append(1)
                    elif int(x) == 1:
                        solution2s.append(0)
                # we get The One's Complement^^^
                mono1 = 1
                mono1 = str(mono1)
                max_length = len(solution2s)
                while len(mono1) < max_length:
                    mono1 = '0' + mono1
            # Here we make sure both lengths are same for addition to be possible^^^^
            # For example if user enters 1111 we make sure that we add 0001
                solution2s = solution2s[::-1]
                mono1 = mono1[::-1]
                result = ''  # Initialize the result as an empty string
                carry = 0  # Initialize the carry as 0
            # Loop through the bits of the binary numbers
                for i in range(len(solution2s)):
                    # Get the current bits at the index
                    bit1 = int(solution2s[i])
                    bit2 = int(mono1[i])
                # Add the current bits and the carry as a temporary sum
                    temp_sum = bit1 + bit2 + carry
                    resulting_bit = temp_sum % 2
                    result = str(resulting_bit) + result
                    # Add the resulting bit to the final result
                    # calculate the carry for the next loop
                    carry = temp_sum // 2
                    if carry:
                        result = '1' + result
                print(result)

            twos_complement(Num1)

        if choice2 == 'C':
            binary_str1 = str(Num1)
            binary_str2 = str(input("Please enter a second number\n"))
            valid_digits = '01'
            for n in binary_str2:
                if n not in valid_digits:
                    print("Please enter a binary number")
                    binary_str2 = str(input())

            def binary_addition(x, y):
                x = x[::-1]
                y = y[::-1]
                result = ''  # Initialize the result as an empty string
                carry = 0    # Initialize the carry as 0
                # Loop through the bits of the binary numbers
                for i in range(max_length):
                    # Get the current bits at the index
                    bit1 = int(x[i])
                    bit2 = int(y[i])
                # Add the current bits and the carry as a temporary sum
                    temp_sum = bit1 + bit2 + carry
                # Add the resulting bit to the final result
                    result_bit = temp_sum % 2
                    result = str(result_bit) + result
                # Calculate the carry for the next loop
                    carry = temp_sum // 2
            # If there's any remaining carry, add it to the result
                if carry:
                    result = '1' + result
                return result

            max_length = 0
            if len(binary_str1) > len(binary_str2):
                max_length = len(binary_str1)
            else:
                max_length = len(binary_str2)
            while len(binary_str1) < max_length:
                binary_str1 = '0' + binary_str1
            while len(binary_str2) < max_length:
                binary_str2 = '0' + binary_str2
    # Here we make sure both lengths are same for addition to be possible^^^^
    # For example if user enters 1111 and 10 we make sure that we add 0010

            print(binary_addition(binary_str1, binary_str2))
        if choice2 == 'D':
            Num1 = Num1
            Num2 = input("Please enter a second number")
            valid_digits = '01'
            for n in Num2:
                if n not in valid_digits:
                    print("Please enter a binary number")
                    Num2 = input()

            def binary_subtraction(x, y):
                max_len = 0
                if len(x) > len(y):
                    max_len = len(x)
                else:
                    max_len = len(y)
                while len(x) < max_len:
                    x = '0' + x
                while len(y) < max_len:
                    y = '0' + y
                x = x[::-1]
                y = y[::-1]
                result = ''
                borrow = 0
                for i in range(len(x)):
                    bit1 = int(x[i])
                    bit2 = int(y[i])
                    temp_diff = bit1 - bit2 - borrow
                    result_bit = temp_diff % 2
                    if temp_diff < 0:
                        borrow = 1
                    result = str(result_bit) + result
                return result
            print(binary_subtraction(Num1, Num2))
    print("\n**Binary Calculator**\nA)Insert New Numbers\nB)Exit")
    if choice1 == 'B':
        print("Exiting program")
    if choice1 != 'A' and choice1 != 'B':
        print("Please select a valid choice")
        print("**Binary Calculator**\nA)Insert New Numbers\nB)Exit")
