#include <cstdio>
#include "making_the_grade.cpp"

int main(void){
    std::array<int, 4>returned_array = letter_grades(66);
    
    for (size_t i = 0; i < returned_array.size(); ++i) {
        printf("%d ", returned_array[i]);
    }
    printf("\n");

}