#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // struct that finds directory name and serial #
  struct dirent *pdirname;
  // initialze a character that stores the value of dirname in a pointer
  char *dirname;
  struct stat buf;
  // Parse command line
  // if argc is greater than or equal to 2
  if (argc >= 2)
  {
    dirname = argv[1];
  }
  else
  {
    // assign the value of "." to dirname
    dirname = ".";
  }
  // Open directory
  DIR *dir = opendir(dirname);

  // Repeatly read and print entries
  // if dirname equals NULL, then there is no dir to open
  if (dirname == NULL)
  {
    printf("There is no directory in that path to open\n");
    exit(1);
  }
  else
  {
    // Read the directory entry in opendir to read via dir Struct
    while ((pdirname = readdir(dir)) != NULL)
    {
      // retrieve all file sizes
      stat(pdirname->d_name, &buf);
      // print a list of all directories
      // with their corresponding file sizes to the left of them
      printf("%10ld %s\n", buf.st_size, pdirname->d_name);
    }
  }
  // Close directory
  closedir(dir);

  return 0;
}