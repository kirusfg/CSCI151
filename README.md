# NU SST CSCI 151 Exercises ![Solving](https://img.shields.io/badge/solving-done-green)
This repository stores solutions to most of the CSCI 151 course exercises.

## Downloading this repository
This can be done in several ways:
- Download a zip archive containing all these solutions via the green **Clone or download** button
- Clone this repository using git:
  1. Change the current working directory to the location where you want the cloned directory to be made
  2. Clone this repository to your working directory:
  ```
  git clone https://github.com/kirusfg/csci151.git
  ```
## Compiling and running the programs
### Linux
To build and test the solutions in Linux, you have to compile them using a **gcc** compiler:
```
gcc lessonX.Y.c -o programName.out -lm
```
To run the program after compiling it, simply use:
```
./programName.out
```
### Windows

#### Eclipse IDE
If you are using Eclipse IDE, please add the following line to your code:
```
setvbuf(stdout, NULL, _IONBF, 0);
```
