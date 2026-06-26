# Get Next Line

A C implementation of the **get_next_line** function from the 42 School curriculum. This project implements a function that reads and returns one line at a time from a file descriptor while efficiently handling memory and preserving the reading position between function calls. The project demonstrates low-level file I/O, dynamic memory management, and the use of static variables in C.

## Features

* 📄 Reads one line at a time from any file descriptor.
* 🔄 Maintains the reading position between successive calls.
* 🧠 Uses static variables to preserve state.
* 📦 Supports different `BUFFER_SIZE` values during compilation.
* 💾 Dynamic memory allocation with proper memory management.
* ⭐ Bonus implementation supports multiple file descriptors simultaneously.

## Project Structure

```
.
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
├── get_next_line_bonus.c
├── get_next_line_utils_bonus.c
└── get_next_line_bonus.h
```

## Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters

* `fd` – The file descriptor to read from.

### Return Value

* Returns the next line from the file, including the newline character (`\n`) when present.
* Returns `NULL` when the end of the file is reached or an error occurs.

## Compilation

Compile the project by specifying a buffer size:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c
```

You can replace `42` with any positive integer to test different buffer sizes.

## Example Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## What I Learned

During this project, I gained practical experience with:

* File descriptors and the `read()` system call
* Static variables
* Dynamic memory allocation
* String manipulation
* Memory leak prevention
* Writing modular and reusable C code

## Technologies

* C
* GCC / Clang
* Makefile
* POSIX File I/O

## Author

**Sona Gevorgyan**

GitHub: https://github.com/SonaGevorgyann
