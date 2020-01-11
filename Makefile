.PHONY: test

test:
	g++ -std=c++11 -Wall -O3 test/test.cc -o test/tsc-test
	test/tsc-test
