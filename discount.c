#include "discount.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/* PEC3 Activity 1A */
void sortDiscountsShop(tDiscountsShop *discountsShop){
			
	int compare(const void *s1, const void *s2)
    {
		tDiscount *e1 = (tDiscount *)s1;
		tDiscount *e2 = (tDiscount *)s2;
	  
		return e1->dni - e2->dni;
    }
	
	//Sort table
	qsort (discountsShop->discounts, discountsShop->numDiscounts, sizeof(discountsShop->discounts[0]), compare);	
}

/* PEC3 Activity 1B */
void discountChanged(tDiscountsShop *discountsShop,int dni){
	
	unsigned int i;
	unsigned int discounts;
	discounts = 0;

	for(i=0;i<discountsShop->numDiscounts;i++) {
		
		//If the parameter "changed" of the given dni is FALSE
		if (discountsShop->discounts[i].dni == dni && discountsShop->discounts[i].changed == 0){
			discountsShop->discounts[i].changed = TRUE;
			discounts++;
		//If the parameter "changed" of the given dni is TRUE
		} else if (discountsShop->discounts[i].dni == dni && discountsShop->discounts[i].changed == 1){
			printf ("Coupon with DNI %d is already exchanged. \n",discountsShop->discounts[i].dni);
			discounts++;
		}
	}
	
	//The given dni doesn't exist in the table
	if (discounts == 0){
		printf ("The coupon with  DNI %d doesn't exist in the table \n",dni);
	}
	
}

/*Set string to object*/
void getDiscountObject(const char *str, tDiscount *discount) {

	char temp[5];
	sscanf(str, "%d %f %s", &discount->dni,&discount->discount,temp);
	
	if(strcmp(temp, "TRUE")== 0){
		discount->changed = TRUE;
	}else{
		discount->changed = FALSE;
	}
		
}

/*Inicialize table*/
void discountTable_init(tDiscountsShop *discountTable) {
	
	discountTable->numDiscounts=0;

}

void discount_cpy(tDiscount *dst, tDiscount src) {
 
	dst->dni = src.dni;
	dst->discount = src.discount;
	dst->changed = src.changed;
}

void discountTable_add(tDiscountsShop *tabDiscount, tDiscount discount) {
	/* Check if there enough space for the new discount */
	if(tabDiscount->numDiscounts>=MAXDISCOUNTS) {
		printf ("The table of discounts is full \n");
	}else{
		/* Add the new discount to the end of the table */
		discount_cpy(&tabDiscount->discounts[tabDiscount->numDiscounts],discount);
		tabDiscount->numDiscounts++;
	}
	
}

/*Check if the table is correctly sorted*/
int discount_cmp(tDiscountsShop *discountsShop) {
	
	int retVal=0;
	unsigned int i;

	for(i=0;i<discountsShop->numDiscounts-1;i++) {
		if (discountsShop->discounts[i].dni>discountsShop->discounts[i+1].dni && discountsShop->discounts[i].dni<discountsShop->discounts[i+1].dni){
			retVal = -1;
		}
	}
			
	return retVal;
}

