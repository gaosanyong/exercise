# Example Makefile
CXX      = g++
CXXFLAGS = -Wall -std=c++17
TARGET   = HelloWorld
SRC      = HelloWorld.cpp

$(TARGET): $(SRC)
  $(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

.PHONY: clean # PHONY target (not FILE target)
clean:
  rm -f $(TARGET)
