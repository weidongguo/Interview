#include <iostream>


/* 1st way: 
	 recursion fib(n) = fib(n-1) + fib(n-2) for n >= 2
						 fib(0) = 0
						 fib(1) = 1
	 top down approach
	 exponential time
*/

int fib(int i){
	if(i < 0)
		return -1;	

	if( i == 0 )
		return 0;	
	else if( i == 1)
		return 1;

	return fib(i-1) + fib(i-2);
}

/* 2nd way:
	 bottom up - dynamic programming, store needed info
	 linear time - O(n)	
*/
int fib2(int i ){
	int *f = new int[i+1], answer;

	if( i < 0) return -1; //undefined for negative, safety check
	
	f[0] = 0;
	f[1] = 1;
	for(int j = 2; j <= i; j++){
		f[j]=f[j-1]+f[j-2];	
	}

	answer = f[i];
	delete [] f;

	return answer;

}
/* 3rd way:
	 some matrix multiplication method, O(lg n)

*/

/* 4rd way:
	 solve the recurrent relation and obtain
	 a formula, can accurately approximate 
	 the ith Fibonacci number
	 in constant time O(1) */
	
void test_fib( int (*funct)(int i), int upTo ){
	for(int i = 0 ; i <= upTo; i++){
		std::cout << funct(i) << " " ;
	}
	std::cout << std::endl;
}

int main(){

	test_fib(fib, 10);	
	test_fib(fib2, 10);

	return 0;
}

