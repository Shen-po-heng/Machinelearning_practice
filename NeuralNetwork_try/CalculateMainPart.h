#include <stdlib.h> 
#include <math.h> 
#include <stdio.h> 

//suppose initial value and Threshold value
#define N 2  //the number of the learning data set
#define IN 3 //the number of the neuron of the input layer
#define HN 3 //the number of the neuron of the hidden layer
#define ON 2 //the number of the neuron of the output layer
#define Z 20 

	double P[IN]; //the input data of one set
	double T[ON]; //the teaching data of one set
	double W_IntoHid[HN][IN]; //the weight value between input layer and Hidden layer
	double W_HidtoOut[ON][HN]; //the weight value between Hidden layer and Output layer
	double In_Hid_Layer[HN]; //the input of Hidden layer
	double In_Out_Layer[ON]; //the input of Output layer
	double Out_Hid_Layer[HN]; //the Output of Hidden layer
	double Out_Out_Layer[ON]; //the Output of Output layer
	double Th_Hid[HN]; //the threshold of Hidden layer
	double Th_Out[ON]; //the threshold of Output layer
	double err_m[N]; //the error of the m times of data	
	double d_err[ON];
	FILE *fp;

/*define a struct to save the training Data*/
	struct {
		double input[IN];
		double teach[ON];
	}Study_Data[N];

//Save the weight value every times
	struct {
		double old_W[HN][IN];
		double old_V[ON][HN];
	}Old_WV[Z];

	//Get training data
	ReadTrainingData(){			//Read TrainingData from TrainingData.txt
			int Data_Set_Number,Input_Number,output_Number;
			int Data_read;

	if((fp=fopen("TrainingData.txt","r"))==NULL){		/*open the TrainingData.txt to read the content*/
		printf("opening file is failed!");
		exit(1);
	}
		// initiate these variable
		Data_Set_Number=0;
		Input_Number=0;
		output_Number=0;
	while(fscanf(fp,"%d",&Data_read)!=EOF){
		if (Input_Number<IN){
			Study_Data[Data_Set_Number].input[Input_Number]=Data_read;
			Input_Number++;
		}
		else{
			Study_Data[Data_Set_Number].teach[output_Number]=Data_read;
			output_Number++;
			if (output_Number==ON){
				Data_Set_Number++;
				Input_Number=0;
				output_Number=0;
			}
		}

	}
	fclose(fp);
	printf("\nThere are [%d] datats that have been loaded successfully!\n",output_Number);

	//show the data which has been loaded
	printf("\nShow the data which has been loaded as follows:\n");
	for(Data_Set_Number=0;Data_Set_Number<N;Data_Set_Number++){
		for(Input_Number=0;Input_Number<IN;Input_Number++){
			printf("\nStudy_Data[%d].input[%d]=%f",Data_Set_Number,Input_Number,Study_Data[Data_Set_Number].input[Input_Number]);
		}
		for(output_Number=0;output_Number<ON;output_Number++){
			printf("\nStudy_Data[%d].teach[%d]=%f",Data_Set_Number,output_Number,Study_Data[Data_Set_Number].teach[output_Number]);
		}
	}
	printf("\n\nPress any key to start calculating...\n\n");
	return 1;
	}




initial(){
	int i;
	int ii;
	int j;
	int jj;
	int k;
	int kk;

	/*the value of Hidden layer and the initial of the threshold*/

	for(i=0;i<HN;i++){
		for(j=0;j<IN;j++){
			W_IntoHid[i][j]=(double)((rand()/32767.0)*2-1);			//intiate the weight between input layer and Hiddenlayer with 0,1,-1 randomly
			printf("W_IntoHid[%d][%d]=%f\n",i,j,W_IntoHid[i][j]);
		}
	}
	for(ii=0;ii<ON;ii++){
		for(jj=0;jj<HN;jj++){
			W_HidtoOut[ii][jj]= (double)((rand()/32767.0)*2-1); //intiate the Weight between Hidden layer and output layer with 0,1,-1 randomly
			printf("W_HidtoOut[%d][%d]=%f\n",ii,jj,W_HidtoOut[ii][jj]);
		}
	}
	for(k=0;k<HN;k++){
		Th_Hid[k] = (double)((rand()/32767.0)*2-1); //intiate the threshold between input layer and Hidden layer between -0.01 ~ 0.01 
		printf("Th_Hid[%d]=%f\n",k,Th_Hid[k]);
	}
	for(kk=0;kk<ON;kk++){
		Th_Out[kk] = (double)((rand()/32767.0)*2-1); //intiate the threshold between Hidden layer and Output layer between -0.01 ~ 0.01 
		printf("Th_Out[%d]=%f\n",kk,Th_Out[kk]);
	}
	return 1;
}//the end of initial()
//input the m times learning data 
input_P(int m){
	int i;
	for(i=0;i<IN;i++){
		P[i]=Study_Data[m].input[i];
		printf("P[%d]=%f\n",i,P[i]);
	}
	//get the m times data
	return 1;
}//the end of input_P


//input the m times teaching data
input_T(int m){
	int k;
	for(k=0;k<ON;k++){
		T[k]=Study_Data[m].teach[k];
	}
return 1;
}//the end of the input_T(m)


//the out put of the Hidden layer
H_I_O(){
	double sigma;
	int i,j;
	for(j=0;j<HN;j++){
		sigma=0;
		for(i=0;i<IN;i++){
			sigma+=W_IntoHid[j][i]*P[i]; //calculate the weighted sum of Hidden layer
		}

	In_Hid_Layer[j]=sigma-Th_Hid[i]; //the the weighted sum of Hidden layer - threshold
	Out_Hid_Layer[j]=1.0/(1.0+exp(- In_Hid_Layer[j])); //calculate the output of the hidden layer with Siglon Function
}
return 1;
}//the end of H_I_O()


