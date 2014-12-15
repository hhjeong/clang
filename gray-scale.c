#include <stdio.h>

typedef struct {
    int r, g, b;
} Pixel;

int calc( Pixel p ) { 
    return (int) ( 0.2126 * p.r + 0.7152 * p.g + 0.0722 * p.b );
}

int main() {
    Pixel image[10][10];
    int n;
    int i, j;
    
    for( i = 0 ; i < 10 ; ++i )
        for( j = 0 ; j < 10 ; ++j ) 
            image[i][j].r = image[i][j].g = image[i][j].b = 0;    

    scanf("%d", &n);

    while(n--) {
        int h, w;
        int r, g, b;
        scanf("%d %d", &h, &w);
        Pixel *p = &image[h][w];
        scanf("%d %d %d", &(p->r), &(p->g), &(p->b));
    }   
    for( i = 0 ; i < 10 ; ++i ) { 
        for( j = 0 ; j < 10 ; ++j ) { 
            printf("%4d", calc( image[i][j] ) );
        }
        printf("\n");
    }


}
             
