#include <algorithm>
using namespace std;

void shift_line(int *start_point, int const multiplier, int const number_of_elements, int shift){
    shift = shift % number_of_elements;
    int increment = multiplier*shift;
    for(
        int current=0, next=increment;
        next<(number_of_elements*multiplier);
        current=next, next+=increment){
            
        }
        
}

void shift_loop(int **matrix, int const loop, int const rows, int const columns, int const shift_size){
    // Storing shift size number of elements in a temporary array.
    int temp[shift_size];

    int const 
        vertical_length = rows-2*loop, 
        horizontal_length = columns-2*loop;

    int jump_rows_to_top = loop*columns, 
        jump_rows_to_bottom = (rows-loop-1)*columns,
        jump_columns_to_left = loop,
        jump_columns_to_right = columns-loop-1;

    int *first_element{matrix[loop]+loop};

    shift_line(
        first_element + jump_rows_to_top + jump_columns_to_left,
        -columns, 
        vertical_length, 
        shift_size
    );

    shift_line(
        first_element + jump_rows_to_bottom + jump_columns_to_left, 
        -1, 
        horizontal_length, 
        shift_size
    );

    shift_line(
        first_element + jump_rows_to_bottom + jump_columns_to_right, 
        columns, 
        vertical_length, 
        shift_size
    );

    shift_line(
        first_element + jump_rows_to_top + jump_columns_to_right, 
        1, 
        horizontal_length, 
        shift_size
    );
}

void shift_matrix(int **matrix, int const rows, int const columns, int const shift_size){
    // Loops are in the form of concentric rectangles. They get shifted clockwise independently.
    int const number_of_loops = min(rows, columns)/2;
    for(int loop=0; loop < number_of_loops; ++loop){
        shift_loop(matrix, loop, rows, columns, shift_size);
    }
}
