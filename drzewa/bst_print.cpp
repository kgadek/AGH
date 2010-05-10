#include <cstdio>
#include <cstdlib>

int n, i, o, c;

void sp(int i) {
	while(i--)
		printf(" ");
}

int main() {
	scanf("%d",&n);
	n = (1<<n)-1;
	i = n;
	o = n;

	while(i>1) {
		i=o;
		for(sp(c=o/=2);c<n;c+=i+1) {
			if(rand()%2)
				printf("%c[;%dmO%c[%dm",0x1B,31,0x1B,0);
			else
				printf("%c[;%dmO%c[%dm",0x1B,30,0x1B,0);
			sp(i);
		}
		printf("\n");
	}
	return 0;
}

