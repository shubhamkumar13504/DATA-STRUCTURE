#include<stdio.h>
#define MAX 5
typedef struct q {
    int data;
    int prior;
}new;

new pri[MAX];

int size=0;
void insert(int d,int p){
    if(size==MAX){
        printf("full");
        return;
    }
    int i=size -1;
    while (i>=0 && pri[i].prior>p){
        pri[i+1]=pri[i];
        i--;
    }
    pri[i+1].data=d;
    pri[i+1].prior=p;
    size++;
}
void delete(){
    if(size==0){
        printf("empty");
    }
    printf("the deleted value is %d\n",pri[0].data);
    for(int i=1 ; i<size;i++){
        pri[i-1]=pri[i];
        i++;
    }
    size--;
}
void display(){
    int  i=0;
    while(i<size){
        printf("thae value is  %d and the priority is %d\n",pri[i].data,pri[i].prior);
        i++;
    }
}
int main(){
    insert(10,3);
    insert(30,1);
    insert(20,2);
    display();
    delete();
    delete();
}