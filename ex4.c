
#define UNSIGNED_LIMIT 0xffffffff //4294967295
#include <stdio.h>
#include <math.h>
#include "ex4.h"
/******************
* Function Name: CollatzNoPrint
* Input:long int number.
* Output:unsigned long int number.
* Function Operation:The function takes the number and check the number of steps we need to do so
					 the original number will turn into 1. The function use the Collatz theory to do so.
			  		 If the number of steps was lower than the unsigned limit, the function will return the sum.
					 Else, the function will stop the process and return 0.
******************/
unsigned long int CollatzNoPrint(long int n);
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
void Collatz(long int n)
{
	long int sum = 0;
	long int i;
	// Using static variable is needed for sum the total number of steps 
	//from the moment we start running the program.
	static int totalSum = 0;
	for (i=0; n!=1 ; i++)
		//For even numbers:
		if (n % 2 == 0)
		{
			printf("%ld->", n);
			n = n / 2;
			sum = sum + 1;
			totalSum = totalSum +1;		
		}
		// For odd numbers:
		else
		{	
			printf("%ld->", n);
			n = (3*n + 1) ;
			sum = sum + 1;
			totalSum = totalSum + 1;		
		}
			printf("1");
			printf("\nnum of steps: %ld\n", sum);
			printf("total num of steps: %ld\n", totalSum);
}
/******************
* Function Name: CollatzNoPrint
* Input:long int number.
* Output:unsigned long int number.
* Function Operation:The function takes the number and check the number of steps we need to do so
					  the original number will turn into 1. The function use the Collatz theory to do so.
					  If the number of steps was lower than the unsigned limit, the function will return the sum.
					  Else, the function will stop the process and return 0.
******************/
unsigned long int CollatzNoPrint(long int n)
{
	unsigned long int sum = 0;
	// as long as the number is not 1 and the sum is lower than the unsigned limit.
	while (n != 1 && sum <= UNSIGNED_LIMIT)
	{
		//For even numbers:
		if (n % 2 == 0)
		{
			n = n / 2;
			sum = sum + 1;
		}
		// For odd numbers:
		else
		{
			n = (3 * n + 1);
			sum = sum + 1;
		}
	}
	if (sum <= UNSIGNED_LIMIT)
	{
		return sum;
	}
	else
	{
		return 0;
	}
}
/******************
* Function Name:ProofCollatzUntill
* Input:long int number.
* Output:No output.
* Function Operation:The function will use the previous function to check what is the number of the steps.
					 If the number is lower than the unsigned limit the function will print the number 
					 with the number of the steps. Else the function will print "you might wanna check
					 (the number)and win 500$"
******************/
void ProofCollatzUntill( long int n)
{
	int i;
	// For 1, the function will be as number 2:
	if (n == 1)
		n = n + 1;
	for (i = 1; i < n; i++)
	{
		if (i == 1)
			printf("passed: 1 (num of steps: 0)\n");
		else if (CollatzNoPrint(i) == 0)
			printf("you might wanna check %ld and win 500$ :)\n", n);
		else
			printf("passed: %d (num of steps: %lu)\n", i, CollatzNoPrint(i));
	}
}
/******************
* Function Name:Fermat
* Input:2 numbers from type int.
* Output:No output.
* Function Operation:The function get two numbers, one is the exponent number(n) and the second 
					 number is the last number we need to check(starting from number 1).
					 The function check if there is equation that exist: num1^n+num2^n = num3^n.
					 If there is such equation the function print "Eureka!" + the equation.
					 Else, the function will print "meh :(".
******************/
void Fermat(int n, int stop)
{
	int aNum = 1, bNum = 1, cNum = 1;
	int i = 0;
	//using flag to see when we succeeded to enter the finall loop and if
	//the "if" loop was true.
	int flag = 0;
	//for the first num:
	for (aNum = 1; aNum < stop; aNum++)
	{
		//for the second num:
		for (bNum = aNum; bNum < stop; bNum++)
		{
			//for the third num:
			for (cNum = 1; cNum < stop; cNum++)
			{
				if (pow(aNum, n) + pow(bNum, n) == pow(cNum, n))
				{
					printf("Eureka! %d^%d + %d^%d = %d^%d\n", aNum, n, bNum, n, cNum, n);
					flag = 1;
				}
			}
		}
	}
	//If the flag has not change it mean that the function didn't find such equation.
	if (flag == 0)
		printf("meh :(\n");
}

