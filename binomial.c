/*********
Binomial distribution
ST practical 1
Date: 17/1/2019
************/

#include<stdio.h>
#include<math.h>

int nCr(int n,int r){

	if(r == 0 || r == n) return 1;

	int i,j, num = 1, den = 1;
	int den_f, num_f;

	if(r > n/2)	den_f = n-r;
	else den_f = r;

	if(den_f == 0) den_f = 1;

	for(i = 1;i <= den_f;i++) den = den*i;
	for(i = n, j = 0;j < den_f;j++,i--) num = num*i;
	//printf("num = %d, den = %d\n",num, den);
	return num/den;
}

int main(int argc, int *argv[]){
	int n,r;
	float p;

	printf("Enter n, r and p space separated\n");
	scanf("%d %d %f",&n,&r,&p);

	if(r == -1){
		float nj = 0.0;
		for(int i = 0;i <= n;i++){
			printf("r = %d P(r) = %0.4f\n", i, nCr(n,i)*pow(p,i)*pow(1-p,n-i));
			nj += nCr(n,i)*pow(p,i)*pow(1-p,n-i);
		}
		printf("%0.4f\n",nj);
	}
	else{
		int ncr = nCr(n,r);
		//printf("ncr = %d\n",ncr);
		printf("Result = %0.4f\n",ncr*pow(p,r)*pow(1-p,n-r));
		return 0;
	}
}
