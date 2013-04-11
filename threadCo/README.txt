Name: Chao Ma

------------------------------
1. Multiplication of Matrices
------------------------------
I use 3 samples to test the performance. 
    Sample 1 multiplies two matices of size 500(sample500.txt)
    Sample 2 multiplies two matices of size 750(sample750.txt)	
    Sample 3 multiplies two matices of size 1000(sample1000.txt)
Because it may take time to print the final result on the screen, during my experiment, I commented out the code for output. The result is as follows:

matrix size = 500
thread Num    1          2         4          8          16          32          64
time   	      1.381	 0.892	   0.867      0.861	 0.856	     0.863	 0.877
	      
matrix size = 750
thread Num    1          2         4          8          16          32          64
time   	      5.746	 3.186	   2.960      2.920	 2.948	     2.953	 2.932

matrix size = 1000
thread Num    1          2         4          8          16          32          64
time   	      16.989	 9.221	   7.466      7.466	 7.337	     7.559	 7.462

Note: My computer has 4 cores, using linux OS


-----------------------
2. Dining Philosophers
-----------------------
When a philosopher is eating, the console will print "Philosopher i is eating!" (i is the id of the philosopher ranging form 0 to 4)
When a philosopher finishes eating, the console will print "Philosopher i finishes eating!"


-------------------
3. Sleeping Barber
-------------------
You have to pass one parameter to the program which indicates the number of customers
This program hard code 3 positions in the barber shop (1 barber chair and 2 waiting chair)
The console will print sentences like:

"Customer i is getting a hair cut"
"Customer i finishes the hair cut"
"Customer i waits in line"
"Customer i leaves the shop" (means the customer does not get a hair cut)
"Barber is giving a hair cut"




Note: I put some sleep statement in problems 2,3,4 to make it easy to observe.
