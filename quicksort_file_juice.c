#include <stdio.h>
#include <stdlib.h>

#define BUF 256

void __fastcall swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int __fastcall partition(int*& nums, int start, int end) {
	int pivot = nums[(start + end) / 2];
	while (start <= end) {
		while (nums[start] < pivot)
			start++;
		while (nums[end] > pivot)
			end--;
		if (start >= end)
			break;
		swap(nums[start++], nums[end--]);
	}
	return end;
}

int __fastcall quicksort(int*& nums, int start, int end) {
	if (start >= end) return 0;
	int q = partition(nums, start, end);
	quicksort(nums, start, q);
	quicksort(nums, q + 1, end);
}

int main(int argc, char* argv[]) {
	if (argc != 3) return 1;
	FILE* infile, *outfile;
	fopen_s(&infile, argv[1], "ab");
	fputs("\r\n", infile);
	fclose(infile);
	fopen_s(&infile, argv[1], "rb");
	fopen_s(&outfile, argv[2], "wb");
	if (!infile || !outfile) return 2;
	char tmp[BUF] = "";
	int* num_str = NULL;

	int count = atoi(fgets(tmp, BUF, infile));
	for (int i = 0; i < BUF; ++i) {
		if (tmp[i] < '0' || tmp[i] > '9') {
			if (tmp[0] == '\r') return 3;
			if (tmp[i] == '\r' || tmp[i] == '\n')
				break;
			else return 3;
		}
	}
	if (count < 0) return 3;
	fputs(tmp, outfile);
	num_str = (int*)malloc(count * sizeof(int));
	char** str = (char**)malloc(sizeof(char*));
	for (int i = 0; i < count; ++i) {
		str[i] = (char*)malloc(sizeof(char) * BUF);
		fgets(str[i], BUF, infile);

		for (int j = 0; j < BUF; ++j) {
			if (str[i][j] >= '0' && str[i][j] <= '9' || str[i][j] == ' ') {
				if (str[i][j] == ' ') {
					break;
				}
			}
			else return 3;
		}
		num_str[i] = atoi(str[i]);
		str = (char**)realloc(str, sizeof(char*) * (i + 2));
	}
	fclose(infile);

	quicksort(num_str, 0, count-1);

	for (int i = 0; i < count; ++i) {
		for (int j = 0; j < count; ++j) {
			if (num_str[i] == atoi(str[j])) {
				fputs(str[j], outfile);
				free(str[j]);
				break;
			}
		}
	}

	free(str);
	free(num_str);
	fclose(outfile);
	return 0;
}