#include<stdio.h>
#include<stdlib.h>
double fabs(double);
double power(double , double);
double factorial(int);
double sine(double);
double cos(double);
double tan(double);
double sineinverse(float);
double cosinverse(float);
double sinh(double);
double cosh(double);
double tanh(double);
double gcd(double , double);
double lcm(double , double);
double log(double);
double logbase10(double);
double exponential(double);
double myfloor(double x);
double myceil(double x);
int myround(double);
double sqrt(double);

void main(){
	int i;
	double y,l,x;
	printf("Please read the README file before for proper functioning\n");
	printf("Enter the value of x\n");
	scanf("%lf",&x);
	printf("1.Absolute Value\n2.Power\n3.Factorial\n4.Sine\n5.Cos\n6.Tan\n7.Sineinverse\n8.Cosinverse\n9.Sinh\n10.Cosh\n11.Tanh\n12.Gcd\n13.Lcm\n14.Log\n15.Logbase10\n16.Exponential\n17.Myfloor\n18.Myceil\n19.Myround\n20.Squareroot\n");
	scanf("%d",&i);
	switch(i){
		case 1:
			printf("%lf",fabs(x));
			break;
		case 2:
			printf("Enter the power\n");
			scanf("%lf",&y);
			if((y>-1)&&(y<1)){
				printf("Invalid input");
				return;
			}
			printf("%lf",power(x,y));
			break;
		case 3:
			printf("%lf",factorial(x));
			break;
		case 4:
			printf("%lf",sine(x));
			break;
		case 5:
			printf("%lf",cos(x));
			break;
		case 6:
			printf("%lf",tan(x));
			break;
		case 7:
			if((x<-1)||(x>1)){
				printf("Invalid input");
				return;
			}
			printf("%lf",sineinverse(x));
			break;
		case 8:
			if((x<-1)||(x>1)){
				printf("Invalid input");
				return;
			}
			printf("%lf",cosinverse(x));
			break;
		case 9:
			printf("%lf",sinh(x));
			break;
		case 10:
			printf("%lf",cosh(x));
			break;
		case 11:
			printf("%lf",tanh(x));
			break;
		case 12:
			printf("Enter the second number\n");
			scanf("%lf",&y);
			printf("%lf",gcd(x,y));
			break;
		case 13:
			printf("Enter the seconde number\n");
			scanf("%lf",&y);
			printf("%lf",lcm(x,y));
			break;
		case 14:
			if(x<1){
				printf("Invalid input");
				return;
			}
			printf("%lf",log(x));
			break;
		case 15:
			if(x<1){
				printf("Invalid input");
				return;
			}
			printf("%lf",logbase10(x));
			break;
		case 16:
			printf("%lf",exponential(x));
			break;
		case 17:
			printf("%lf",myfloor(x));
			break;
		case 18:
			printf("%lf",myceil(x));
			break;
		case 19:
			printf("%d",myround(x));
			break;
		case 20:
			if(x<1){
				printf("Invalid input");
				return;
			}
			printf("%lf",sqrt(x));
			break;
	}
}

double power(double x,double y){

        double result=1,temp;
        double i;
        if(y==0){
                return 1;
        }
        if(y>0){
                for(i=0;i<y;i++){
                        result=result*x;
                }
                return result;
        }
        if(y<0){
                temp=1/x;
                for(i=-1;i>y;i--){
                        temp=temp/x;
                }
                return temp;
        }
}


/*For the calculation of Factorial*/

double factorial(int x){
        int i;
        double result=1;
        for(i=2;i<x+1;i++){
                result=result*i;
}
        return result;
}

/* For the calculation of sine */

double sine(double x){
        int s,count,i;
/*      float sum;      */
        double sum,t,m,k,j,l;
        k=x;
/*      while((s/360)!<360){ */
                s=x/360;
/*      } */
        j=k-s*360;
/*      m=x/360;
        s= x % 360;*/
        if((j==0)||(j==180)||(j==360)){
                return 0;
        }
        if(j==90){
                return 1;
        }
        if(j==270){
                return -1;
        }
        t=(j*22)/(7*180);
        sum=t;
        count=1;
        for(i=3;i<81;i+=2){
                if(count%2==1){
                        l=(power(t,i)/factorial(i));
                        sum=sum-l;
                }
                if(count%2==0){
                        l=(power(t,i)/factorial(i));
                        sum=sum+l;
                }
                count++;
        }
        if(/*(j>0)&&*/(j<180)){
//              printf("The answer is %lf",sum);
                return sum;
        }
        if((j>180)/*&&(j<360)*/){
                sum=sum*(1);
//                printf("The answer is %lf",sum);
                return sum;
	}
}


double cos(double x){
        int s,count,i;
/*      float sum;      */
        double sum,t,m,k,j,l;
        k=x;
/*      while((s/360)!<360){ */
                s=x/360;
/*      } */
        j=k-s*360;
/*      m=x/360;
        s= x % 360;*/
        if((j==90)||(j==270)){
                return 0;
        }
        if((j==0)||(j==360)){
                return 1;
        }
        if(j==180){
                return -1;
      }
/*      if((x/90)%2==0){
                return 0;
        }
        
        s=x%360;*/
        t=(j*22)/(7*180);
        sum=1;
        count=1;
        for(i=2;i<80;i+=2){
                if(count%2==1){
                        l=(power(t,i)/factorial(i));
                        sum=sum-l;
                }
                if(count%2==0){
                        l=(power(t,i)/factorial(i));
                        sum=sum+l;
                }
                count++;
        }
        if(/*(j>0)&&*/(j<180)){
//              printf("The answer is %lf",sum);
                return sum;
	}
        if((j>180)/*&&(j<360)*/){
                sum=sum*(1);
//              printf("The answer is %lf",sum);
                return sum;
        }
}