/******************
* Function Name:HelpIsDividedBy3Rec
* Input: 2 numbers, type long int.
* Output: int number (0/1/2)
* Function Operation: The function will get two numbers, "mod"=0
					  and the original number.
					  now the function will check the values of them both.
					  eventually the function return the value of "mod".
					  the function workes only with the digits:1,2,3 as required.
******************/
int HelpIsDividedBy3Rec(long int n, long int mod)
{
	//as long as the number is not 0.
	if (n == 0)
		return mod;
	//if the digit= 3 it does not matter so the number= number/10.
	if (n % 10 == 3)
		return HelpIsDividedBy3Rec(n / 10, mod);
	//When mod keeps the value "0"
	if (mod == 0)
	{
		// will put the digit itself in "mod".
		mod = n % 10;
		return HelpIsDividedBy3Rec(n / 10, mod);
	}	
	//When mod keeps the value "1"
	if (mod == 1)
	{
		if (n % 10 == 2)
		{
			mod = 0;
		}
		else if (n % 10 == 1)
		{
			mod = 2;
		}
		else
			mod = 1;
		return HelpIsDividedBy3Rec(n / 10, mod);
	}
	//When mod keeps the value "2"
	if (mod == 2)
	{
		if (n % 10 == 2)
		{
			mod = 1;
			return HelpIsDividedBy3Rec(n / 10, mod);
		}
		else if (n % 10 == 1)
		{
			mod = 0;
			return HelpIsDividedBy3Rec(n / 10, mod);
		}
		else
			mod = 2;
		return HelpIsDividedBy3Rec(n / 10, mod);
	}	
}
/******************
* Function Name:IsDividedBy3Rec
* Input:long int number.
* Output:int number (1/0)
* Function Operation:The function check recursively if the number is devided by 3.
					 The function will not use any action but num/10, num %10.
					 The function use the privious function who will help her to know 
					 if the number is devided by 3.
******************/
int IsDividedBy3Rec(long int n)
{
	long int mod = 0;
	// Mod will get the value from the previous function. 
	mod = HelpIsDividedBy3Rec(n, mod);
	// If mod == 0 it means that the number id devided by 3.
	if (mod == 0)
		return 1;
	return 0;
}
/******************
* Function Name:IsDividedBy3Iter
* Input: long int number.
* Output: int number (0/1)
* Function Operation: The function will check if the number is devided by 3
					  by sum up the right digit with the number/10.
					  The function do so until the number will be <=10.
					  if the final number is 3,6 or 9, it means that the number is devided by 3.
******************/
int IsDividedBy3Iter(long int n)
{
	//for positive numbers:
	if (n > 0)
	{
		while (n >= 10)
		{
			//The function will check if the number is devided by 3
			//by sum up the right digit with the number / 10.
			n = (n % 10) + (n / 10);
		}
		//if the final number is 3,6 or 9, it means that the number is devided by 3.
		if (n == 3 || n == 6 || n == 9)
			return 1;
		return 0;
	}
	//for negative numbers:
	else
		while (n <= -10)

		{
			n = (n % 10) + (n / 10);
		}
	if (n == -3 || n == -6 || n == -9)
		return 1;
	return 0;
}
/******************
* Function Name:FindCommonDigit
* Input: two long int numbers,
* Output: int number (dig / -1)
* Function Operation: The function check recursively if there is a common digit between the two number.
					  If there is such digit' the function return the most right common digit.
					  Else the function return -1.
******************/
int FindCommonDigit(long int n1, long int n2)
{
	 int dig1 = n1 % 10;
	 int dig2 = n2 % 10;
	//If the one of the numbers = 0.
	if (n1 == 0 || n2 == 0)
		return -1;
	//If the most right digit of them both equal, return that digit.
	if (dig1 == dig2)
		return dig1;
	//if one digit is smaller than the other, return the function with the number of
	//the bigger digit and the number / 10 of the smaller digit.
	if (dig1 < dig2)
		return (FindCommonDigit(n1 , n2/10));
	if (dig1 > dig2)
		return (FindCommonDigit(n1 / 10, n2));
}
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
int CountDigit(long int n, int d)
{
	long int counter = 0;
	// If the number =0:
	if (n == 0)
		return counter;
	//If the n%10 = digit, add the counter 1, and call again the function but now number = number/10.
	if (n % 10 == d)
		counter = (counter +1 + CountDigit(n / 10, d));
	//If the n%10 = digit, dont do anything and call again the function but now number = number/10
	else
		counter = (counter + CountDigit(n / 10, d));
}
/******************
* Function Name:PrintReverse
* Input: long int number.
* Output: no output
* Function Operation:The function gets long int number and print it upside down.
					 The function do so recursively by using variable calld "digit" who will keep the 
					 right digit value, print the digit, and call herself again but now number= number/10,
					 untill the number =0.
******************/
void PrintReverse(long int n)
{
	long int dig;
	if (n != 0)
	{
		dig = n % 10;
		//Printing the digit
		printf("%lu", dig);
		PrintReverse(n / 10);
	}
	else 
		printf("\n");
}
