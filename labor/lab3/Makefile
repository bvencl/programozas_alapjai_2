CXX = g++
CXXFLAGS= -g -Wall

main.exe: main.o rectangle.o circle.o boundingcircle.o
	$(CXX) -o $@ $^

clean:
	del *.o main.exe