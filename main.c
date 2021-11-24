#include <stdio.h> /*printf, scanf*/
#include <string.h> /*strlen*/
#include <stdlib.h> /*malloc*/


const char * set_lst(char input_lst[]); /*function prototype*/

int main(void) {
  // calls the function set_lst
  // input_sentence has been set 200 indexs, 200 or more chars should result in crashing or misbehaviour. 
  char input_sentence[200];
  printf("enter sentence\n");
  scanf("%[^\n]%*c", input_sentence);
  printf("%s", set_lst(input_sentence));
  return 0;
}

// function defined
const char * set_lst(char input_lst[]){
  
  // declare variables 
  int length = strlen(input_lst);

  // set_temp is given a fixed array size of ::length of input_lst + 1:: the maximum size a set can be is the same size as the input, the set of "abcdef" is still "abcdef" ... the +1 is given so that the array has space for the null character '\0' 
  char *set_temp = malloc((length + 1) * sizeof(char));
  // when a value is stored in set_temp, set_temp_indexes increases by 1 so that each item stored is in the next index avaliable.
  int set_temp_indexes = 0;
  // used to track how many matches of a char there are between the input_lst and the set_lst
  int match_counter = 0;


  // if i is 2 and j were 2, then these for loops would give me i:j values in the order [0:0 0:1 0:2], [1:0 1:1 1:2], [2:0 2:1 2:2] so it will grab the value of i and then print of the values of j before incrementing i. 
  for (int i = 0; i < length; i++ ){
    // printf("%d", i);
    for (int j = 0; j < length; j++){
      // printf("\n%d %d", i, j);
      // this compares every index of the input_lst and set_temp, if they match then the match counter is incremented.
      if (input_lst[i] == set_temp[j]){
        match_counter++;
      }
    }
    // if the match counter is 0 that means that set_temp doesn't contain input_lst[i] so we then store input_lst[i] in set_temp, now if the same char occurs later in the input_lst the match counter will not be 0 which will prevent any more occurances of it being added to set_temp
    if (match_counter == 0){
      // printf("\nraw_list[i] = %c", input_lst[i]);
      set_temp[set_temp_indexes] = input_lst[i];
      set_temp_indexes++;
    }
    // reset the match counter so that it doesn't impact the count of the next char
    match_counter = 0;
  }
  // printf("\n%s", set_temp); 
  
  // as set_temp is a local variable 
  char *processed_lst = set_temp;
  return processed_lst;
}