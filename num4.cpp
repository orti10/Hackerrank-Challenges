//Functions

#include <iostream>
#include <cstdio>
using namespace std;


int max_of_four(int a, int b, int c, int d){
    int max=0;
    if(a>max) max=a;
    if(b>max) max=b;
    if(c>max) max=c;
    if(d>max) max=d;
return max;
}

/* another way
int arr[4]={a,b,c,d};
int max=arr[0];
for(int i=0;i<4;i++){
 if(max<arr[i])
        max=arr[i];
}
return max;
*/


int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}

