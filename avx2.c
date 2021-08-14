#include <immintrin.h>
#include <stdio.h>

int main() {
	avxcalc();
}

void avxcalc(){
  __m256 f32_array_1 = _mm256_set_ps(2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0, 16.0);
  __m256 f32_array_2 = _mm256_set_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);
  __m256i i32_array1 = _mm256_set_epi32(100, 200, 300, 400, 500, 600, 700, 800);
  __m256i i32_array2 = _mm256_set_epi32(-20, -72, -48, -9, -100, 3, 5, 8);
  __m256i i64_array1 = _mm256_set_epi64x(1, 2, 8, -5);
  __m256i i64_array2 = _mm256_set_epi64x(5, -9, 7, 8);

  __m256 result1 = _mm256_add_ps(f32_array_1, f32_array_2);
  __m256 result2 = _mm256_sub_ps(f32_array_1, f32_array_2);
  __m256i result3 = _mm256_add_epi32(i32_array1, i32_array2);
  __m256i result4 = _mm256_sub_epi32(i32_array1, i32_array2);
  __m256i result5 = _mm256_sub_epi64(i64_array1, i64_array2);
   
  printf("add f32:\n");
  float* f = (float*)&result1;
  printf("%f %f %f %f %f %f %f %f\n", f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
  printf("sub f32:\n");
  f = (float*)&result2;
  printf("%f %f %f %f %f %f %f %f\n", f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
  printf("add i32:\n");
  int* i = (int*)&result3;
  printf("%d %d %d %d %d %d %d %d\n", i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7]);
  printf("sub i32:\n");
  i = (int*)&result4;
  printf("%d %d %d %d %d %d %d %d\n", i[0], i[1], i[2], i[3], i[4], i[5], i[6], i[7]);
  printf("sub i64:\n");
  i = (int*)&result5;
  printf("%d %d %d %d\n", i[0], i[1], i[2], i[3]);
}
