CXX = g++

all: main

main: main.o algo.o 
	 $(CXX) main.o algo.o -o main

main.o: main.cpp
	$(CXX) -c main.cpp
     
algo.o: algo.cpp
	 $(CXX) -c algo.cpp

clean:
	rm -rf *.o rm main

