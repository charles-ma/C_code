all: client
client: client.c
	gcc -pthread -o client client.c csapp.c
run: client
	./client 127.0.0.1 8000 /index.html
clean:
	rm client
