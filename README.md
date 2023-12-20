# get_next_line Function

The `get_next_line` function is a utility function designed to read a line from a file descriptor, especially useful when dealing with system calls in a C program. This function is capable of handling various file descriptors, including stdin, stdout, and stderr.

## Table of Contents

- [Overview](#overview)
- [Usage](#usage)
- [Function Signature](#function-signature)
- [Return Value](#return-value)
- [Example](#example)
- [Contributing](#contributing)
- [License](#license)

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

    while (get_next_line(fd, &line) > 0) {
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
int get_next_line(int fd, char **line);
```

- `fd`: The file descriptor from which to read the line.
- `line`: A pointer to a character pointer that will store the line read.

## Return Value

The function returns:

- `1` if a line has been read successfully.
- `0` if the end of the file has been reached.
- `-1` in case of an error.

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

