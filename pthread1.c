#include<stdio.h>
#include<pthread.h>
#define N 5
void* thread_fn(void*);
pthread_mutex_t mutex1=PTHREAD_MUTEX_INITIALIZER;
int counter=0;

int main(){
pthread_t thread_id[N];
int i,j;
for(i=0;i<N;i++){
pthread_create(&thread_id[i],NULL,thread_fn,NULL);
}
for(j=0;j<N;j++){
pthread_join(thread_id[i],NULL);
}
printf("counter=%d",counter);
return 0;
}

void* thread_fn(void* ptr){
printf("thread no= %ld \n",pthread_self());
pthread_mutex_lock(&mutex1);
counter++;
pthread_mutex_unlock(&mutex1);
}
