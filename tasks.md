# Complete argc/argv Learning Journey - 5 Hour Course

## LEVEL 1: GETTING STARTED (30 minutes)

### Task 1.1: Your First argc/argv Program
**Goal:** Understand what argc and argv are

**Given Code:**
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Number of arguments: %d\n", argc);
    printf("Program name: %s\n", argv[0]);
    
    // TODO: Add one line to print the first argument (if it exists)
    // Hint: Check if argc > 1 first!
    
    return 0;
}
```

**Your Task:** Add code to safely print the first argument.
**Test:** `./program hello`

---

### Task 1.2: Print All Arguments
**Goal:** Loop through all arguments

**Given Code:**
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Program: %s\n", argv[0]);
    
    // TODO: Complete the for loop to print all arguments
    for (int i = 1; i < /* fill this */; i++) {
        printf("Argument %d: /* fill this */\n", i, /* fill this */);
    }
    
    return 0;
}
```

**Your Task:** Complete the for loop.
**Test:** `./program apple banana cherry`

---

### Task 1.3: Argument Counter
**Goal:** Count different types of arguments

**Requirements:** Write a program that counts:
- Total arguments (excluding program name)
- Arguments that start with '-' (flags)
- Arguments that start with '--' (keywords)
- Arguments that are numbers 
- Arguments that are strings

**Test:** `./program -v file.txt 123 -debug 456`
**Expected:** `Total: 5, Flags: 2, Numbers: 2`

---
### Taks 1.4 Argument Parsing
**Goal:** Split arguments into arrays of their types 

**Requirements:** Write a program that splits arguments into arrays:
- Arguments that start with '-' (flags)
- Arguments that start with '--' (keywords)
- Arguments that are numbers 
- Arguments that are strings


---

## LEVEL 2: BASIC VALIDATION (30 minutes)

### Task 2.1: Simple Validation (10 min)
**Goal:** Check argument count

**Given Code:**
```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    // TODO: Check if exactly 2 arguments provided (name + age)
    // If wrong number, print: "Usage: ./program <name> <age>"
    // If correct, print: "Hello [name], you are [age] years old!"
    
    return 0;
}
```

**Test:** `./program John 25` vs `./program John`

---

### Task 2.2: Multiple Valid Counts
**Goal:** Accept different argument counts

**Requirements:** Create a program that:
- With 1 arg: prints "Hello [name]!"  
- With 2 args: prints "Hello [name], you are [age]!"
- With 3 args: prints "Hello [name], you are [age] from [city]!"
- Otherwise: prints usage message

**Test multiple combinations**

---

### Task 2.3: Required vs Optional Arguments
**Goal:** Handle optional arguments

**Requirements:** Create a program that:
- Requires at least 1 argument (operation)
- Operation "--greet" requires 1 more argument (name)
- Operation "--add" requires 2 more arguments (numbers)
- Operation "--list" works with just the operation

**Test:** 
- `./program --greet Alice`
- `./program --add 5 10`
- `./program --list`

---

## LEVEL 3: WORKING WITH NUMBERS

### Task 3.1: Simple Calculator
**Goal:** Convert strings to numbers

**Given Code:**
```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./calc <num1> <operator> <num2>\n");
        return 1;
    }
    
    // TODO: Convert argv[1] and argv[3] to integers
    // TODO: Check argv[2] for operator (+, -, *, /)
    // TODO: Perform calculation and print result
    
    return 0;
}
```

**Test:** `./program 15 + 7`

---

### Task 3.2: Sum All Numbers
**Requirements:** Create a program that:
- Takes any number of numeric arguments
- Calculates their sum
- Handles invalid numbers gracefully (print warning, skip them)

**Test:** `./program 1 2 3 hello 4 5` should sum 1+2+3+4+5=15 and warn about "hello"

---

### Task 3.3: Number Statistics 
**Requirements:** Extend Task 3.2 to also calculate:
- Sum, Average, Minimum, Maximum
- Count of valid numbers

**Test:** `./program 10 5 20 15 2`

---

### Task 3.4: Number Base Converter 
**Goal:** Work with different number representations

**Requirements:** Create a program: `./converter <number> <from_base> <to_base>`
- Support bases 2, 8, 10, 16
- Use `strtol()` for input conversion
- Handle invalid bases and numbers

**Test:** `./converter 255 10 16` should output `FF`

---

## LEVEL 4: STRING PROCESSING

### Task 4.1: String Length Counter 
**Requirements:** Create a program that:
- Takes multiple string arguments  
- Prints each string with its length
- Prints total character count

**Test:** `./program hello world test`

---

### Task 4.2: String Operations 
**Requirements:** Program takes operation + strings:
- `upper`: convert all strings to uppercase
- `lower`: convert all strings to lowercase  
- `reverse`: reverse each string individually
- `concat`: concatenate all strings

**Test:** `./program upper hello world` → `HELLO WORLD`

---

### Task 4.3: Word Search 
**Requirements:** `./search <word> <text1> <text2> ...`
- Search for word in all text arguments
- Print which arguments contain the word
- Case insensitive search

**Test:** `./search cat "I have a cat" "Dogs are nice" "My CAT is black"`

---

## LEVEL 5: FLAGS AND OPTIONS

### Task 5.1: Simple Flags
**Goal:** Parse single-letter flags

**Requirements:** Create a program that recognizes:
- `-v` or `--verbose`: enable verbose output
- `-h` or `--help`: show help message
- Process remaining arguments normally

**Test:** `./program -v file1 file2` and `./program --help`

---

### Task 5.2: Flags with Values 
**Goal:** Handle flags that take parameters

**Requirements:** Support:
- `-n <number>`: set a number value
- `-o <filename>`: set output filename
- `-v`: verbose flag (no value)

**Test:** `./program -n 5 -o output.txt -v input.txt`

---

### Task 5.3: Mixed Arguments Parser
**Requirements:** Create a robust argument parser that handles:
- Flags can appear anywhere: `./program file1 -v file2 -n 10`
- Multiple files and multiple flags
- Unknown flags should show error

**Test various combinations**

---

### Task 5.4: Configuration Override (15 min)
**Goal:** Use flags to override default settings

**Requirements:** Program with defaults:
- Default port: 8080
- Default host: localhost
- Default debug: false

**Flags override:**
- `--port <num>` or `-p <num>`
- `--host <addr>` or `-h <addr>`  
- `--debug` or `-d`

**Print final configuration**

---

## LEVEL 6: FILE OPERATIONS 

### Task 6.1: File Display 
**Requirements:** `./display <file1> <file2> ...`
- Display contents of each file
- Print filename before content
- Handle file opening errors gracefully

---

### Task 6.2: Simple File Statistics
**Requirements:** `./filestat <files...>`
For each file, print:
- Filename
- Size in bytes
- Number of lines
- Number of words

---

### Task 6.3: File Search Tool
**Requirements:** `./filesearch <word> <files...>`
- Search for word in multiple files
- Print: `filename:line_number:matching_line`
- Support case-insensitive search with `-i` flag

---

### Task 6.4: File Operations Tool
**Requirements:** `./fileops <operation> <files...>`
Operations:
- `copy <src> <dst>`: copy file
- `merge <output> <input1> <input2> ...`: merge files
- `split <input> <size>`: split file into chunks

---