#ifndef __TIMER_H
#define __TIMER_H

#include <time.h>

class Timer{
private:
	clock_t cur;
public:
	Timer(){ cur = clock(); }
	void tic(){ cur = clock(); }
	void toc(){ 
		printf("time elapse %f seconds.\n", (double)(clock() - cur) / CLOCKS_PER_SEC );
	}
};

#endif /* __TIMER_H */