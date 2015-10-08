#include <stdio.h>
#include <math.h>
#include <malloc.h>
//cc -o ct ct.c -lm
typedef struct {
	int len;
	int *samples;
}sampleset;

sampleset s,b;
int slookup (int n) {
	if(n<0)
		return *(s.samples);
	if(n>s.len)
		return *(s.samples+s.len);
	return *(s.samples+n);
}
void getsamples( sampleset *s) {
	int c=0;
	int blocks=400;
	char ins[9000];//dont go over 9000
	s->len=blocks;
	while(gets(ins) && !feof(stdin)) {
		if(c>s->len){
			s->samples=realoc(s->samples,s->len+blocks);//TODO: error checking (this whole function really)
			s->len+=blocks;
		}
		(s->samples+c)=atoi(ins);
	}
		
}
void dumpsamples(sampleset s) {
	int i=0;
	for(i=0;i<s.len;i++)
		printf("%d\n",*(s.samples+i));
}
//-----------
int (*func)(int); //pointer to function to transform
int costf(int x,int v) { //cos transform formula where x is integration var, and v is frequency
	//not thread safe (at all)
	return cos(x*pi*v)*(*func)(x);
}
int aint (int a, int b, int (*f)(int,int), int v) { //sum f(x,v) from x=a to x=b with v constant (aproximate integral maybe better later)
	int i=0;//It's really a reiman sum so we should use i and not x
	int c=0;//counter
	for(i=a;i<=b;i++) {
		c=(*f)(i,v);
	}
	return c;
}
sampleset transform(int bincount,int a, int b, int (*f)(int) ) {//not thread safe
	sampleset bins;
	bins.len=bincount;
	bins.samples=malloc(s.len);
	int i=0;
	func=f;
	for(i=0;i<bins.len;i++)
		*(bins.samples+i)=aint(a,b,costf,i); 
	return bins;
	
}
//-----------
int main (int argc, char *argv[]) {
	getsampls(&s);
	b=transform(10,0,len,slookup);
	dumps(b);
	free(b.samples);
}
