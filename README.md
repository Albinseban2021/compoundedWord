# Compounded-Words

## Overview

The Compounded Words Finder is a C++ program that identifies the longest and second-longest compounded words from a list of input words. A compounded word is defined as a word that can be constructed by concatenating shorter words from the same list.

## Execution Steps

To run the program, follow these steps:

1. **Prerequisites**: Ensure you have a C++ compiler (e.g., g++) installed on your system.

2. **Compilation**: Compile the C++ source code using the following command in the terminal:

   ```bash
   g++ -std=c++11 -o compound_word_finder testCreate.cpp
Design Decisions and Approach
Sorting by Length: The program uses a sorted list of words, sorted by their length in ascending order, to optimize the search for compounded words.

Recursive Approach: The program employs a recursive approach in the isCompounded function to determine if a word can be compounded. It checks for matching prefixes and suffixes within the list of words already processed.

Efficiency: This program is designed to efficiently identify the longest and second longest compounded words in a list of words by taking advantage of sorting and recursive search.
