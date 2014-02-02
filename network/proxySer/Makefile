all: proxyServer
proxyServer: proxyServer.c
	gcc -pthread -o proxyServer proxyServer.c csapp.c
run: proxyServer
	./proxyServer 8000
clean:
	rm proxyServer
