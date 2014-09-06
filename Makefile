CC = gcc
CXXFLAGS = -Wall -std=gnu99
LIBS = -lm

PROJECT = eflt

HEADERS = src/rc.h src/gnuplot_i.h
OBJECTS = src/main.o src/rc.o src/gnuplot_i.o

all: $(PROJECT)

$(PROJECT): $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o $@ $(LIBS)

debug: CXXFLAGS += -g3 -DDEBUG
debug: $(PROJECT)

%.o: %.c $(HEADERS)
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf src/*.o
	rm -rf $(PROJECT)
