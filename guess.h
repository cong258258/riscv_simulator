#include <cstdio>
#include <iostream>
#include <cstdlib>
class guessman
{
	int *x;
	int guess_time = 0;
	int guess_right_time = 0;
public:
	guessman()
	{
		x = new int[40000];
		for(int i = 0; i < 40000; i++)
			x[i] = 0;
	}
	~guessman()
	{
		delete [] x;
	}
	int do_guess(unsigned &code)
	{
		guess_time++;
		if(x[code] <= 1)
			return 0;
		else
			return 1;
	}
	void guess_right_taken(unsigned &code)
	{
		// printf("%d  ", code);
		guess_right_time++;
		if(x[code] != 3)
			x[code]++;
	}
	void guess_right_not_taken(unsigned &code)
	{
		// printf("%d  ", code);
		guess_right_time++;
		if(x[code] != 0)
			x[code]--;
	}
	void guess_wrong_taken(unsigned &code)
	{
		// printf("%d  ", code);
		if(x[code] != 3)
			x[code]++;
	}
	void guess_wrong_not_taken(unsigned &code)
	{
		// printf("%d  ", code);
		if(x[code] != 0)
			x[code]--;
	}
	void guess_show_final()
	{
		double per;
		per = double(guess_right_time) / double(guess_time) * 100;
		printf("guess_final: %d  %d   %f%%\n", guess_time, guess_right_time, per);
		// for(int i = 0; i < 40000; i++)
		// 	printf("%d", x[i]);
	}
};