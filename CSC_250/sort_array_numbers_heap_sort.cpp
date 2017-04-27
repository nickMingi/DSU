#include <stdio.h>

void heap_sort(int* numbers, int count){

	int temp;

	for(int i = count -1; i > 0; --i){
		temp = numbers[i];
		numbers[i] = numbers[0];
		numbers[0] = temp;
		percolate_down(numbers, i , 0);
	}
}

void heapify(int* numbers, int count){
	for (int i = count / 2 - 1; i >= 0; --i)
	{
		percolate_down(numbers, count, i);
	}
}

void percolate_down(int* numbers, int count, int index){
	while(index * 2 + 1 < count){
		int swap_index = index;
		int left_child_index = index * 2 + 1;
		int right_child_index = index * 2 + 2;
		bool has_left_child = left_child_index < count;
		bool has_right_child = right_child_index < count;

		if(has_left_child && has_right_child){
		
			if(numbers[left_child_index] > numbers[right_child_index]){
				swap_index = left_child_index;
			}else{
				swqp_index = right_child_index;
			}
		}else if(has_left_child){
			swap_index = left_child_index;
		}else if(has_right_child){
			swap_index = right_child_index;
		}else{
			break;
		}

		if(numbers[swap_index] > numbers[index]){
			int temp = numbers[index];
			numbers[index] = numbers[swap_index];
			numbers[swap_index] = temp;
			index = swap_index;
		}else {
			break;
		}
	}
}