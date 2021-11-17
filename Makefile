CC = g++
CFLAGS = -W -Wall -std=c++20 -g -O3
LDFLAGS = -LGLEW -lGL -lglut -lGLU -lstdc++
EXEC = nbody

SOURCES := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))

all: $(EXEC) Makefile

$(EXEC): $(OBJECTS)
	$(CC) -o $(EXEC) $^ $(CFLAGS) $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS) $(LDFLAGS)

clean:
	rm *.o
	rm $(EXEC)
