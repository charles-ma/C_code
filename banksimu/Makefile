all: parallel synch
parallel: bank-parallel.c
	gcc -pthread -o bank-parallel bank-parallel.c
synch: bank-synch.c
	gcc -pthread -o bank-synch bank-synch.c
run: parallel synch
	./bank-parallel & ./bank-synch
clean:
	rm -i bank-parallel bank-synch
