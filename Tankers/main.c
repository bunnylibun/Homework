#include <stdio.h>
#include <stdlib.h> 
#include <strings.h>
#include <math.h> 
#include "lodepng.h" 

unsigned char* load_png(const char* filename, unsigned int* width, unsigned int* height) {
  unsigned char* image = NULL; 
  int error = lodepng_decode32_file(&image, width, height, filename);
  if(error != 0) {
    printf("error %u: %s\n", error, lodepng_error_text(error)); 
  }
  return (image);
}

void write_png(const char* filename, const unsigned char* image, unsigned width, unsigned height) {
  unsigned char* png;
  long long unsigned int pngsize;
  int error = lodepng_encode32(&png, &pngsize, image, width, height);
  if (error == 0) {
      lodepng_save_file(png, pngsize, filename);
  } 
  else { 
    printf("error %u: %s\n", error, lodepng_error_text(error));
  }
  free(png);
}

#define e 25
void contrast (unsigned char* pic, int y1, int x1, int y2, int x2, int width) {
    int m=0;
    for (int i=x1; i<x2; i++) {
        for (int j=y1; j<y2; j++) {
            m += pic[i*width+j];
        }
    }
    m /= (x2-x1)*(y2-y1);
    for (int i=x1; i<x2; i++) {
        for (int j=y1; j<y2; j++) {
            int d = pic[i*width+j]-m;
            if (d >= e) pic[i*width+j]=255;
            else pic[i*width+j]=0;
        }
    }
    return;
}

int dfs(unsigned char* pic, int y1, int x1, int y2, int x2, int width, unsigned char* visited, int x, int y) {
    int ly = y - y1;
    int lx = x - x1;
    int region_width = y2 - y1;
    int idx = lx * region_width + ly;
    if (y < y1 || y >= y2 || x < x1 || x >= x2) return 0;
    if (visited[idx] == 1 || pic[x * width + y] == 0) return 0;
    visited[idx] = 1;
    return 1 + dfs(pic, y1, x1, y2, x2, width, visited, x + 1, y)
             + dfs(pic, y1, x1, y2, x2, width, visited, x - 1, y)
             + dfs(pic, y1, x1, y2, x2, width, visited, x, y + 1)
             + dfs(pic, y1, x1, y2, x2, width, visited, x, y - 1);
}

int count_tankers(unsigned char* pic, int y1, int x1, int y2, int x2, int width) {
    int region_h = y2 - y1;
    int region_w = x2 - x1;
    unsigned char* visited = (unsigned char*)calloc(region_w * region_h, sizeof(unsigned char));
    int ans = 0;
    for (int i = x1; i < x2; i++) {          
        for (int j = y1; j < y2; j++) {                 
            int ly = j - y1;                 
            int lx = i - x1;                 
            int idx = lx * region_h + ly;
            if (pic[i * width + j] != 0 && !visited[idx]) {
                int size = dfs(pic, y1, x1, y2, x2, width, visited, i, j);
                if (size <= 7) {
                    ans++;
                }
            }
            else visited[idx]=1;
        }
    }
    free(visited);
    return ans;
}

void make_bw (unsigned char* colored, int bw_size, unsigned char* bw) {
    for (int i=0; i<bw_size; i++) {
        bw[i]=(colored[i*4]+colored[i*4+1]+colored[i*4+2])/3;
    }
    return;
}

void make_colored (unsigned char* bw, unsigned char* finish, int bw_size) {
    for (int i=0; i<bw_size; i++) {
        finish[i*4]=bw[i];
        finish[i*4+1]=bw[i];
        finish[i*4+2]=bw[i];
        finish[i*4+3]=255;
    }
    return;
}
  
int main(void) { 
    const char* filename = "skull.png"; 
    unsigned int width, height;
    int colored_size, bw_size;
    unsigned char* colored = load_png("skull.png", &width, &height); 
    if (colored == NULL) { 
        printf("Problem reading picture from the file %s. Error.\n", filename); 
        return -1; 
    }
    colored_size = width * height * 4;
    bw_size = width * height;

    unsigned char* bw = (unsigned char*)malloc(bw_size*sizeof(unsigned char));
    make_bw(colored, bw_size, bw);
    
    unsigned char* finish = (unsigned char*)malloc(colored_size*sizeof(unsigned char));
    contrast(bw, 277, 62, 354, 110, width);
    contrast(bw, 533, 19, 724, 245, width);
    contrast(bw, 540, 243, 715, 302, width);
    contrast(bw, 501, 300, 563, 316, width);
    contrast(bw, 547, 315, 752, 337, width);
    contrast(bw, 500, 328, 546, 332, width);
    contrast(bw, 509, 335, 786, 418, width);
    contrast(bw, 570, 420, 814, 471, width);
    contrast(bw, 866, 415, 1125, 640, width);
    contrast(bw, 523, 463, 807, 520, width);
    contrast(bw, 537, 513, 831, 553, width);
    contrast(bw, 566, 570, 760, 602, width);

    printf("%d tankers", count_tankers(bw, 277, 62, 354, 110, width)
                   + count_tankers(bw, 533, 19, 724, 245, width)
                   + count_tankers(bw, 540, 243, 715, 302, width)
                   + count_tankers(bw, 501, 300, 563, 316, width)
                   + count_tankers(bw, 547, 315, 752, 337, width)
                   + count_tankers(bw, 500, 328, 546, 332, width)
                   + count_tankers(bw, 509, 335, 786, 418, width)
                   + count_tankers(bw, 570, 420, 814, 471, width)
                   + count_tankers(bw, 866, 415, 1125, 640, width)
                   + count_tankers(bw, 523, 463, 807, 520, width)
                   + count_tankers(bw, 537, 513, 831, 553, width)
                   + count_tankers(bw, 566, 570, 760, 602, width));

    make_colored(bw, finish, bw_size);
    write_png("picture_out.png", finish, width, height);
    
    free(bw);
    free(finish); 
    free(colored); 
    return 0; 
}
