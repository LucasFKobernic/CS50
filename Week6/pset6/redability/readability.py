from cs50 import get_string
LETTERS = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']

def get_number_of_letters(Text):
	number_of_letters =0
	for i in range (len(Text)):
		for j in range (len(LETTERS)):
			if Text[i]== LETTERS[j] or Text[i].upper()==LETTERS[j]:
				number_of_letters+=1
	return number_of_letters
def get_number_of_words(Text):
	number_of_words=0
	for i in range (len(Text)):
		if Text[i] ==' ':
			number_of_words +=1
	return number_of_words
def get_number_of_sentences(Text):
	sentences=0
	for i in range (len(Text)):

		if Text[i]=='.' or Text[i]=='!' or Text[i]=='?':
			sentences+=1
	return sentences
def get_grade(letter, word, sentences):
	L = float(letter/word*100)
	S= float(sentences/word*100)
	coleman = float((0.0588*L)-(0.296*S)-15.8)
	return round(coleman,0)

def get_text():
	Text = get_string("Text: ")
	return Text

def main():
	Text = get_text()
	letter = get_number_of_letters(Text)
	words = get_number_of_words(Text)
	if words ==0 and letter != 0:
		words+=1
	elif words > 0 and letter != 0:
		words+=1
	elif words > 0 and letter ==0:
		words = 0
	sentences = get_number_of_sentences(Text)
	grade = int(get_grade(letter, words, sentences))
	print (letter)
	print (words)
	print (sentences)
	print (grade)
	if grade < 1:
		print("Before Grade 1")
	elif grade >16:
		print ("Grade 16+")
	else:
		print("Grade " +  str(grade))

if __name__ == "__main__":
    main()