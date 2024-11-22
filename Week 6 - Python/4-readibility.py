import re


def count_letters(text):
    return sum(char.isalpha() for char in text)


def count_words(text):
    return len(re.findall(r"[\w'-]+", text))


def count_sentences(text):
    sentences = re.split(r'(?<!\w\.\w.)(?<![A-Z][a-z]\.)(?<=\.|\?)\s', text)
    sentences = [s.strip() for s in sentences if s.strip()]
    return len(sentences)


def calculate_grade(total_letters, total_words, total_sentences):
    if total_words == 0:
        return None

    L = (total_letters / total_words) * 100
    S = (total_sentences / total_words) * 100

    grade = 0.0588 * L - 0.296 * S - 15.8
    return round(grade)


def determine_grade_range(grade):
    if grade >= 16:
        return "Grade 16+"
    elif grade < 1:
        return "Before Grade 1"
    else:
        return f"Grade {grade}"


text = input("Text: ")

total_letters = count_letters(text)
total_words = count_words(text)
total_sentences = count_sentences(text)

grade = calculate_grade(total_letters, total_words, total_sentences)

if grade is not None:
    print(determine_grade_range(grade))
else:
    print("No text provided.")