# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = app

# Default target
all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) main.c -o $(TARGET)

check: $(TARGET)
	@echo "Running basic execution test..."
	./$(TARGET)

clean:
	rm -f $(TARGET)