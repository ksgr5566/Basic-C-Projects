//An advanced scientific calculator with a purely text based interface
//Oct-2020

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define DEGREE (M_PI/180.0)
#define RADIAN (1/DEGREE)

void info(){
  printf("About this calculator :");
  printf("\n1)Takes a number first and evaluates the operation with the entered number as input for trig/log/factorial functions.");
  printf("\n2)The Result given continues to become the input for next operation.");
  printf("\n3)Type \"refresh\" to discard previous result and start anew.");
  printf("\n4)Type \"exit\" to exit the calculator.");
  printf("\n5)If the input given is incorrect don't blame the calculator for not working the way it should.");
  printf("\n6)Functions to be typed as they are without mistakes : ");
  printf("\n\n  +   -   *   /   ^   %   !   loge   log10   e^x   sqrt   refresh   exit ");
  printf("\n  sin cos tan sec cot cosec arcsin arccos arctan arcsec arccot arccosec");
  printf("\n  sinh cosh tanh sech coth cosech arcsinh arccosh arctanh arcsech arccoth arccosech");
  printf("\n\n7)Happy Calculating!! :) \n");
}

int factorial(int n){
  int val;
 if (n<0) { printf("Illegal argument\n"); exit(0); }
 if (n==0 || n==1) val = 1;// this is the base case
 else  val = n * factorial(n-1);//this is the recursive step - tail recursion
 return val;
}

