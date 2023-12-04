#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

long long int	get_ms_time(void);

int main( int argc, char ** argv )
{
	long long int	last_ms;
	long long int	now_ms;
	long long int	sleep_ms;

	sleep_ms = 10;
	while (1)
	{
		last_ms = get_ms_time();
		usleep( sleep_ms * 1000 );
		now_ms = get_ms_time();
		printf( "elapsed_ms%4lldms : usleep%4lldms : diff%3lldms\n", \
			now_ms - last_ms, sleep_ms, now_ms - last_ms - sleep_ms);
		sleep_ms = sleep_ms + 10;
	}
	
	return 0;

}

long long int	get_ms_time(void)
{
	long long int			ms;
    struct timeval			time;

	if (gettimeofday(&time, NULL) != 0)
		return (-1);
    ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}
