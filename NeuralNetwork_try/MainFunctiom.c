/* 
Date:2018/3/22
Neural Network implenmatation 
*/ 
#include <stdlib.h> 
#include <math.h> 
#include <stdio.h> 
#include"StartShowANDEndShow.h"
#include "CalculateMainPart.h"
//主程式 

void main(){
    double Pre_error;
    double sum_err;
    double alpha; /*/動量因數，改進型bp演算法使用*/
    double learningRate_HidtoOut; //the learning rate between Hidden layer and Output layer
	double learningRate_IntoHid; /*/隱層至輸入層學習效率*/
	int Learning_number;  //this variable to calculate the number of learning 
	int limit_Number;
		limit_Number=30000;
		learningRate_HidtoOut=0.7;
		learningRate_IntoHid=0.7;
		alpha=0.9;
		Learning_number=0;
		Pre_error=0.0001;

		Start_Show();		//this function is from StartShowANDEndShow.h
		ReadTrainingData();
		initial();
	do{
		int m;
		++Learning_number;
	for(m=0;m<N;m++){
		input_P(m);
		input_T(m);
		H_I_O();
		O_I_O();
		Err_O_H(m);
		Err_H_I();
		saveWV(m); /****************/
		Delta_O_H(2,learningRate_HidtoOut,alpha); /*(m,Learning_number)*/
		Delta_H_I(2,learningRate_IntoHid,alpha); /*(m,Learning_number)*/
	}
		sum_err=Err_Sum();
	printf("sum_err=%f\n",sum_err);
	printf("Pre_error=%f\n\n",Pre_error);

  
   		if(Learning_number>limit_Number){
    		printf("\n*******************************\n");
    		printf("The program is ended by itself because of error!\nThe learning times is surpassed!\n");
    		printf("*****************************\n");
    		break;
   		}
	}while (sum_err>Pre_error);

		printf("\n****************\n");
		printf("\nThe program have studyed for [%d] times!\n",Learning_number);
		printf("\n****************\n");
		savequan();          /*save the results*/
		End_Show();			//this function is from StartShowANDEndShow.h
}
 
