//Pointer

#include <stdio.h>

void update(int *a,int *b) {
    int absDifference=0;
    int sum = *a + *b;
    if((*a-*b)>0){
        absDifference = *a-*b;
    }
    else{
        absDifference = -(*a-*b);
    }
    *a = sum;
    *b = absDifference; 
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}