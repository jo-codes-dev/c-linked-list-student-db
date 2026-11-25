# Student Record Management System

A menu-driven console application written in C for managing student academic records. Built around a singly linked list, the system demonstrates dynamic memory allocation, modular C programming, in-place list manipulation, searching, sorting, and persistent binary/text file storage via `student.dat`.

## Features

* **Dynamic Record Insertion (`a/A`):** Allocates each new node dynamically using `malloc()` and automatically assigns the smallest unused positive integer as a unique roll number (for example, if roll numbers `1`, `2`, `4`, and `5` are in use, the next record receives `3`).
* **Flexible Record Deletion (`d/D`):** Supports deletion by roll number (`R/r`) or student name (`N/n`). If multiple records share the same name, all matching records and their roll numbers are displayed so you can specify the exact record to unlink and `free()`.
* **Tabular Display (`s/S`):** Displays all records currently in memory in a structured table (`Roll No.`, `Name`, and `Percentage`), or notifies you if the list is empty.
* **Record Modification (`m/M`):** Searches records by roll number (`R/r`), name (`N/n`), or percentage (`P/p`)—resolving duplicate matches by roll number—and updates the student's name and percentage while keeping the original roll number intact.
* **Sorting (`t/T`):** Reorders the linked list alphabetically by student name (`N/n`) or in descending order by percentage (`P/p`, highest first).
* **In-Place List Reversal (`r/R`):** Reverses the singly linked list by rearranging node `next` pointers directly without allocating duplicate nodes.
* **Bulk Memory Cleanup (`l/L`):** Traverses the list node by node, frees all dynamically allocated memory, and resets the `head` pointer to `NULL`. Does not alter `student.dat` unless changes are explicitly saved afterward.
* **File Persistence & Safe Exit (`v/V` & `e/E`):** Automatically loads saved records from `student.dat` at startup (if the file exists), writes records to `student.dat` on demand (`v/V`) or when saving on exit (`S/s`), and ensures all allocated heap memory is freed prior to termination.
* **Input Validation:** Validates that percentages fall within `0.00` to `100.00`, student names are non-empty, roll numbers remain positive and unique, and invalid menu inputs or missing records are handled gracefully.

## Project Structure

| File | Responsibility |
| :--- | :--- |
| `student.h` | Defines `struct student`, shared constants/macros, and function prototypes. |
| `stud_main.c` | Contains `main()`, runs the interactive menu loop, and dispatches user commands. |
| `stud_add.c` | Implements dynamic node creation, smallest-available roll number assignment, and insertion. |
| `stud_del.c` | Implements record lookup by roll number or name, duplicate disambiguation, unlinking, and `free()`. |
| `stud_show.c` | Formats and prints the complete linked list in tabular form. |
| `stud_mod.c` | Searches records by roll number, name, or percentage and updates student details. |
| `stud_save.c` | Handles loading records from `student.dat` at startup and saving records to `student.dat`. |
| `student` | Compiled executable binary generated from the source files. |
| `student.dat` | Persistent data file storing saved student records between sessions. |

## Data Structure

Each student record is represented as a node in a singly linked list defined in `student.h`:

```c
struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
};
```

## Prerequisites

* A C compiler supporting C99 or later (such as `gcc` or `clang`)
* Standard C libraries (`stdio.h`, `stdlib.h`, `string.h`)

## Compilation and Execution

### 1. Compile the Application

From the project root directory, compile all source modules together to produce the `student` executable:

```bash
gcc -Wall -Wextra stud_main.c stud_add.c stud_del.c stud_show.c stud_mod.c stud_save.c -o student
```

### 2. Run the Application

On Linux / macOS:

```bash
./student
```

On Windows (Command Prompt or PowerShell):

```powershell
student.exe
```

If `student.dat` is present in the working directory, the program loads the saved records into the linked list automatically upon launch; otherwise, it starts with an empty list.

## Menu Reference

```text
*** STUDENT RECORD MENU ***
a/A : Add new record
d/D : Delete a record
s/S : Show the list
m/M : Modify a record
v/V : Save records
e/E : Exit
t/T : Sort the list
l/L : Delete all the records
r/R : Reverse the list
Enter your choice:
```

| Option | Action | Sub-Options & Behavior |
| :--- | :--- | :--- |
| `a` / `A` | Add new record | Auto-assigns lowest unused roll number; prompts for name and percentage (`0.00`–`100.00`). |
| `d` / `D` | Delete a record | `R/r`: Delete by roll number \| `N/n`: Delete by name (lists matching roll numbers if duplicates exist). |
| `s` / `S` | Show the list | Displays `Roll No.`, `Name`, and `Percentage` in a formatted table. |
| `m` / `M` | Modify a record | `R/r`: Search by roll number \| `N/n`: Search by name \| `P/p`: Search by percentage. |
| `v` / `V` | Save records | Writes all current linked-list records to `student.dat`. |
| `t` / `T` | Sort the list | `N/n`: Sort alphabetically by name \| `P/p`: Sort descending by percentage. |
| `l` / `L` | Delete all records | Frees all nodes in memory and sets `head = NULL` (`student.dat` remains unchanged). |
| `r` / `R` | Reverse the list | Reverses the linked list in place by updating `next` pointers. |
| `e` / `E` | Exit | `S/s`: Save to `student.dat`, free memory, and exit \| `E/e`: Free memory and exit without saving. |