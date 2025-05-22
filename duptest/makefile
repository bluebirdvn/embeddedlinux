CXX=g++
CXXFLAGS=-Wall -Werror -std=c++17

TARGET=duptest duptest1
SRC=duptest.cpp
SRC1=duptest1.cpp
all: $(TARGET)

duptest: $(SRC)
	$(CXX) $(CXXFLAGS) -o duptest $(SRC)


duptest1: $(SRC1)
	$(CXX) $(CXXFLAGS) -o duptest1 $(SRC1)
clean:
	rm -f $(TARGET)
