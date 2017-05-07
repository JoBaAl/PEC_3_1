#define MAXDISCOUNTS 50

typedef enum {FALSE, TRUE} bool;

typedef struct {

	int dni;
	float discount;
	bool changed;

} tDiscount;

typedef struct {

	tDiscount discounts[MAXDISCOUNTS];
	int numDiscounts;

} tDiscountsShop;

/* PEC3 Activity 1A */
void sortDiscountsShop(tDiscountsShop *discountsShop);

/* PEC3 Activity 1B */
void discountChanged(tDiscountsShop *discountsShop,int dni);

/* Copy the discount data in src to dst*/
void discount_cpy(tDiscount *dst, tDiscount src);

/* Initialize the discount of discounts */
void discountTable_init(tDiscountsShop *discountTable);

/* Compare table of discounts*/
int discount_cmp(tDiscountsShop *discountsShop);

/* Add a new discount to the table of discounts */
void discountTable_add(tDiscountsShop *table, tDiscount discount);

/* Get a discount object from its textual representation */
void getDiscountObject(const char *str, tDiscount *discount);

void test_initDiscountTable(tDiscountsShop *table, char *c1, char *c2, char *c3, char *c4, char *c5, tDiscount *s1, tDiscount *s2, tDiscount *s3, tDiscount *s4, tDiscount *s5);