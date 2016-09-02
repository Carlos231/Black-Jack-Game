CC = g++
exe = blackjack

$(exe): deck.o hand.o player.o game.o dealer.o driver.o
	$(CC) deck.o hand.o player.o game.o dealer.o driver.o -o $(exe)
deck.o: deck.cpp
	$(CC) -c deck.cpp
hand.o: hand.cpp
	$(CC) -c hand.cpp
player.o: player.cpp
	$(CC) -c player.cpp
game.o: game.cpp
	$(CC) -c game.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
dealer.o: dealer.cpp
	$(CC) -c dealer.cpp
clean:
	rm -f a.out $(exe) *.o
