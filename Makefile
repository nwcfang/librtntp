CC=gcc
CFLAGS=-Wall -ggdb -O0
LDFLAGS=

TARGET=test-tsGetTime 
OBJECTS=test-tsGetTime.o 

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)

test-client: test-client.o
	$(CC) $(LDFLAGS) -o $@ test-client.o
test-server: test-server.o
	$(CC) $(LDFLAGS) -o $@ test-server.o
.PHONY: clean 
clean:
	rm -rf $(OBJECTS) $(TARGET)
