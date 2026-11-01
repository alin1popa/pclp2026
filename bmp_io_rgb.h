#ifndef BMP_IO_RGB_H
#define BMP_IO_RGB_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define BMP_GET32(p) ((uint32_t)(p)[0] | (uint32_t)(p)[1]<<8 | (uint32_t)(p)[2]<<16 | (uint32_t)(p)[3]<<24)
#define BMP_PUT32(p,v) do { uint32_t bmp_v_ = (uint32_t)(v); for(int bmp_k_=0; bmp_k_<4; ++bmp_k_) (p)[bmp_k_] = (unsigned char)(bmp_v_ >> (8*bmp_k_)); } while(0)

/* img[N][M][3]: canalele 0=R, 1=G, 2=B; img[0][0] = coltul stanga-sus.
   Fiecare img[i] si img[i][j] este alocat separat. Citire BI_RGB 24/32 bpp.
   Returneaza NULL la eroare; pentru argumente valide, *N si *M raman 0. */
static inline unsigned char ***bmp_read(const char *path, int *N, int *M)
{
    if (!N || !M || N == M) return NULL;
    *N = *M = 0; if (!path) return NULL;
    FILE *f = fopen(path, "rb"); if (!f) return NULL;
    unsigned char h[54], *buf=NULL, ***img=NULL; int nr=0, nc=0;
    if (fread(h, 1, 54, f) != 54 || h[0]!='B' || h[1]!='M') goto fail;
    uint32_t off=BMP_GET32(h+10), dib=BMP_GET32(h+14), w=BMP_GET32(h+18), sh=BMP_GET32(h+22);
    int top = (int)(sh >> 31), b = h[28]/8; uint32_t n = top ? (uint32_t)(0u-sh) : sh;
    if ((dib!=40 && dib!=52 && dib!=56 && dib!=108 && dib!=124) || (uint64_t)off<14ull+dib ||
        h[26]!=1 || h[27] || (h[28]!=24 && h[28]!=32) || h[29] || BMP_GET32(h+30) ||
        !w || w>INT32_MAX || w>INT_MAX || !n || n>INT32_MAX || n>INT_MAX) goto fail;
    uint64_t stride = ((uint64_t)w*b+3)/4*4;
    if (stride>SIZE_MAX || (uint64_t)n*sizeof(*img)>SIZE_MAX || (uint64_t)w*sizeof(**img)>SIZE_MAX) goto fail;
    if (fseek(f, 0, SEEK_END)) goto fail;
    long len = ftell(f);
    if (len<0 || (uint64_t)len<(uint64_t)off+stride*n || fseek(f, (long)off, SEEK_SET)) goto fail;
    img=malloc((size_t)n*sizeof(*img)); buf=malloc((size_t)stride); if (!img || !buf) goto fail;
    for (uint32_t y=0; y<n; ++y) {
        img[y]=malloc((size_t)w*sizeof(**img)); if (!img[y]) goto fail; ++nr; nc=0;
        for (uint32_t x=0; x<w; ++x) { img[y][x]=malloc(3); if (!img[y][x]) goto fail; ++nc; }
    }
    for (uint32_t y=0; y<n; ++y) {
        if (fread(buf, 1, (size_t)stride, f)!=(size_t)stride) goto fail;
        for (size_t x=0; x<w; ++x)
            for (int k=0; k<3; ++k) img[top?y:n-1-y][x][k]=buf[b*x+2-k];
    }
    free(buf); fclose(f); *N=(int)n; *M=(int)w; return img;
fail:
    if (img) { for (int y=0; y<nr; ++y) { for (uint32_t x=0; x<(y==nr-1?(uint32_t)nc:w); ++x) free(img[y][x]); free(img[y]); } free(img); }
    free(buf); fclose(f); return NULL;
}

/* Scrie BMP 24 bpp. Returneaza 1 la succes, 0 la eroare. Nu modifica matricea. */
static inline int bmp_write(const char *path, unsigned char ***img, int N, int M)
{
    if (!path || !img || N<=0 || M<=0) return 0;
    if ((uint64_t)N>INT32_MAX || (uint64_t)M>INT32_MAX) return 0;
    uint64_t stride=((uint64_t)M*3+3)/4*4, bytes=stride*(uint64_t)N;
    if (stride>SIZE_MAX || bytes>UINT32_MAX-54u) return 0;
    for (int y=0; y<N; ++y) { if (!img[y]) return 0; for (int x=0; x<M; ++x) if (!img[y][x]) return 0; }
    unsigned char h[54]={0}, *buf=calloc(1,(size_t)stride); if (!buf) return 0;
    h[0]='B'; h[1]='M'; h[26]=1; h[28]=24;
    BMP_PUT32(h+2,54+bytes); BMP_PUT32(h+10,54); BMP_PUT32(h+14,40);
    BMP_PUT32(h+18,M); BMP_PUT32(h+22,N); BMP_PUT32(h+34,bytes);
    FILE *f=fopen(path,"wb"); if (!f) { free(buf); return 0; }
    int ok=fwrite(h,1,54,f)==54;
    for (int y=N; ok && y-->0;) {
        for (size_t x=0; x<(size_t)M; ++x)
            for (int k=0; k<3; ++k) buf[3*x+2-k]=img[y][x][k];
        ok=fwrite(buf,1,(size_t)stride,f)==(size_t)stride;
    }
    if (fclose(f)!=0) ok=0;
    free(buf); return ok;
}
#undef BMP_GET32
#undef BMP_PUT32
#endif