double tan(double x){
        double sum;
        sum=((sine(x))/(cos(x)));
        return sum;
}

double sineinverse(float x){
        double sum,ans,t;
        int i;
        if((x<-1)||(x>1)){
                printf("Invalid entry\n");
                return 0;
        }
        if(x==0){
                return 0;
        }
        if(x==1){
                return 90;
        }
        if(x==-1){
                return -90;
        }
        if(x==0.5){
                return 30;
        }
        if(x==-0.5){
                return -30;
        }
        sum=x+(power(x,3)/6);
        t=(power(x,3)/6);
        for(i=5;i<25;i+=2){
                sum=sum + ((power(t,2)*(i-3)*(i-3))/(i-4));
                t=((power(t,2)*(i-3)*(i-3))/(i-4));
        }
        ans=(sum*181*7)/22;
        return ans;
}

double cosinverse(float x){
        double sum,ans;
        if(x==0){
                return 90;
        }
        if(x==1){
                return 0;
        }
        if(x==-1){
                return 180;
        }
        if(x==0.5){
                return 60;
        }
        if(x<0){
                x=(-1)*x;
        }
        sum=sineinverse(x);
        ans=90-sum;
        return ans;
}

double sinh(double x){
        double sum,t;
        int i;
        sum=x;
        for(i=3;i<100;i+=2){
                sum=sum+((power(x,i)/factorial(i)));
        }
        return sum;
}

double cosh(double x){
        double sum,t;
        int i;
        sum=1;
        for(i=2;i<100;i+=2){
                sum=sum + (power(x,i)/(factorial(i)));
        }
        return sum;
}


double gcd(double x , double y){
        while(x!=y){
                if(x>y){
                        x -= y;
                }
                else
                        y -= x;
                }
        return x;
}

double lcm(double x , double y){
        double m,n,j;
        m=x;
        n=y;
        while(x!=y){
                if(x>y){
                        x -=y;
                }
                else
                        y -= x;
                }
        j=x;
        y=(m*n)/j;
        return y;
}


//This log() function returns the logarithmic value  of x to the base e                 
double log(double x) {
        if (x < 0.00000000) {
                printf("invalid input ");
                return -1;
        }
        if (x == 0) {
                printf("ERROR:Entered value should be greater than 0 as domain is the numbers greater than ZERO ");
                return -1;
        }
        double y;
        y = (x - 1)/(x + 1);
        double sum;
        sum = 0.0;
        double den = 1.0;
        double frac = y;
        double term = frac / den;
        while(term > 0.00000000000001) {
                sum += term;
                den += 2.0;
                frac = frac * y * y;
                term = frac / den;
        }
        return 2.0 * sum;
}
//This log10() fuction returns the natural logarithmic value of x       
double logbase10(double x) {
        if (x < 0.00000000) {
                printf("invalid input ");
                return -1;
        }
        if (x == 0) {
                printf("ERROR:Entered value should be greater than 0 as domain is the numbers greater than ZERO");
                return -1;
        }
        else {
                double l;
                l = log(x);
                return (l / 2.3025850929940);
        }
}

                                                                                                                           
double exponential(double x){
        double sum=1;
        int i;
        for(i=1;i<150;i++){
                sum=sum + ((power(x,i))/factorial(i));
        }
        return sum;
}


//This fabs() function returns absolute value of the number
double fabs(double x) {
        if (x >= 0.00)
                return x;
        else
                return (-x);
}



//This floor() function returns largest integral value less than x. 
double myfloor(double x) {
        int y = (int) x;
        if(x >= 0) {
                return (double)(y);
        }
        if((x < 0) && (y > x)) {
                return (double)(--y);
        }
        else if((x < 0) && (x = y)) {
                return (double)(y);
        }
}
//This myceil() function returns smallest integral value that exceeds x. 
double myceil(double x) {
        int y = (int) x;
        if((x >= 0) && (y < x))
                return (double)(++y);
        else if((x >= 0) && (y == x))
                return (double)(y);
        if(x < 0)
                return (double)(y);
}
//this myround() fuction returns rounding of value of given double value.
int myround(double x) {
        if(x < 0.0)
                return (x - 0.5);
        else
                return (x + 0.5);
}
	
double tanh(double x){
	double sum,t,l;
	t=sinh(x);
	l=cosh(x);
	sum=t/l;
	return sum;
}


//This sqrt() function returns the squareroot of given number
double sqrt(double x) {
        if (x < 0.00000000) {
                printf("invalid input ");
                return -1;
        }
        double l, h = x, b;
        double m;
        int i;
        l = 0.0;
        m = (l + h) / 2;
        for (i = 0; i <= 50; i++) {
                b = m * m;
                if(b == x) {
                        return m;
                        break;
                }
                else {
                        if(m * m > x) {
                                h = m;
                                m = (l + h) / 2;
                        }
                        else {
                                l = m;
                                m = (l + h) / 2;
                        }
                }
        }
        return m;
}

