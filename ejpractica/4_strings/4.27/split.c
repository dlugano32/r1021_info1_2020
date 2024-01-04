#include <stdio.h>
#include <string.h>

int split (int n, int k);

int main(void)
{
	int i,n;
	scanf("%d", &i);
	scanf("%d", &n);
	printf("%d",split(n,i));
	
	
	return 0;
}

int split (int n, int k){
    while(n--)
        k/=10;
    return k%10;
}
