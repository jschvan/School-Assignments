CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = ppmApp
SRCS = ppmDriver.c ppmUtil.c
OBJS = $(SRCS:.c=.o)
INPUT = Image1WComments.ppm 
OUTPUT = output2.ppm

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET) $(INPUT) $(OUTPUT)