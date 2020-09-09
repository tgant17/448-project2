battleship: main.o executive.o Battleship.o player.o board.o
	g++ -std=c++11 -g -Wall main.o executive.o Battleship.o player.o board.o -o battleship

main.o: main.cpp
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp
	g++ -std=c++11 -g -Wall -c executive.cpp

Battleship.o: Battleship.h Battleship.cpp
	g++ -std=c++11 -g -Wall -c Battleship.cpp

player.o: player.h player.cpp
	g++ -std=c++11 -g -Wall -c player.cpp

board.o: board.h board.cpp
	g++ -std=c++11 -g -Wall -c board.cpp

clean:
	rm *.o battleship
