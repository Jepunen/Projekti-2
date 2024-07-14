## `my-cat.c`

### Overview
`my-cat` is a simple implementation of the Unix `cat` command, which reads one or more files and prints their contents to the standard output.

### Compilation
To compile `my-cat`, use the following command:
```sh
gcc -o my-cat my-cat.c
```

### Usage
```sh
./my-cat file1 [file2 ...]
```
-   If no files are provided, the program exits without doing anything.
-   If one or more files are provided, it prints the contents of each file to the standard output.

### Error Handling
-   If a file cannot be opened, the program prints `my-cat: cannot open file` and exits with status `1`.

### Example
```sh
./my-cat file1.txt file2.txt
```

---

## `my-grep.c`

### Overview
`my-grep` is a simple implementation of the Unix `grep` command, which searches for a specific term in one or more files and prints the matching lines.

### Compilation
To compile `my-grep`, use the following command:
```sh
gcc -o my-grep my-grep.c
```

### Usage
```sh
./my-grep searchterm [file1 ...]
```
-   If no search term is provided, the program prints `my-grep: searchterm [file...]` and exits with status `1`.
-   If no files are provided, it reads from the standard input.
-   If one or more files are provided, it searches for the term in each file and prints the matching lines.

### Error Handling
-   If a file cannot be opened, the program prints `my-grep: cannot open file` and exits with status `1`.

### Example
```sh
./my-grep "hello" file1.txt file2.txt
```

---

## `my-unzip.c`

### Overview
`my-unzip` is a simple implementation of a decompression utility that reads a compressed file and prints the decompressed contents to the standard output.

### Compilation
To compile `my-unzip`, use the following command:
```sh
gcc -o my-unzip my-unzip.c
```

### Usage
```sh
./my-unzip file
```
-   If no file is provided, the program prints `my-unzip: file1 [file2 ...]` and exits with status `1`.
-   It reads the compressed file and prints the decompressed contents to the standard output.

### Error Handling
-   If the file cannot be opened, the program prints an error message and exits with status `1`.

### Example
```sh
./my-unzip compressed_file
```

---

## `my-zip.c`

### Overview
`my-zip` is a simple implementation of a compression utility that reads a file and prints the compressed contents to the standard output.

### Compilation
To compile `my-zip`, use the following command:
```sh
gcc -o my-zip my-zip.c
```

### Usage
```sh
./my-zip file
```
-   If no file is provided, the program prints `my-zip: file1 [file2 ...]` and exits with status `1`.
-   It reads the file and prints the compressed contents to the standard output.

### Error Handling
-   If the file cannot be opened, the program prints an error message and exits with status `1`.

### Example
```sh
./my-zip file_to_compress
```