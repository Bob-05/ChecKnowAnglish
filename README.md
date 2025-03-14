# ChecKnowAnglish
![ChecKnowAnglish](https://github.com/user-attachments/assets/e1f1e9ac-3877-47ff-8a21-f370470cb5c0)

I present to your attention an assistant for memorizing words in English — CheKnowAnglish (although the program can be used not only for memorizing English words, I will tell you about it below).

This program is a console program (for now), but that doesn't make it any less functional. It provides the following features:
1) Writing words,
2) Output a list of words,
3) Knowledge test: translation from English to Russian,
4) Knowledge test: translation from Russian to English,
5) Reset the dictionary to the basic level.

I would like to draw your attention to the fact that in the third and fourth paragraphs, the user can independently set the range of words from the dictionary (Russian-English) that he wants to check. However, if the specified range is incorrect, the program automatically selects the entire list of words, from the first to the last.

The principle of the program:
The program compares two words for similarity, which allows you to use it to learn not only English, but also other languages. The main thing is that the words should be identical in meaning.

All words are stored in a text file "RU_EN.txt ", which should be located in the same folder as the program itself. This means that the list can be edited directly via a file. However, it is important to keep in mind that if the expression consists of several words, then use the characters "_" or "-" (of your choice) instead of a space. This is due to the fact that the program separates words by spaces. If a space is placed incorrectly, it will break the data structure.

For example, take the string:

- Wrong: "because because"
The program will perceive this as two separate words: "because" corresponds to "what", and "because" will remain without a pair.

- Correct: "because"
In this case, the program will correctly match "because" with "because".
