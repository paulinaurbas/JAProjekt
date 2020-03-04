# JAProjekt
University project from Assember Language
## Topis
The topic of the project was to write a program that creates the negative of the bitmap user specified.
## Assumptions of project 
### Assumptions of the library function
The project assumptions were as follows:
- The main part of the application written in C ++
- Two DLLs, one written in C and the other in assembler.
- The user can choose which library will process the image
- The user has the option of choosing the number of processing threads
- The program is enabled from the console using switches
- After the program finishes, the user receives a processed bitmap, saved in a file whose name is given after the -o switch. 
In addition, the processing time for the given algorithm on a given number of threads appears on the console
### Assumptions of the library function
In both DLL libraries, one written in assembler, the other written in C, there is a function that performs bitmap to negative conversion on the selected fragment.
## Running program
a. Without providing the number of threads:
```bash
-i Charles.bmp -o Output.bmp -2
```
b. Specifying the number of threads:
```bash
-i Charles.bmp -o Output.bmp -2 -t 64
```

