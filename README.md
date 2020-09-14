# EECS 448 - PROJECT 1
 For this program we built a game of Battleship.
 * Coding implementation was in C++
 * Executive class controls bulk of program operation.
 * Class list:
   * Battleship
   * Board
   * Executive
   * player
 * Board Size: 9x9
   * Columns denoted A-I
   * Rows denoted 1-9
 * Number of ships per player:
   * Chosen by player (options 1-5)
   * Size of ships given by count. 1st ship is 1x1, second ship is 1x2, etc, up to 1x5 ship for a potential 5th ship. 
## Input:
Interaction with program occurs at runtime

## Installing

Clone this repository into a directory
```
~: cd Downloads
~/Downloads: git clone https://github.com/JackNGould/448_battleship.git
```

Compilation needs to be ran on the machine afterwords. Makefile included. Use 'make' and 'make clean' commands

## Run:
executable name: battleship

## Built With
* [GNU Compiler Collection - GCC](https://gcc.gnu.org/) - C++ compiler used. 
* [Valgrind](https://valgrind.org/) - Used for memory leak detection
* [GNU Debugger - gdb](https://www.gnu.org/savannah-checkouts/gnu/gdb/index.html) - For quick debugging done in terminal. 
* [DDD Debugger](https://www.gnu.org/software/ddd/) - For occasional debugging with graphical tool.

## Authors

* **Jack Gould** - *Initial work* - [JackNGould](https://github.com/JackNGould)
* **Grant Henry** - *Initial work* - [GrantHenry](https://github.com/gkhenry142)
* **Thang Minh Le** - *Initial work* - [Thang-sudo](https://github.com/Thang-sudo)
* **Wenxuan Hu** - *Initial work* - [EpicJoe](https://github.com/EpicJoe)
* **Logan Michels** - *Initial work* - [l583m086](https://github.com/l583m086)

## Contributors

* **University of Kansas School of Engineering** 

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Professor David Johnson
