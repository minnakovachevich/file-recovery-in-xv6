# file-recovery-in-xv6
<p align="justify">
The purpose of this project was to edit the xv6 system so it could support the “best effort” recovery of deleted files. The recovery system will only work in the case of deleted files, but not for deleted directories. “Best effort” file recovery implies that the deletion and creation of files should run as usual. Special attention was paid in order to ensure that the current system work and functionality was not interfered with, resulting in crashing down. 

In order to enable the recovery of files, information about the occupied blocks needed to be saved in the **inode structure**, and **a flag for the deleted file** from the directory was added. Since by the default xv6 deletion procedure, the entire file content information is deleted from the inode structure of the deleted file, this needed to be edited so that the inode structure stayed intact, and the only thing that changed was the file type to a 0. This indicates that inode can be used for describing another file in the future. The **dirent structure** needed also to be amended, as by the default procedure the entire dirent item of a file is filled with 0 bytes in order to mark a file as deleted. To enable file recovery, dirent structure needs to be saved. That’s why a char del attribute was added, after the inode number and before the file name. If this item is set to 0, the file is present in the system; if it’s 1, the file is deleted. The file name size has been shortened to 13, instead of the original 14. This change needed to be consistent within the xv6 system, so all items in the directories are now created with the char del set to 0. When using the ls command deleted files are ignored.

Two new system calls were implemented: 
- **int lsdel(char \*path, char \*result);**
- **int rec(char \*path);**

**lsdel system call** is used to return a list of all the deleted files in a directory.
**path** parameter represents the directory chosen to display its deleted files.
**result** parameter represents a user buffer allocated in the form of a matrix with 64 rows, and each row contains a DIRSIZ+1 character. This limits the number of files within a directory to 64. The return value is a number of found results, or -1 if the user input a nonexistent directory name. This function forwards a matrix filled with the deleted file names. If the directory contained more than 64 files prior to deletion, all files after the 64th are to be ignored.

**rec system call** is used for “best effort” file recovery. We could run into two issues when recovering a file: inode used to describe a file could be used for something else, or a file block could be used for something else. In both cases, we won’t recover the file, we will only signify a fault. 
**path** parameter is the name of the file we are trying to recover.
The return value can be one of the following:
-  (0) – successful file recovery
- (-1) – invalid directory path
- (-2) – file not found in the chosen directory
- (-3) – inode of the file is being used for something else
- (-4) – any of the file blocks are being used for something else

Three user programs needed to be implemented: **lsdel**, **rec** and **writer**.

**lsdel [path]** lists all the deleted files on a given path. Path is optional; if not given, the current directory (.) is implied. Possible issues when running this program are that the invalid path is given or that there are no deleted files in the given directory.

**rec path** tries to execute the recovery of the chosen file, and signifies a fault if it fails to do so. The given path is the name of the file that needs to be recovered. Possible issues when running this program are that the parameter is not given in the command line, invalid parent directory for the given file, nonexistent deleted file with the same name, inode of the file is used for something else or the file blocks are used for something else.

**writer** program takes the name of the file that needs to be created as an argument, and fills it with a fixed text of a given size. First block of the file are letters ‘a’, second block are the letters ‘b’, and so forth, so we can know where we are inside a file when we are writing it.
</p>
