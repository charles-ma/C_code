all: server
server: server.c
	gcc -pthread -o server server.c csapp.c
run: server
	./server 8000
clean:
	rm server
