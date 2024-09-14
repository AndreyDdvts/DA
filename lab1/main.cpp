#include <iostream>
#include <string.h>



const int MAX_KEY_VALUE = 65535;



struct Pair {
  int key;
  char value[65];
};



void scan_array(Pair **array, int array_size, int *pair_counter) {
  while (std::cin >> (*array)[*pair_counter].key >> (*array)[*pair_counter].value) {
    ++(*pair_counter);
    if ((*pair_counter) == array_size) {
      array_size *= 2;
      (*array) = (Pair *)realloc((*array), array_size * sizeof(Pair));
    }
  }
}

void print_array(Pair *array, int pair_counter) {
  for (int i = 0; i < pair_counter; ++i) {
    std::cout << array[i].key << '\t' << array[i].value << '\n';
  }
}



void count_sort(Pair *array, Pair *new_array, int pair_counter) {
  int frequency[MAX_KEY_VALUE + 1];
  memset(frequency, 0, (MAX_KEY_VALUE + 1)*sizeof(int));

  for (int i = 0; i < pair_counter; ++i) {
    ++frequency[array[i].key];
  }

  int total_counter = 0, old_counter;
  for (int i = 0; i <= MAX_KEY_VALUE; ++i) {
    old_counter = frequency[i];
    frequency[i] = total_counter;
    total_counter += old_counter;
  }

  for (int i = 0; i < pair_counter; ++i) {
    new_array[frequency[array[i].key]] = array[i];
    ++frequency[array[i].key];
  }
}



int main() {
  int pair_counter = 0;
  
  Pair *array = (Pair *)malloc(sizeof(Pair));
  scan_array(&array, 1, &pair_counter);
  Pair *new_array = (Pair *)malloc(pair_counter * sizeof(Pair));
  count_sort(array, new_array, pair_counter);
  print_array(new_array, pair_counter);

  free(array);
  free(new_array);
  
  return 0;
}
