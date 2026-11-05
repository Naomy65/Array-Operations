# Array Operations in C

This assignment demonstrates how to:
1. Create an integer array with a size entered by the user.
2. Insert a value at a user-selected position.
3. Delete the first occurrence of a value.
4. Display the array after each operation.

## Compile on Windows (WinLibs / MinGW GCC)

Open PowerShell or the VS Code terminal in this folder and run:

```powershell
gcc -std=c11 -Wall -Wextra -pedantic main.c -o array.exe
.\array.exe
```

## Compile on Linux / macOS

```bash
gcc -std=c11 -Wall -Wextra -pedantic main.c -o array
./array
```

## Example test

Input:
- Array size: `5`
- Elements: `10 20 30 40 50`
- Value to insert: `25`
- Insertion position: `2`
- Value to delete: `40`

Expected final array:

```text
Final Array: 10 20 25 30 50
```

**Position numbering starts at 0.** The first element is at position 0.
Deletion removes the first matching occurrence of the value.
