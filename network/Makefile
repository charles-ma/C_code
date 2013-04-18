all: client
client: client.c
	gcc -pthread -o client client.c csapp.c
run: client
	./client www.seas.upenn.edu 80 /~machao/index.html
clean:
	rm client