int main(void){
  info();
  float num1,num2,result;
  start:{
    printf("Enter number : ");
    scanf("%f",&num1);getchar();
    while(1){
      bool opr_check=false;
      char opr[10];bool trig_check=false;
      printf("Enter Operation : ");
      gets(opr);if(strcmp(opr,"exit")==0)exit(0);
      if(strcmp(opr,"refresh")==0)goto start;
      if(strcmp(opr,"+")==0||strcmp(opr,"-")==0||strcmp(opr,"/")==0||strcmp(opr,"*")==0||strcmp(opr,"^")==0||strcmp(opr,"%")==0){
        printf("Enter number : ");
        scanf("%f",&num2);getchar();opr_check=true;
      }
      if(opr_check==true){
        if(strcmp(opr,"+")==0){result=num1+num2;printf("Result = %f \n",result);}
        if(strcmp(opr,"-")==0){result=num1-num2;printf("Result = %f \n",result);}
        if(strcmp(opr,"/")==0){result=num1/num2;printf("Result = %f \n",result);}
        if(strcmp(opr,"*")==0){result=num1*num2;printf("Result = %f \n",result);}
        if(strcmp(opr,"^")==0){result=pow(num1,num2);printf("Result = %f \n",result);}
        if(strcmp(opr,"%")==0){result=(int)num1%(int)num2;printf("Result = %d \n",(int)result);}
        num1=result;
      }
      int degree_radian;
      if(strcmp(opr,"sin")==0||strcmp(opr,"cos")==0||strcmp(opr,"tan")==0||strcmp(opr,"cosec")==0||strcmp(opr,"sec")==0||strcmp(opr,"cot")==0||strcmp(opr,"arcsin")==0||strcmp(opr,"arccos")==0||strcmp(opr,"arctan")==0||strcmp(opr,"arccosec")==0||strcmp(opr,"arcsec")==0||strcmp(opr,"arccot")==0||strcmp(opr,"sinh")==0||strcmp(opr,"cosh")==0||strcmp(opr,"tanh")==0||strcmp(opr,"cosech")==0||strcmp(opr,"sech")==0||strcmp(opr,"coth")==0||strcmp(opr,"arcsinh")==0||strcmp(opr,"arccosh")==0||strcmp(opr,"arctanh")==0||strcmp(opr,"arccosech")==0||strcmp(opr,"arcsech")==0||strcmp(opr,"arccoth")==0){
        printf("1.Degrees or 2.Radians----Enter 1 or 2 : ");
        scanf("%d",&degree_radian);getchar();trig_check=true;
      }
      float x,y;
      if(degree_radian==1){x=DEGREE;y=RADIAN;}
      if(degree_radian==2){x=1;y=1;}
      if(trig_check==true){
        if(strcmp(opr,"sin")==0){result=sin(num1*x);printf("Result = %f \n",result);}
        if(strcmp(opr,"cos")==0){result=cos(num1*x);printf("Result = %f \n",result);}
        if(strcmp(opr,"tan")==0){result=tan(num1*x);printf("Result = %f \n",result);}
        if(strcmp(opr,"cosec")==0){result=1/sin(num1*x);printf("Result = %f \n",result);}
        if(strcmp(opr,"sec")==0){result=1/cos(num1*x);printf("Result = %f \n",result);}
        if(strcmp(opr,"cot")==0){result=1/tan(num1*x);printf("Result = %f \n",result);}
        if(strcmp(opr,"arcsin")==0){result=asin(num1)*y;printf("Result = %f \n",result);}
        if(strcmp(opr,"arccos")==0){result=acos(num1)*y;printf("Result = %f \n",result);}
        if(strcmp(opr,"arctan")==0){result=atan(num1)*y;printf("Result = %f \n",result);}
        if(strcmp(opr,"arccot")==0){result=atan(1/num1)*y;printf("Result = %f \n",result);}
        if(strcmp(opr,"arccosec")==0){result=asin(1/num1)*y;printf("Result = %f \n",result);}
        if(strcmp(opr,"arcsec")==0){result=acos(1/num1)*y;printf("Result = %f \n",result);}
        if(strcmp(opr,"sinh")==0){result=sinh(num1*x);printf("Result = %f \n",result);}
        if(strcmp(opr,"arcsinh")==0){result=asinh(num1)*y;printf("Result = %f \n",result);}
        if(strcmp(opr,"cosech")==0){result=1/sinh(num1*x);printf("Result = %f \n",result);}
        if(strcmp(opr,"arccosech")==0){result=asinh(1/num1)*y;printf("Result = %f \n",result);}
        if(strcmp(opr,"arcsec")==0){result=acos(1/num1)*y;printf("Result = %f \n",result);}
        if(strcmp(opr,"cosh")==0){result=cosh(num1*x);printf("Result = %f \n",result);}
        if(strcmp(opr,"arccosh")==0){result=acosh(num1)*y;printf("Result = %f \n",result);}
        if(strcmp(opr,"sech")==0){result=1/cosh(num1*x);printf("Result = %f \n",result);}
        if(strcmp(opr,"arcsech")==0){result=acosh(1/num1)*y;printf("Result = %f \n",result);}
        if(strcmp(opr,"tanh")==0){result=tanh(num1*x);printf("Result = %f \n",result);}
        if(strcmp(opr,"arctanh")==0){result=atanh(num1)*y;printf("Result = %f \n",result);}
        if(strcmp(opr,"coth")==0){result=1/tanh(num1*x);printf("Result = %f \n",result);}
        if(strcmp(opr,"arccoth")==0){result=atanh(1/num1)*y;printf("Result = %f \n",result);}
      }
      if(strcmp(opr,"!")==0){result=factorial(num1);printf("Result = %d \n",(int)result);}
      if(strcmp(opr,"loge")==0){result=log(num1);printf("Result = %f \n",result);}
      if(strcmp(opr,"log10")==0){result=log10(num1);printf("Result = %f \n",result);}
      if(strcmp(opr,"e^x")==0){result=exp(num1);printf("Result = %f \n",result);}
      if(strcmp(opr,"sqrt")==0){result=pow(num1,0.5);printf("Result = %f \n",result);}
      if(trig_check==true||strcmp(opr,"!")==0||strcmp(opr,"loge")==0||strcmp(opr,"log10")==0||strcmp(opr,"e^x")==0||strcmp(opr,"sqrt")==0){
        num1=result;
      }
    }
  }


  return 0;
}
