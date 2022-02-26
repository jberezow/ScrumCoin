outfile = scrumcoin

all: main.cpp
	g++ -o ${outfile} -Iinclude *.cpp

run: all
	./${outfile}

clean: 
	$(RM) ${outfile}
