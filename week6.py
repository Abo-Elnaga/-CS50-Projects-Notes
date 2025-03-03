# Hello, world program
def hello():
    name = input("What's your name? ")
    print(f"Hello, {name}")

# Mario (Less Comfortable)
def mario_less():
    height = int(input("Height: "))
    for i in range(1, height + 1):
        print(" " * (height - i) + "#" * i)

# Mario (More Comfortable)
def mario_more():
    height = int(input("Height: "))
    for i in range(1, height + 1):
        print(" " * (height - i) + "#" * i + "  " + "#" * i)

# Cash (Less Comfortable)
def cash():
    cents = int(float(input("Change owed: ")) * 100)
    coins = 0
    for coin in [25, 10, 5, 1]:
        coins += cents // coin
        cents %= coin
    print(coins)

# Credit (More Comfortable)
def credit():
    number = input("Number: ")
    sum_even = sum(int(d) for d in number[-2::-2])
    sum_odd = sum(sum(divmod(int(d) * 2, 10)) for d in number[-1::-2])
    if (sum_even + sum_odd) % 10 == 0:
        print("VALID")
    else:
        print("INVALID")

# Readability Test
def readability():
    import re
    text = input("Text: ")
    words = len(text.split())
    sentences = len(re.findall(r'[.!?]', text))
    letters = sum(c.isalpha() for c in text)
    index = round(0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8)
    print(f"Grade {index}" if index >= 1 else "Before Grade 1")

# DNA Analysis
def dna():
    import csv
    import sys
    from collections import Counter

    database_file = input("Database file: ")
    sequence_file = input("DNA sequence file: ")

    with open(database_file) as db:
        reader = csv.DictReader(db)
        str_sequences = reader.fieldnames[1:]
        data = list(reader)
    
    with open(sequence_file) as seq:
        sequence = seq.read()
    
    def max_repeats(seq, subseq):
        i, max_count = 0, 0
        while subseq * (i + 1) in seq:
            i += 1
            max_count = i
        return max_count
    
    person_str_counts = {str_: max_repeats(sequence, str_) for str_ in str_sequences}
    
    for person in data:
        if all(int(person[str_]) == person_str_counts[str_] for str_ in str_sequences):
            print(person['name'])
            return
    print("No match")
