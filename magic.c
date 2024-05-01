#include "magic.h"

unsigned int rand = 1681692777;

unsigned int uint_random() {
	unsigned int num = rand;	

	num ^= num << 13;	
	num ^= num << 13;	
	num ^= num << 13;	
	
	rand = num;
	return num;
}
