# get_next_line Function

The `get_next_line` function is a utility function designed to read a line from a file descriptor, especially useful when dealing with system calls in a C program. This function is capable of handling various file descriptors, including stdin, stdout, and stderr.

## Overview

The `get_next_line` function is commonly used in scenarios where reading input from a file descriptor, such as a system call, is required. It reads a line from the specified file descriptor and returns it as a dynamically allocated string. The function manages the memory allocation and resizing to accommodate lines of varying lengths.

## Usage

To use the `get_next_line` function in your C program, follow these steps:

1. Include the `get_next_line.h` header file.
2. Call the function with the desired file descriptor.

```c
#include "get_next_line.h"

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        // Process the line as needed
        printf("Line: %s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

## Function Signature

```c
char *get_next_line(int fd);
```

- `fd`: The file descriptor from which to read the line.

## Return Value

The function returns a dynamically allocated string containing the line read from the file descriptor. It returns `NULL` when the end of the file is reached or an error occurs.

## Example

Suppose you have a file named `example.txt` with the following content:

```
Hello, World!
This is a sample file.
```

The example usage in the "Usage" section would output:

```
Line: Hello, World!
Line: This is a sample file.
```
