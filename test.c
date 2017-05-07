#include <stdio.h>
#include "test.h"
#include "discount.h"

#define DISCOUNT1 "33333333 10 TRUE"
#define DISCOUNT2 "22222222 20 FALSE"
#define DISCOUNT3 "44444444 10 FALSE"
#define DISCOUNT4 "55555555 5 FALSE"
#define DISCOUNT5 "11111111 10 FALSE"

void testDiscounts(){
	
	unsigned int i;
	int DNI;
	
	tDiscountsShop discountsShop;
	tDiscount discount1, discount2, discount3, discount4, discount5;	
	
	//Inicialize table
	test_initDiscountTable(&discountsShop,DISCOUNT1,DISCOUNT2,DISCOUNT3,DISCOUNT4,DISCOUNT5,&discount1,&discount2,&discount3,&discount4,&discount5);
	
	/* PEC3 Activity 1C1 */
	printf("Test 1c1: Sort table of discounts: \n");	
	sortDiscountsShop(&discountsShop);
	
	//Check if the table is correctly sorted
	if(discount_cmp(&discountsShop)!=0){
		printf("Discounts sorted incorrectly \n");
	} else {
		printf("Discounts sorted \n");
	}
	
	/* PEC3 Activity 1C2 */
	DNI = 22222222;
	printf("Test 1c2: Search if coupon whith DNI %d exist and changed field is FALSE: \n",DNI);	
	
	discountChanged(&discountsShop,DNI);
	
	//Find if the coupon with the given dni has changed the "changed" parameter 
	for(i=0;i<discountsShop.numDiscounts;i++) {
		if (discountsShop.discounts[i].dni==DNI && discountsShop.discounts[i].changed==1){
			printf("Coupon with DNI %d find and changed. \n",DNI);
		}
	}
	
	/* PEC3 Activity 1C3 */
	DNI = 33333333;
	printf("Test 1c3: Search if coupon whith DNI %d exist and changed field is TRUE: \n",DNI);	
	
	discountChanged(&discountsShop,DNI);
	
	/* PEC3 Activity 1C4 */
	DNI = 88888888;
	printf("Test 1c4: Search if coupon with DNI %d doesn't exist: \n",DNI);	
	
	discountChanged(&discountsShop,DNI);
		
}

void test_initDiscountTable(tDiscountsShop *table, char *c1, char *c2, char *c3, char *c4, char *c5, tDiscount *s1, tDiscount *s2, tDiscount *s3, tDiscount *s4, tDiscount *s5) {
	
	/* Create 5 test discounts */
	getDiscountObject(c1, s1);	
	getDiscountObject(c2, s2);	
	getDiscountObject(c3, s3);
	getDiscountObject(c4, s4);
	getDiscountObject(c5, s5);	
	
	/* Add the discounts to the table */
	discountTable_init(table);		
	discountTable_add(table, *s1);
	discountTable_add(table, *s2);
	discountTable_add(table, *s3);
	discountTable_add(table, *s4);
	discountTable_add(table, *s5);
}