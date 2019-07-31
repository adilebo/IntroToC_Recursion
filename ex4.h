/******************
* Function Name: Collatz
* Input: long int num(1<num)
* Output:no output.
* Function Operation: The function takes the number and check the number of steps we need to do so
					  the original number will turn into 1. The function use the Collatz theory to do so.
					  Also, the function will sum the total number of steps since we started to run the program.
					  The function will print the progress, the sum of the steps for the number,
					  and the total sum of the steps for all the
					  numbers who was input from the moment the progrem started to run.
******************/
void Collatz(long int n);
/******************
* Function Name:ProofCollatzUntill
* Input:long int number.
* Output:No output.
* Function Operation:The function will use the previous function to check what is the number of the steps
					 If the number is lower than the unsigned limit the function will print the number
					 with the number of the steps. Else the function will print ""you might wanna check
					 (the number)and win 500$"
******************/

void ProofCollatzUntill(long int n);
/******************
* Function Name:Fermat
* Input:2 numbers from type int.
* Output:No output.
* Function Operation:The function get two numbers, one is the exponent number and the second
				 	 number is the last number we need to check(starting from number 1).
				  	 The function check if there is equation that exist: num1^n+num2^n = num3^n.
					 If there is such equation the function print "Eureka!" + the equation.
					 Else, the function will print "meh :(".
******************/
void Fermat(int n, int stop);
/******************
* Function Name:IsDividedBy3Rec
* Input:long int number.
* Output:int number (1/0)
* Function Operation:The function check recursively if the number is devided by 3.
				   	 The function will not use any action but num/10, num %10.
					 The function use the privious function who will help her to know
					 if the number is devided by 3.
******************/
int IsDividedBy3Rec( long int n);
/******************
* Function Name:IsDividedBy3Iter
* Input: long int number.
* Output: int number (0/1)
* Function Operation: The function will check if the number is devided by 3
				      by sum up the right digit with the number/10.
					  The function do so until the number will be <=10.
					  if the final number is 3,6 or 9, it means that the number is devided by 3.
******************/
int IsDividedBy3Iter(long int n);
/******************
* Function Name:FindCommonDigit
* Input: two long int numbers,
* Output: int number (dig / -1)
* Function Operation: The function check recursively if there is a common digit between the two number.
					  If there is such digit' the function return the most right common digit.
					  Else the function return -1.
******************/
int FindCommonDigit(long int n1, long int n2);
/******************
* Function Name:CountDigit
* Input: one long int number, one int number.
* Output: int number.
* Function Operation:The function get long int number and int number.
					 The function check recursively how many times the digit(int number)
					 appear in the long int number.
					 The function do so with variable who calls "counter", that sums up the number of
					 times the digit appear in the long int number.
******************/
int CountDigit(long int n, int d);
/******************
* Function Name:PrintReverse
* Input: long int number.
* Output: no output
* Function Operation:The function gets long int number and print it upside down.
					 The function do so recursively by using variable calld "digit" who will keep the
					 right digit value, print the digit, and call herself again but now number= number/10,
					 untill the number =0.
******************/
void PrintReverse(long int n);