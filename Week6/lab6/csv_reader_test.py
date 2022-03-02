# Simulate a sports tournament

import csv
import sys
import random
import math
# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    #open the file
    with open(sys.argv[1]) as csv_file:
        csv_reader = csv.DictReader(csv_file)
        for line in csv_reader:
            line["rating"] = int (line["rating"])
            teams.append(line)
    for i in teams:
        print (i["rating"])
    print (math.log2(2))

if __name__ == "__main__":
    main()