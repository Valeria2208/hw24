//
//  main.cpp
//  hw24
//
//  Created by Valeria Dudinova on 19.12.2024.
//

#include <iostream>
using namespace std;

const int MAX_WORDS = 1000;
const int MAX_LENGTH = 50;

bool compareWords(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return false;
        }
        ++i;
    }
    return a[i] == '\0' && b[i] == '\0';
}

void copyWord(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
}

void cleanWord(const char* input, char* output) {
    int j = 0;
    for (int i = 0; input[i] != '\0'; ++i) {
        char ch = input[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            if (ch >= 'A' && ch <= 'Z') {
                ch += 'a' - 'A';
            }
            output[j++] = ch;
        }
    }
    output[j] = '\0';
}

int findWordIndex(char words[][MAX_LENGTH], int wordCount, const char* word) {
    for (int i = 0; i < wordCount; ++i) {
        if (compareWords(words[i], word)) {
            return i;
        }
    }
    return -1;
}

int main() {
    char words[MAX_WORDS][MAX_LENGTH] = {0};
    int wordCounts[MAX_WORDS] = {0};
    int wordCount = 0;

    char inputWord[MAX_LENGTH];
    char cleanedWord[MAX_LENGTH];

    cout << "Enter text. Press Ctrl+D (Linux/Mac) or Ctrl+Z (Windows) to finish:\n";

    while (cin >> inputWord) {
        cleanWord(inputWord, cleanedWord);

        if (cleanedWord[0] != '\0') {
            int index = findWordIndex(words, wordCount, cleanedWord);
            if (index == -1) {
                copyWord(words[wordCount], cleanedWord);
                wordCounts[wordCount] = 1;
                ++wordCount;
            } else {
                ++wordCounts[index];
            }
        }
    }

    cout << "\nWord frequency dictionary:\n";
    for (int i = 0; i < wordCount; ++i) {
        cout << words[i] << ": " << wordCounts[i] << endl;
    }

    int maxFrequency = 0;
    int maxIndex = -1;
    for (int i = 0; i < wordCount; ++i) {
        if (wordCounts[i] > maxFrequency) {
            maxFrequency = wordCounts[i];
            maxIndex = i;
        }
    }

    if (maxIndex != -1) {
        cout << "\nMost frequent word: "
             << words[maxIndex] << " (occurs " << maxFrequency << " times)\n";
    } else {
        cout << "\nNo words found.\n";
    }

    return 0;
}




