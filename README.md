# Inverted-Search-Engine
🔎 Inverted Search Engine using Hashing & Linked Lists (C)
📌 Overview

This project implements an Inverted Search Engine in C that indexes words from multiple text files and allows efficient searching across those files.

An inverted index is the core data structure used in search engines. It maps each word to the list of documents in which it appears, along with the frequency of occurrence.

This project was built as part of my Data Structures & Algorithms learning journey at Emertxe.

🚀 Features

📂 Indexes multiple .txt files via command-line arguments

🧠 Uses Hash Table (27 buckets: a–z + special characters)

🔗 Implements Linked Lists for dynamic storage

🔁 Supports incremental database creation

🔍 Efficient word search with file-wise frequency

💾 Save database to backup file

♻️ Restore database from backup file

🔡 Case normalization (converts words to lowercase)

🚫 Prevents duplicate file indexing

📊 Displays structured inverted index

🧱 Data Structures Used

Hash Table (Array of 27 Main Node pointers)

Singly Linked List (File List)

Nested Linked Lists:

Main Node → Word + File count

Sub Node → Filename + Word frequency

🛠 Technical Concepts Applied

Hashing

Linked List Manipulation

Dynamic Memory Allocation (malloc)

File Handling (fopen, fscanf, fprintf)

String Manipulation (strcpy, strcmp, strstr)

Modular Programming (Header file abstraction)

Structured Menu-driven Design

📂 Project Structure
.
├── main.c
├── header.h
├── create_database.c
├── display_database.c
├── search_word.c
├── save_database.c
├── update_database.c
├── validate.c
└── Makefile

⚙️ How It Works
1️⃣ Create Database

Reads all valid .txt files

Extracts words

Hashes based on first character

Builds inverted index using linked lists

2️⃣ Display Database

Shows:

[index]   word     File Count    file1[count] -> file2[count]

3️⃣ Search Word

Finds word in O(1) average hash lookup

Displays files and frequency

4️⃣ Save Database

Stores entire inverted index into a backup file

Allows persistence

5️⃣ Update Database

Restores database from backup file

Avoids rebuilding from scratch

🖥 Compilation & Execution
🔹 Using GCC
gcc *.c -o invert.out
./invert.out file1.txt file2.txt file3.txt

🔹 Using Makefile
make
./invert.out file1.txt file2.txt

📸 Sample Menu
==== Inverted Search Menu ====
1. Create Database
2. Display Database
3. Search Word
4. Save Database
5. Update Database
6. Exit

📚 What I Learned

Real-world application of Hash Tables

Efficient data organization using linked lists

Memory management in C

File parsing and persistence mechanisms

Writing modular and maintainable C programs

Handling edge cases in string processing

🎯 Future Improvements

Remove punctuation using tokenizer

Improve hashing strategy

Add sorting by frequency

Optimize search using better collision handling

Add memory cleanup function

👨‍💻 Author

Binil George



