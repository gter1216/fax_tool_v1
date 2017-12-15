
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int hour;
	int minute;
	int sec;
	int msec;
} pcm_timestamp_t;

//void add_pcm_ts(pcm_timestamp_t * s, const int inc_msec)
//{
//	int new_msec = 0;
//	int new_sec = 0;
//	int new_min = 0;
//
//	////printf("xx debug, hahahaaaaaaaaaa\n");
//	////printf("xx debug, sec is: %02d, msec is: %03d\n", s->sec, s->msec);
//
//	new_msec = s->msec + inc_msec;
//
//	if (new_msec < 1000)
//		s->msec = new_msec;
//	else
//	{
//		new_sec = s->sec + 1;
//		s->msec = new_msec - 1000;
//		//if (new_sec < 60)
//		//	s->sec = new_sec;
//		//	else
//		//	{
//		//		new_min = s->minute + 1;
//		//		s->sec = new_sec - 60;
//		//		if (new_min < 60)
//		//			s->minute = new_min;
//		//		else
//		//		{
//		//			s->hour++;
//		//			s->minute = new_min - 60;
//		//		}
//		//	}
//	}
//}
//
//void print_pcm_ts(pcm_timestamp_t * s)
//{
//	printf("Current pcm timestamp is -> %02d:%02d:%02d.%03d\n",
//		s->hour,
//		s->minute,
//		s->sec,
//		s->msec);
//}

const char * get_ts_tag(pcm_timestamp_t * s)
{
	// static char buffer[100];
	// char *buffer = (char*)malloc(sizeof(char) * 100);

	char buf[100];
	char * buffer;
	buffer = buf;

	sprintf(buffer, "%02d:%02d:%02d.%03d ---> ",
		s->hour,
		s->minute,
		s->sec,
		s->msec);

	return buffer;
}


int main()
{
	printf("Hello World!\n");
	pcm_timestamp_t * pts;
	const char * io;

	pts = (pcm_timestamp_t *)malloc(sizeof(*pts));

	pts->hour = 12;
	pts->minute = 21;
	pts->sec = 32;
	pts->msec = 341;

	io = get_ts_tag(pts);

	printf("Test1: %s\n", io);

	printf("Test2: %s\n", io);

	printf("Test3: %s\n", io);

	//print_pcm_ts(pts);

	//for (int i =0; i<1000; i++)
	//{
	//	add_pcm_ts(pts, 20);
	//	print_pcm_ts(pts);
	//}
}

