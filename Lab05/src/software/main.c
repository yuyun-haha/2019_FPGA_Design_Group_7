#include "contral.h"
#include <stdio.h>
#include "xil_printf.h"
#include "xil_io.h"
#include "xparameters.h"

int main()
{
	u32 operator;
	int A, B, C, D, a, b, c, d;

	while(1){
		printf("Which operation would you want to execute :");
		printf("\r\n0: add\r\n1: sub\r\n2: mul\r\n3: det\r\n4: trans\r\n");

		scanf("%d", &operator);
		printf("%d\r\n", operator);

		if(operator >= 0 && operator <= 4){
			write_data(0, operator);

			printf("Please enter the first 2x2 matrix :");
			printf("\r\n");
			scanf("%d", &A);
			printf("%d ", A);
			write_data(1, A);

			scanf("%d", &B);
			printf("%d\r\n", B);
			write_data(2, B);

			scanf("%d", &C);
			printf("%d ", C);
			write_data(3, C);

			scanf("%d", &D);
			printf("%d\r\n", D);
			write_data(4, D);

			if(operator == 0 || operator == 1 || operator == 2){
				printf("Please enter the second 2x2 matrix :");
				printf("\r\n");
				scanf("%d", &a);
				printf("%d ", a);
				write_data(5, a);

				scanf("%d", &b);
				printf("%d\r\n", b);
				write_data(6, b);

				scanf("%d", &c);
				printf("%d ", c);
				write_data(7, c);

				scanf("%d", &d);
				printf("%d\r\n", d);
				write_data(8, d);
			}

			Xil_Out32(XPAR_CONTRAL_0_S00_AXI_BASEADDR + 0x00000004, 0x00000003);	//enable matrix processor (let pl_start high)
			if(operator == 0 || operator == 1 || operator == 2 || operator == 4){
				printf("The answer is:\r\n");
				printf("%d ", 		read_data(255));
				printf("%d\r\n", 	read_data(254));
				printf("%d ", 		read_data(253));
				printf("%d\r\n",	read_data(252));
			}
			else if(operator == 3){
				printf("The answer is: %d\r\n", read_data(255));
			}

		}

		else{
			printf("please enter 0 ~ 4  !!! \r\n\r\n");
		}

	}

    return 0;
}