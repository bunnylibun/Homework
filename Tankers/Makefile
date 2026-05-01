CC = gcc
CFLAGS = -Wl,--stack,33554432
TARGET = tanker_solve
SRC = main.c lodepng.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)

run: $(TARGET)
	./$(TARGET).exe

clean:
	rm -f $(TARGET).exe