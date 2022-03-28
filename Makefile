all:
	g++ -std=c++14 -Wall -Werror -pedantic-errors LinearHashTable.cpp main.cpp -o main

clean:
	rm main
