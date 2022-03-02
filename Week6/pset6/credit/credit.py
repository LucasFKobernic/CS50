from cs50 import get_int



def get_credit_number():
    number = get_int("Credit Card Number: ")
    status = classify_card(get_number_of_digits(number), get_first_digits(number, get_number_of_digits(number)))
    return status
    #while True:
     #   number = get_int("Credit Card Number: ")
     #   status = classify_card(get_number_of_digits(number), get_first_digits(number, get_number_of_digits(number)))
     #   print(status)
     #   if status != "INVALID":
     #       return number

def get_number_of_digits(number):
    digits = 0
    while number > 0:
        number =int(number /10)
        digits+=1
    return digits

def get_first_digits(number, digits):
    return int(number/pow(10,digits-1))


def classify_card(digits, first_digit):
    if digits == 15 or first_digit == 3:
        return "AMEX"
    elif digits == 16:
        if first_digit == 5 or first_digit == 2:
            return "MASTERCARD"
        elif first_digit == 4:
            return "VISA"
        else:
            return "INVALID"
    elif digits == 13 and first_digit ==4:
        return "VISA"
    else:
        return "INVALID"

def verify_visa(number, digits):
    summation_1=0
    summation_2=0
    for i in range(digits):
        digit = int(number/pow(10,i))%10
        if i%2 == 0 or i == 0:
            summation_1 += digit
        else:
            if digit*2<10:
                summation_2 += digit*2
            else:
                summation_1 += get_first_digits(digit*2, 2)+(digit*2)%10
    if (summation_2 + summation_1)%10 == 0:
        return "VALID CREDIT CARD"
    else:
        return "INVALID CREDIT CARD"

def main():
    print(get_credit_number())
    #verify_visa(number, get_number_of_digits(number))


if __name__ == "__main__":
    main()