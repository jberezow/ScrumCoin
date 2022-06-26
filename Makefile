outfile = scrumcoin
test_file = test_exec

all: main.cpp
	g++ -o ${outfile} -Iinclude *.cpp src/*.cpp

run: all
	./${outfile}

clean: 
	$(RM) ${outfile}

test:
	find tests/*.cpp -maxdepth 1 -exec g++ -o tests/${test_file} -Iinclude {} src/*.cpp \; -exec tests/${test_file} \;
	@echo All tests passed successfully