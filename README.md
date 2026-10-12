*This project has been created as part of the 42 curriculum by vpoka.*

# Get Next Line

A small C function that reads from a file descriptor and returns one line at a time.

## Description

`get_next_line` returns the next line read from a file descriptor, whatever the buffer size or how the data arrives. It is a 42 school project whose goals are to make reading from file descriptors convenient and to teach a core C concept: static variables that keep state from one function call to the next.

Called repeatedly in a loop, `get_next_line()` reads a whole file line by line. Each returned line keeps its terminating `\n`, except the last line when the file does not end with a newline. When there is nothing left to read, or an error occurred, it returns `NULL`.

Features:

- Works with any file descriptor: regular files, standard input, pipes, and more.
- Reads as little as possible per call and stops at the first newline found, instead of loading the whole file.
- `BUFFER_SIZE` is configurable at compile time.
- Bonus: a single static variable tracks multiple file descriptors at once, so reads can be interleaved between, say, fd 3, 4 and 5 without losing the thread of any of them.
- No `libft`, no `lseek()`, no global variables — only `read`, `malloc` and `free`.

## Instructions

### Prerequisites

- A C compiler (`cc`, as used at 42; `gcc` or `clang` work too).
- No external libraries or dependencies.

There is no Makefile in this project: `get_next_line` is a set of `.c`/`.h` files to compile into your own program, as shown below.

### Compilation

Mandatory part:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c <your_files>.c
```

Bonus part:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c <your_files>.c
```

A buffer size of 42 is used as an example. The project compiles both with and without the `-D BUFFER_SIZE` flag.

### Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

Prototype: `char *get_next_line(int fd);`

- `fd`: the file descriptor to read from.
- Return value: the line that was read, or `NULL` if there is nothing else to read or an error occurred.
- Remember to `free()` each returned line.

### Configuration

| Macro | Default | Purpose |
| --- | --- | --- |
| `BUFFER_SIZE` | `5` | Size of the buffer passed to `read()`; define it with `-D BUFFER_SIZE=n` |
| `MAX_FD` | `1024` | Bonus only: number of file descriptors tracked at once; define it with `-D MAX_FD=n` |

Both values can also be changed directly in the headers (`get_next_line.h`, `get_next_line_bonus.h`).

## Resources

- [42 Get Next Line subject](42_subject_gnl.pdf) (version 12) — official requirements and evaluation rules.
- Manual pages: `read(2)`, `malloc(3)`, `free(3)`, `open(2)`.
- [C storage duration — static variables](https://en.cppreference.com/w/c/language/storage_duration) — the concept at the heart of this project.

### AI usage

AI was used for documentation, commit messages and this README.

## Project structure

| File | Role |
| --- | --- |
| `get_next_line.c` | Mandatory implementation |
| `get_next_line.h` | Mandatory header (`BUFFER_SIZE` default) |
| `get_next_line_utils.c` | Helpers: `ft_strlen`, `ft_strdup`, `ft_strjoin`, `ft_strchr`, `ft_substr` |
| `get_next_line_bonus.c` | Bonus implementation, one static array for multiple fds |
| `get_next_line_bonus.h` | Bonus header (`MAX_FD` default) |
| `get_next_line_utils_bonus.c` | Bonus helpers |
| `42_subject_gnl.pdf` | Official 42 subject |

## Troubleshooting

- **Memory leaks**: every line returned by `get_next_line()` is heap-allocated. `free()` it before the next call and when you are done with it.
- **`get_next_line()` returns `NULL` right away**: make sure `fd` is open and valid; in the bonus version it must also be lower than `MAX_FD`, and `BUFFER_SIZE` must be greater than 0.
- **The last line has no `\n`**: this is expected — the newline is only included when the file actually contains one.
- **Strange behavior after modifying the file between calls, or when reading a binary file**: the subject leaves both cases undefined.

## Status

Finished. Scored 112/100.

