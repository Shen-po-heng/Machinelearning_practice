//Start_Show && End_Show
#include <stdio.h>
#include <stdlib.h> 
void Start_Show()
{
	printf(" ***********************\n");
	printf(" This Program is the Data Structure homework calculating back propagation CNN model *\n");
	printf(" ***********************\n");
	printf("\n\nBefore starting,please read the follows carefully:\n\n");
	printf(" 1.Please ensure the Path of the 'TrainData.txt' is correct!\n");
	printf(" 2.The calculating results will be saved \n");
	printf(" 3.The program will load 10 datas when running from 'TrainData.txt'!\n");
	printf(" 4.The program of CNN model can learm itself for no more than 30000 times.\nAnd surpassing the number,the program will be ended by itself in\npreventing running infinitely because of error!\n");
	printf("\n\n\n");
	printf("Now press any key to start...\\n");
	system("pause");
}

void End_Show()
{
printf("\n\n---------------------------------------------------\n");
printf("The program has reached the end successfully!\n\nPress any key to exit!\n\n");
printf("\n ***********************\n");
printf(" * This is the end of the program which can calculate the CNN model! *\n");
printf(" ***********************\n");
printf(" * Thanks for using! *\n");
printf(" ***********************\n");
exit(0);
}
