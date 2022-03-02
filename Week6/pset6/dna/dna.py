from cs50 import get_string
import cs50
from sys import argv
import csv




def main():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return 1
    database = argv[1]
    name = argv[2]
    csv_file =  database
    sequence_file =  name
    dict_suspects = {}
    STR= []
    number_STR=[]
    count = 0
    with open(csv_file, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            if count == 0:
                for i in range(1,len(row)):
                    STR.append(row[i])
            else:
                dict_suspects[row[0]] = []
                for i in range(1,len(row)):
                    dict_suspects[row[0]].append(row[i])
            count+=1

    with open(sequence_file, 'r') as file:
        reader = csv.reader(file)
        for row in reader:
            sequence = row[0]

    #STR é o DNA
    #sequence é a sequenca AGTA, por exemplo, que estou procurando.


    ANZAHL = []

    for j in range (0, len(STR)):
        N_ANZAHL = 0
        N_GANZAHL = 0
        for i in range(0, len(sequence)):
            if sequence[i] == STR[j][0]:
                STATUS = True
                n = i
                while STATUS:
                    if sequence[n:n+len(STR[j])] == STR[j]:
                        N_ANZAHL += 1
                        n  += len(STR[j])
                    else:
                        if N_ANZAHL > N_GANZAHL:
                            N_GANZAHL = N_ANZAHL
                        N_ANZAHL = 0
                        STATUS = False
        ANZAHL.append(N_GANZAHL)

    for suspect in dict_suspects:
        STR_CHECK =0
        for i in range (0, len(dict_suspects[suspect])):
            if dict_suspects[suspect][i] == str(ANZAHL[i]):
                STR_CHECK +=1
        if STR_CHECK == len(ANZAHL):
            print(suspect)
            break
    if STR_CHECK != len(ANZAHL):
        print("No match")


# Checking matching with the suspects


    """for STR_PIECE in STR:
        number=0
        for i in range (len(sequence)):
            if STR_PIECE[0] == sequence [i]:
                if STR_PIECE == sequence[i: i + len(STR_PIECE)]:
                    number+=1
        number_STR.append(number)
    print (number_STR)"""



if __name__ == '__main__':
    main()
    #/week7/pset6/dna/databases/small.csv