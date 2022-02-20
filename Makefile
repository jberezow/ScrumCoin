all: main.cpp
	g++ -o scrumcoin main.cpp

run: all
	./scrumcoin

clean: 
	$(RM) scrumcoin
