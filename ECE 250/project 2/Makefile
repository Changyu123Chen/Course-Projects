all: openhttest orderedhttest

openhttest: openhttest.cpp double_hash.cpp
	g++ openhttest.cpp double_hash.cpp -o openhttest

orderedhttest: orderedhttest.cpp chaining.cpp
	g++ orderedhttest.cpp chaining.cpp -o orderedhttest