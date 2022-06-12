outfile = scrumcoin
test_file = test_exec

all: main.cpp
	g++ -o ${outfile} -Iinclude *.cpp src/*.cpp

run: all
	./${outfile}

clean: 
	$(RM) ${outfile}

test_wallet:
	g++ -o tests/${test_file} -Iinclude tests/wallet_tests.cpp src/*.cpp
	tests/${test_file}

test_blockchain:
	g++ -g -o tests/${test_file} -Iinclude tests/blockchain_tests.cpp src/*.cpp
	tests/${test_file}
