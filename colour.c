#include <stdio.h>

#include <wiringPi.h>
#include <softPwm.h>

const int blue = 23; const int green = 24; const int red = 25;

int main() {
	system ("/bin/stty raw");
	srand(1);
	wiringPiSetup();

	softPwmCreate(red, 0, 100);
	softPwmCreate(blue, 0, 100);
	softPwmCreate(green, 0, 100);

	int r = 0;
	int g = 0;
	int b = 0;
	for (;;) {
		softPwmWrite(red, r);
		softPwmWrite(blue, b);
		softPwmWrite(green, g);

		switch (getchar()) {
			case 'r': r++; break;
			case 'R': r--; break;
			case 'g': g++; break;
			case 'G': g--; break;
			case 'b': b++; break;
			case 'B': b--; break;
			default: return 0;
		}

	}

	softPwmWrite(red, 0);
	softPwmWrite(blue, 0);
	softPwmWrite(green, 0);

	getc(stdin);
}
