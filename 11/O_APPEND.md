This file contains all you need to know about O_APPEND

fcntl(fd, F_SETFL, O_APPEND);

fd: This is the file descriptor on which the fcntl operation is performed. In this case, it's the original file descriptor obtained from opening the file.
F_SETFL: This is a command to fcntl that specifies that we want to set specific file status flags.
O_APPEND: This is one of the file status flags used to modify the behavior of the file descriptor. In this case, O_APPEND is used to set the "append mode" on the file descriptor.


O_APPEND Flag: When you set the O_APPEND flag on a file descriptor using fcntl, it has the following effect:
All write operations performed on the file descriptor (fd) will automatically append the data to the end of the file.
It ensures that multiple processes can safely write to the file simultaneously without overwriting each other's data. This is particularly useful for log files where multiple processes may be writing log entries concurrently.
Appending vs. Non-Appending Mode:
Without O_APPEND: In the default mode, write operations overwrite existing data in the file. Each write starts from the beginning of the file and overwrites any existing content at the current file position.
With O_APPEND: When O_APPEND is set, the write operations always seek to the end of the file before writing new data. This guarantees that data is appended to the end of the file, preserving existing content.
Example Usage:
Suppose you have an existing file with some data, and you open it in append mode using O_APPEND. If you write new data to the file, it will be added to the end of the existing data, without modifying or overwriting the original content.
This behavior is useful for scenarios like appending log entries to a log file, where you want to continuously add new log entries without altering previous entries.


