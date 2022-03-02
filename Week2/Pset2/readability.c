// inder = 0.0588*L - 0.296 * S -15.8
// L = Number of letter/ (100 words)
// S = Number of sentences /  (100 words)
#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
char* get_text();
int get_number_letters(char* Text);
int string_size(char* Text);
int get_number_word (char* Text);
int get_number_sentences(char* Text);
int grade_level (int words, int letters, int sentences);

char LETTERS[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int main(){
    char* Text = get_text();
    int number_of_letters = get_number_letters(Text);
    int number_of_words = get_number_word (Text);
    int number_of_sentences = get_number_sentences(Text);
    if (number_of_words == 0 && number_of_letters!=0){
        number_of_words +=1;
    }
    else if (number_of_words > 0 && number_of_letters !=0){
        number_of_words+=1;
    }
    else if (number_of_words >0 && number_of_letters == 0){
        number_of_words =0;
    }
    int grade = grade_level (number_of_words, number_of_letters, number_of_sentences);

    if (grade > 16){
        printf("Grade 16+\n");

    }
    else if (grade < 1){
        printf("Before Grade 1\n");
    }
    else{
        printf("Grade %i\n", grade);
    }
    return 0;
}

char* get_text(){
    char* Text= get_string ("Text: ");
    return Text;
}

int get_number_letters(char* Text){
    int length = string_size(Text);
    int number_of_letters=0;
    for (int i = 0; i < length; i++ )
    {
        for (int j =0; j < sizeof(LETTERS)/sizeof(LETTERS[0]); j++){
            if(Text[i] == LETTERS[j] || toupper(Text[i])== LETTERS[j]){
                number_of_letters += 1;
            }
        }
    }
    return number_of_letters;
}

int get_number_word (char* Text){
     int length = string_size(Text);
     int number_of_words=0;
     for ( int i =0; i < length; i++){
         if (Text[i]==' '){
             number_of_words+=1;
         }
     }
     return number_of_words;
}

int get_number_sentences(char* Text){
     int length = string_size(Text);
     int number_of_sentences=0;
     for ( int i =0; i < length; i++){
         if (Text[i]=='.' || Text[i] == '!' || Text[i]== '?'){
             number_of_sentences+=1;
         }
     }
     return number_of_sentences;
}

int grade_level (int words, int letters, int sentences){
    float number_of_words = words;
    float number_of_sentences = sentences;
    float number_of_letters = letters;
    float L = (number_of_letters/number_of_words)*100;
    float S = (number_of_sentences/number_of_words)*100;
    float coleman= (0.0588*L) - (0.296*S) - (15.8);
    int  index = round(coleman);
    return index;
}

int string_size(char* str){
    int length = 0;
    while(str[length] !='\0' ){
      length++;
   }
   return length;
}