#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[])
{
	double radius = 0.5;
	double centerX = 0.5;
	double centerY = 0.5;
	double x,y;
	double calcX,calcY;
	int score = 0;
	int total;
	int i;

	if (argc != 2){
		total = 10000000;
	}

	else {
		total = atoi(argv[1]);
	}

	srand(time(NULL));

	time_t seconds = time(NULL);

	for (i = 0; i < total; i++) {
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;

		calcX = x-centerX;
		calcY = y-centerY;

		if ((pow(calcX,2.0)+pow(calcY,2.0)) < pow(radius,2.0)) {
			score+=1;
		}
	}
	
	double pi = 4.0*(double)score/total;
	seconds = time(NULL) - seconds;
	double error = fabs((pi-M_PI)*100);

	printf("Out of %d randomly generated points, %d of them were within the area of the circle.\n",total,score);
	printf("The estimated value of pi is %.17lf.\n",pi);
	printf("Error of estimated value is %lf\n",error);
	printf("It took %ld seconds to estimate pi.\n",seconds);

	return 0;
}