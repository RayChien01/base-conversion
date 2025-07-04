#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

#include<vector>
#include<iostream>

void converted_output(unsigned long long num, unsigned short output_base){
    
    unsigned short int i = 0, remainder;
    const char base_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    std::vector<char> converted(0);

    do{
        remainder = num % output_base;
        converted.push_back(base_digits[remainder]);
        num = num / output_base;
        i++;
    }while(num != 0);

    if(output_base == 2)
        printf("0b");
    else if(output_base == 8)
        printf("0");
    else if(output_base == 16)
        printf("0x");
    
    while(i > 0){
        i--;
        printf("%c", converted[i]);
    }

    printf("\n");
}

int main(void){

    while(1){
        unsigned long long int num = 0;
        unsigned short int input_base;
        std::string input;
        const char base_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};    

        printf("To convert to another base, please enter a posotive integer, or enter q to quit.\n");
        std::cin >> input;

        if(input[0] == '0'){
            if(tolower(input[1]) == 'b'){
                input_base = 2;
            }
            else if(tolower(input[1]) == 'x'){
                input_base = 16;
            }
            else input_base = 8;
        }
        else if(tolower(input[0]) == 'q'){
            break;
        }
        else{
            input_base = 10;
        }

        {    
            unsigned short int num_to_add;
            for(int i = input.length()-1; i >= 0; i--){

                num_to_add = 0;
                for(short int j = 0; j < 16; j++){
                    if(toupper(input[i]) == base_digits[j]){
                        num_to_add = j;
                    }
                }

                for(unsigned short int j = 1; j < (input.length() - i); j++){
                    num_to_add *= input_base;
                }
                num += num_to_add; 
            }
        }

        converted_output(num, 2);
        converted_output(num, 8);
        converted_output(num, 10);
        converted_output(num, 16);
    }
    system("pause");
    return 0;

}
