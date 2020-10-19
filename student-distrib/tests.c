#include "tests.h"
#include "x86_desc.h"
#include "lib.h"

#include "linkage.h" //REMOVE LATER

#define PASS 1
#define FAIL 0

/* format these macros as you see fit */
#define TEST_HEADER 	\
	printf("[TEST %s] Running %s at %s:%d\n", __FUNCTION__, __FUNCTION__, __FILE__, __LINE__)
#define TEST_OUTPUT(name, result)	\
	printf("[TEST %s] Result = %s\n", name, (result) ? "PASS" : "FAIL");

static inline void assertion_failure(){
	/* Use exception #15 for assertions, otherwise
	   reserved by Intel */
	asm volatile("int $15");
}


/* Checkpoint 1 tests */

/* IDT Test - Example
 * 
 * Asserts that first 10 IDT entries are not NULL
 * Inputs: None
 * Outputs: PASS/FAIL
 * Side Effects: None
 * Coverage: Load IDT, IDT definition
 * Files: x86_desc.h/S
 */

// int idt_test(){
// 	TEST_HEADER;

// 	int i;
// 	int result = PASS;
// 	for (i = 0; i < 9; ++i){
// 		if ((idt[i].offset_15_00 == NULL) && 
// 			(idt[i].offset_31_16 == NULL)){
// 			assertion_failure();
// 			result = FAIL;
// 		}
// 	}

// 	return result;
// }

// int exception_test(){
// 	TEST_HEADER;
// 	int *res;
// 	int a = 1;
// 	res = &a;
// 	res = NULL;
// 	int exception = *res;
// 	return exception;
// }
// int divide_test(){
// 	TEST_HEADER;
// 	//return 1 / 0;
// 	return 0;
// }
int system_call_2(){
	asm volatile( 
          "movl $10, %eax;"
		  "int $0x80"
    );
	return 0;
}

// add more tests here

/* Checkpoint 2 tests */
/* Checkpoint 3 tests */
/* Checkpoint 4 tests */
/* Checkpoint 5 tests */


/* Test suite entry point */
void launch_tests(){
	//TEST_OUTPUT("idt_test", idt_test());
	//TEST_OUTPUT("Dereference NULL test", exception_test());
	//TEST_OUTPUT("divide-by-zero test", divide_test());
	TEST_OUTPUT("system call test 2", system_call_2());
	// launch your tests here
}


