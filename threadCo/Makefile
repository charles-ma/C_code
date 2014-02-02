all: diningPhi sleepBarber checkOut matrixMulti
diningPhi: diningPhi.cpp
	g++ -pthread -o diningPhi diningPhi.cpp
sleepBarber:
	g++ -pthread -o sleepBarber sleepBarber.cpp
checkOut:
	g++ -pthread -o checkOut checkOut.cpp
matrixMulti:
	g++ -pthread -o matrixMulti matrixMulti.cpp
run: diningPhi sleepBarber checkOut matrixMulti
	./diningPhi & ./sleepBarber &./checkOut &./matrixMulti
clean:
	rm -i diningPhi sleepBarber checkOut matrixMulti
