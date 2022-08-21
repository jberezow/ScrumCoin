outfile = scrumcoin
# TODO: Automatically find project root folder
test_folder = tests
test_exe_folder = tests/test_executables
test_file = test_exec.out

all: main.cpp
	g++ -o ${outfile} -Iinclude *.cpp src/*.cpp

run: all
	./${outfile}

clean: 
	$(RM) ${outfile}

clean-test:
	$(RM) tests/${test_file}

test:
	find tests/*.cpp -maxdepth 1 -exec g++ -o ${test_exe_folder}/${test_file} -Iinclude {} src/*.cpp \; -exec ${test_exe_folder}/${test_file} \;
	@echo All tests passed successfully
