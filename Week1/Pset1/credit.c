#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

long get_credit_number(void); // Get the credit card number
int get_number_of_digits(long credit_number); //calculate the number of digits
int get_first_digits(long credit_number, int number_of_digits); // get the first digit
string classfy_card (int digits, int first_digit); //classfy the card (AMEX, VISA, Mastercard)
string verify_visa (long card_number, int number_of_digits);//aply the algorithmus

int main (void)
{

    long n = get_credit_number();
    int digits = get_number_of_digits(n);
    int first_digit = get_first_digits(n, digits);
    string card_type = classfy_card (digits, first_digit);
    string card_validation = verify_visa(n,digits);
    //printf ("%s\n", card_validation);

}

// This funcion ask the user for the credit card number and verify if it full the rules (it must have 13,15 or 16 digits, it must start with 3,4 or 5)
long get_credit_number(void)
{
    long number;
    int digits;
    int first_digit;
    string type_card;
    do
    {
        number = get_long("Credit Card Number: ");
        digits = get_number_of_digits(number);
        first_digit = get_first_digits(number,digits);
        type_card = classfy_card(digits, first_digit);
        printf("%s\n",type_card);

    } while (number <= 0 || strcmp(type_card, "INVALID") ==0);
    return number;
}

//This function get the total number of digits of the credit card number
int get_number_of_digits(long credit_number)
{
    long num = credit_number;
    int digits=0;
    for (int cout =0; num >0 || num != 0; cout++)
    {
        num=num/10;
        digits++;
    }
    return digits;

}

// This function get the first digit of the credit card number
int get_first_digits(long credit_number, int number_of_digits)
{
    long num = credit_number;
    long first_digit;
    for (int cout =0; cout<number_of_digits; cout++)
    {
        first_digit=num;
        num=num/10;
    }
    int fdigit = first_digit;
    return fdigit;

}
//This function classfy the card in VISA, AMEX or Mastercard by the credit card number rules (size an first digit).
string classfy_card (int digits, int first_digit)
{
    if (digits == 15 && first_digit ==3)
    {
        return "AMEX";
    }
    else if (digits ==16)
    {
        if (first_digit ==5)
        {
            return "MASTERCARD";
        }
        else if (first_digit ==4)
        {
            return "VISA";
        }
        else if (first_digit == 2)
        {
            return "MASTERCARD";
        }
        else
        {
            return "INVALID";
        }
    }
    else if (digits ==13 && first_digit ==4)
    {
        return "VISA"; // Visa
    }
     else
        {
            return "INVALID";
        }
}
// This function applies the Luhn's Algorithmus.
// To get each digit of the credit card number, this will be divided for a pow of 10 that matches with the number position (Ex: Number 2355 and we want the number ate positivon of 100, than we will divid 2355/100=23 (here we are handle with int/long))
// Than we will take this new divided Number and make Number%10, to get the digit. Ex: 23%10 = 3)
//to run the for iteration we need the number os digits from the credit card number.
string verify_visa (long card_number, int number_of_digits)
{
    long number = card_number;
    int summation_1=0;
    int summation_2=0;
    int digit;
    double ten_pow;
    for (int i = 0; i<number_of_digits; i++)
    {
        ten_pow = pow(10,i);
        digit = (number/((long) ten_pow))%10;
        if (i%2==0 || i==0)
        {
            summation_1+=digit;
        }
        else
        {
            if (digit*2 <10)
            {
                summation_2+=digit*2;
            }
            else //se o digito tiver dois algorimtos vai separar e somalos separados
            {
                summation_2+=get_first_digits(digit*2,2)+(digit*2)%10;
            }
        }
    }
    int last_digit= (summation_2+summation_1)%10;
    if (last_digit == 0){
        return "VALID CREDIT CARD";
    }
    else
    {
        return "INVALID CREDIT CARD";
    }


}