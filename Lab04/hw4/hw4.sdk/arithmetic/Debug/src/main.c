/*
 * main.c
 *
 *  Created on: 2018/8/28
 *      Author: VLSILAB
 */

#include <stdio.h>
#include "xparameters.h"
#include "LAB4_AXI.h"

void arithmetic();
void sorting ();


void arithmetic (){
	signed int A, B;

	u32 op_num;
	int Sum;

	char op;

	while(1) {

		printf("Enter Formula Here: \r\n");
		scanf("%d %c %d", &A, &op, &B);

		switch(op){
					case '+' : op_num = 0;break;
					case '-' : op_num = 1;break;
					case '*' : op_num = 2;break;
					default : printf("Wrong!!");break;
				}
		Sum = ALU(XPAR_LAB4_AXI_0_S00_AXI_BASEADDR, A, B, op_num);

		printf("%d %c %d = %d\n\r",A, op ,B, Sum);

	}
	printf("Program End.\n\r");
    return 0;

}

void sorting (){
	int A, B, C, D, E, F, G, H;
	printf("Enter numbers Here: \r\n");

	scanf("%d %d %d %d %d %d %d %d", &A, &B, &C, &D, &E, &F, &G, &H);
	printf("%d %d %d %d %d %d %d %d\r\n", A, B, C, D, E, F, G, H );
	SORT(XPAR_LAB4_AXI_0_S00_AXI_BASEADDR, &A, &B, &C, &D, &E, &F, &G, &H);
	printf("%d %d %d %d %d %d %d %d\r\n", A, B, C, D, E, F, G, H );

}
int main(){
	while(1){
		int prog_num;

		printf("Program Start.\n\r");
		printf("Which program would you execute \n\r");
		scanf("%d" ,&prog_num );
		switch(prog_num){
			case 1 : arithmetic();break;
			case 2 : sorting();break;
			default: break;
		}
	}
}
