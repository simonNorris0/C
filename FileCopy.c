// FileCopy.c written for programming problem 2.24 from Operating System
// Concepts by Silberschatz et al. 
// Simon Norris 2024

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
// for memset()
#include <string.h>

// ** open() is used for both accessing files and creating them **
// https://pubs.opengroup.org/onlinepubs/9799919799/functions/open.html
int open(const char *path, int oflag, ...);
// https://pubs.opengroup.org/onlinepubs/9799919799/functions/read.html
ssize_t read(int fildes, void *buf, size_t nbyte);
// https://pubs.opengroup.org/onlinepubs/9799919799/functions/write.html
ssize_t write(int fildes, const void *buf, size_t nbyte);

int main()
{
    int fdin, fdout;  // integers for file descriptors returned by open() calls
    char pathname[40];// char array for pathname of input and output files
    char buf[20];     // character buffer to read data into and write data from
    size_t nbytes;    // number of bytes to read/write into buffer at a time
    //ssize_t bytes_read;    // number of bytes read by read()
    //ssize_t bytes_written; // number of bytes written by write()

    // Prompts user for input file
    printf("Enter the pathname of the file to copy from: ");
    scanf("%s", pathname);

    // Opens the file at the pathname stored in pathname[] for reading only. 
    // The integer (file descriptor) returned and stored in fdin is used to 
    // access the input file.
    fdin = open(pathname, O_RDONLY);
    if (fdin == -1) { // input file does not exist
        printf("ERR: Input file could not be found..");
        return -1;  // Terminate abnormally
    }

    // Prompts user for output file
    printf("Enter the pathname of the file to copy to: ");
    scanf("%s", pathname);
    
    // Creates the file at the pathname stored in pathname[] for writing only. 
    // If pathname names a symbolic link (if the file exists) open() shall 
    // fail and return -1.
    // The final argument is the mode_t mode to set user permissions.
    // owner = r, w, x  7 (r = 4, w = 2, x = 1)
    // group = r, x     5
    // other = r        4
    // The integer (file descriptor) returned and stored in fdout is used to 
    // access the output file.
    fdout = open(pathname, O_WRONLY | O_CREAT | O_EXCL, 0754);      
    if (fdout == -1) { // output file already exists
        printf("ERR: Output file already exists..");
        return -1;  // Terminate abnormally
    }

    // Loop
    //   read
    //   write
    // until no more data in input file
    nbytes = sizeof(buf); 
    while (read(fdin, buf, nbytes) > 0) { // 0 indicates EOF
        write(fdout, buf, nbytes);
        // https://man7.org/linux/man-pages/man3/memset.3.html
        memset(buf, 0, sizeof(buf)); // reset the buffer to prevent 
                                     // old input being written out again
                                     // when the program reaches EOF and
                                     // the buffer is not filled with 
                                     // the final call to read.
    }

    // Close input and output files
    close(fdin);
    close(fdout);
    // Print completion message
    printf("Finished copying succesfuly.\n");
    // Terminate succesfully 
    return 0;
}