//the out put of the output layer
O_I_O(){
	int k;
	int j;
	double sigma;
	for(k=0;k<ON;k++){
		sigma=0.0;
		for(j=0;j<HN;j++){
			sigma+=W_HidtoOut[k][j]*Out_Hid_Layer[j];//calculate the weighted sum of output layer
		}
	In_Out_Layer[k]=sigma-Th_Out[k];
	Out_Out_Layer[k]=1.0/(1.0+exp(-In_Out_Layer[k]));
}
return 1;
}


//calculate the error of output layer
int Err_O_H(int m){
		int k;
		double abs_err[ON];
		double sqr_err=0;
		for (k=0;k<ON;k++){
			abs_err[k]=T[k]-Out_Out_Layer[k];
			sqr_err+=(abs_err[k])*(abs_err[k]);
			d_err[k]=abs_err[k]*Out_Out_Layer[k]*(1.0-Out_Out_Layer[k]);
			err_m[m]=sqr_err/2;
		}
return 1;
}

//calculate the error of Hidden layer
double e_err[HN];
int Err_H_I(){
		int j,k;
		double sigma;
		for(j=0;j<HN;j++){
			sigma=0.0;
			for(k=0;k<ON;k++){
				sigma=d_err[k]*W_HidtoOut[k][j];
			}
		e_err[j]=sigma*Out_Hid_Layer[j]*(1-Out_Hid_Layer[j]);
		}
return 1;
}

//Save the weight Value
saveWV(int m){
	int i;
	int ii;
	int j;
	int jj;
	for(i=0;i<HN;i++){
		for(j=0;j<IN;j++){
			Old_WV[m].old_W[i][j] = W_IntoHid[i][j];
		}
	}
	for(ii=0;ii<ON;ii++){
		for(jj=0;jj<HN;jj++){
			Old_WV[m].old_V[ii][jj] = W_HidtoOut[ii][jj];
		}
	}
	return 1;
}


// improve the weight value between output layer and Hidden Layer
int Delta_O_H(int n,double learningRate_HidtoOut, double alpha ){
	int k,j;
	if(n<1) {
		for (k=0;k<ON;k++){
			for (j=0;j<HN;j++){
				W_HidtoOut[k][j]=W_HidtoOut[k][j]+learningRate_HidtoOut*d_err[k]*Out_Hid_Layer[j];
			}
			Th_Out[k]+=learningRate_HidtoOut*d_err[k];
		}
	}
	else if(n>1) {
		for (k=0;k<ON;k++){
			for (j=0;j<HN;j++){
				W_HidtoOut[k][j]=W_HidtoOut[k][j]+learningRate_HidtoOut*d_err[k]*Out_Hid_Layer[j]+alpha*(W_HidtoOut[k][j]-Old_WV[(n-1)].old_V[k][j]);
			}
		Th_Out[k]+=learningRate_HidtoOut*d_err[k];
		}
	}
return 1;
}

// improve the weight value between input layer and Hidden Layer
Delta_H_I(int n, double learningRate_IntoHid,double alpha){
	int i,j;

	if(n<=1){ /*n<=1*/
		for (j=0;j<HN;j++){
			for (i=0;i<IN;i++){
				W_IntoHid[j][i]=W_IntoHid[j][i]+learningRate_IntoHid*e_err[j]*P[i];
			}
			Th_Hid[j]+=learningRate_IntoHid*e_err[j];
		}
	}
	else if(n>1) {
		for(j=0;j<HN;j++){
			for(i=0;i<IN;i++){
				W_IntoHid[j][i]=W_IntoHid[j][i]+learningRate_IntoHid*e_err[j]*P[i]+alpha*(W_IntoHid[j][i]-Old_WV[(n-1)].old_W[j][i]);
			}
		Th_Hid[j]+=learningRate_IntoHid*e_err[j];
		}
	}
return 1;
}



double Err_Sum(){
	int m;
	double total_err=0;
	for(m=0;m<N;m++){
		total_err+=err_m[m];
	}
return total_err;
}


void savequan(){
	int i,j,k;
	int ii,jj,kk;

	if((fp=fopen("BP_WEIGHT.txt","a"))==NULL) { //save the result at BP_WEIGHT.txt
		printf("Cannot open file strike any key exit!");
		exit(1);
	}

	fprintf(fp,"Save the result of weight as follows:\n");
	for(i=0;i<HN;i++){
		for(j=0;j<IN;j++)
		fprintf(fp,"W_IntoHid[%d][%d]=%f\n",i,j,W_IntoHid[i][j]);
	}

	fprintf(fp,"\n");
	for(ii=0;ii<ON;ii++){
		for(jj=0;jj<HN;jj++)
		fprintf(fp,"W_HidtoOut[%d][%d]=%f\n",ii,jj,W_HidtoOut[ii][jj]);
	}

	fclose(fp);
	printf("\nThe result of 'BP_WEIGHT.txt'has been saved successfully!\nPress any key to continue...");


	if((fp=fopen("BP_Threshold.txt","a"))==NULL){//save the result at BP_Threshold.txt
		printf("Cannot open file strike any key exit!");
		exit(1);
	}

	fprintf(fp,"Save the result of the output layer threshold as follows:\n");
	for(k=0;k<ON;k++)
		fprintf(fp,"Th_Out[%d]=%f\n",k,Th_Out[k]);

	fprintf(fp,"\nSave the result of the Hidden layer threshold as follows:\n");
	for(kk=0;kk<HN;kk++)
		fprintf(fp,"Th_Hid[%d]=%f\n",kk,Th_Hid[kk]);

	fclose(fp);
		printf("\nThe result of BP_Threshold.txt has been saved successfully!\nPress any key to continue...");
}


