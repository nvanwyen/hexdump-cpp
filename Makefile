all: bin/hexdmp

bin/hexdmp: src/*.hpp src/*.cpp
	@( cd src && g++ -o ../bin/hexdmp main.cpp )
clean:
	@rm -f bin/hexdmp *.o
