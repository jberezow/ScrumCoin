all: main.cpp
	g++ -Iinclude main.cpp Block.cpp Blockchain.cpp

run: all
	./scrumcoin

clean: 
	$(RM) scrumcoin
