# C Projects

## Table of Contents

- [About](#about)
- [Reversi Game](#reversi)

## About <a name = "about"></a>

From November 10  2020, I have been learning C. This repository consists of all the things I have built. Please feel free to look through and let me know if you want to collaborate.

## Reversi <a name = "reversi"></a>

Reversi is a board game for two players played on an 8x8 board. It is also called Othello in Japan. I have re-created this game using C. See [Reversi(Osero)](./reversi(osero)) folder for the executable and the source code. 

### How to compile .c files

In order to compile .c files on your computer, you need gcc installed. Please go to [this website](https://gcc.gnu.org/install/binaries.html) and install it first, if you haven't already. 

Then, run this command from the same directory that your .c file is in. 
```
gcc -o game game.c
```
#### little explanation
```gcc -o``` section tells the compiler that youa re going to compile a file. next ```game``` you can call it whatever you want, it will be the name of the .exe file. ```game.c``` is the path to the .c file itself. That's it! Now you know how to compile any .c file!

This command compiles .c file and turns it into a binary executable file(.exe). Now all you need to do is to type ```game``` into the console or double click on the game.exe file.
