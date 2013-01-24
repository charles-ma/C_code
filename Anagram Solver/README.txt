Name : Chao Ma

I implement this program using array as the hashtable, and each array element
 stands for a hash bucket with the head of the linked list put into it. So I
 can use array index as the hash code for every string. I don't have to sort
 the array because the index is automatically sorted but this approach do 
take up some extra space because I have to build up an array of size 300 or
 so to keep track of all the possible hash code. 	  

The program anagramSolver can find all the anagrams for a given string. e.g 
for input Mary, the output is army Myra
for input this, the output is shit hits

The program cross-word can find some anagrams with a certain character in a 
certain position
for input this 1 i, the output is hits
for input this 0 s, the output is shit
