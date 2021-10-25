#include <stdio.h>
int main() 
{
    int T;
    scanf("%d",&T); 
    int t;
    for(t=1;t<=T;t++)
    {
        long long int n,sum;
        scanf("%lld",&n);
        if (n==1 || n==2)
            printf("1\n");
        else{
            n=n-2;
            sum=(n*(2*2+((n-1)*2)))/2;
            sum=sum+1;
            printf("%lld\n",sum);
            }
    }
}