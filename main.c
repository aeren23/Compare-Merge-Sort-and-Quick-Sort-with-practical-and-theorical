#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

double calculate_c_factor(int n, double Tn);
int* generate_random_array(int n);
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void Quick_sort(int arr[], int low, int high);
int Hoare_partition(int arr[], int low, int high);
void swap(int* a, int* b);

int main() {
    srand(time(NULL));

    FILE* fp = fopen("results.txt", "w");
    if (fp == NULL) {
        printf("Dosya açılamadı!\n");
        return 1;
    }
    fprintf(fp, "n,merge_Tn,quick_Tn,merge_c,quick_c\n");

    int time_values[6] = { 1000,5000,10000,50000,100000,200000 };

    for (int i = 0; i < 6; i++) {
        int n = time_values[i];
        double total_time_merge = 0;
        double total_time_quick = 0;

        for (int k = 0; k < 50; k++) {
            int* array_merge = generate_random_array(n);
            int* array_quick = generate_random_array(n);

            clock_t start_merge = clock();
            merge_sort(array_merge, 0, n - 1);
            clock_t end_merge = clock();
            total_time_merge += (double)(end_merge - start_merge) / CLOCKS_PER_SEC;

            clock_t start_quick = clock();
            Quick_sort(array_quick, 0, n - 1);
            clock_t end_quick = clock();
            total_time_quick += (double)(end_quick - start_quick) / CLOCKS_PER_SEC;

            free(array_merge);
            free(array_quick);
        }

        double avg_time_merge = total_time_merge / 50.0;
        double avg_time_quick = total_time_quick / 50.0;

        double c_merge = calculate_c_factor(n, avg_time_merge);
        double c_quick = calculate_c_factor(n, avg_time_quick);

        printf("n=%d  Merge avg: %f  Quick avg: %f  c_merge: %f  c_quick: %f\n",
            n, avg_time_merge, avg_time_quick, c_merge, c_quick);

        fprintf(fp, "%d,%f,%f,%.10f,%.10f\n", n, avg_time_merge, avg_time_quick, c_merge, c_quick);
    }

    fclose(fp);
    printf("Sonuçlar results.txt dosyasına yazıldı.\n");
    return 0;
}

double calculate_c_factor(int n, double Tn) {
    return Tn / (n * log2(n));
}

int* generate_random_array(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 150000;
    }
    return arr;
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    free(L);
    free(R);
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int Hoare_partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
    while (1) {
        do { i++; } while (arr[i] < pivot);
        do { j--; } while (arr[j] > pivot);
        if (i >= j) return j;
        swap(&arr[i], &arr[j]);
    }
}

void Quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int p = Hoare_partition(arr, low, high);
        Quick_sort(arr, low, p);
        Quick_sort(arr, p + 1, high);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
