#include <time.h>
#include <sys/time.h>/* timeval, gettimeofday() */
#include "vector.h"
#include "vector.h"
#include "list.h"
#include "list.h"

struct timeval start, stop;




void profileInsert(Vector * vect,List * list){
gettimeofday(&start, NULL);
	for(int i = 0 ; i <= 1000 ; i++){
		vect->insert(vect, i, (Data){i+1});
	}
//code to be profiled…
gettimeofday(&stop, NULL);
time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
float profile_time = stop_time - start_time;
printf("\n\t=========Insert Vect time===========\n\n");
printf("%f\n", profile_time);


gettimeofday(&start, NULL);
int index = 0;
	//add elements to the list
	for(index = 0 ; index <= 1000 ; index++ ){
		list->insert(list , index, (Data){index+1});
	}

//code to be profiled…
gettimeofday(&stop, NULL);
start_time = (start.tv_sec* 1000000) + start.tv_usec;
stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
profile_time = stop_time - start_time;
printf("\n\t=========Insert List time===========\n\n");
printf("%f\n", profile_time);
}



void profileRead(Vector * vect,List * list){
gettimeofday(&start, NULL);
for(int i = 0 ; i < 100 ; i++){
		Data * d = vect->read(vect, (rand() % 100) + 1);
	}

//code to be profiled…
gettimeofday(&stop, NULL);
time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
float profile_time = stop_time - start_time;
printf("\n\t=========Read Vector time===========\n\n");
printf("%f\n", profile_time);


gettimeofday(&start, NULL);
for(int index = 0 ; index < 100 ; index++){
		Data * d = list->read(list, (rand() % 100) + 1);
	}
//code to be profiled…
gettimeofday(&stop, NULL);
start_time = (start.tv_sec* 1000000) + start.tv_usec;
stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
profile_time = stop_time - start_time;
printf("\n\t=========Read List time===========\n\n");
printf("%f\n", profile_time);

}




void profileRemove(Vector * vect,List * list){
gettimeofday(&start, NULL);
for(int i = 0; i<100; i++){
		vect->remove(vect , (rand() % 100) + 1);
	}

//code to be profiled…
gettimeofday(&stop, NULL);
time_t start_time = (start.tv_sec* 1000000) + start.tv_usec;
time_t stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
float profile_time = stop_time - start_time;
printf("\n\t=========Remove Vector time===========\n\n");
printf("%f\n", profile_time);



gettimeofday(&start, NULL);
for(int index = 0; list->head != NULL,index<100; index++){
		list->remove(list , (rand() % 100) + 1);
	}
//code to be profiled…
gettimeofday(&stop, NULL); 
start_time = (start.tv_sec* 1000000) + start.tv_usec;
stop_time = (stop.tv_sec* 1000000) + stop.tv_usec;
profile_time = stop_time - start_time;
printf("\n\t=========Remove List time===========\n\n");
printf("%f\n", profile_time);


}



