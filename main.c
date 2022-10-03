// convolutional network

#include <stdio.h>
#include<stdlib.h>


int main(){

    int column, line, column_sub_matrix, line_sub_matrix, image_line, image_column,
    maxValue, kernel_line, kernel_column, count_line, count_column, convolutional_line, convolutional_column, edge;

    float kernel_valor, kernel_divider, kernel_dividend, sum_of_products;


    //open kernel
    FILE* kernel_file = fopen("./kernels/unsharp_masking5p5.txt", "r");

    fscanf(kernel_file, "%d %d %f %f", &kernel_line, &kernel_column, &kernel_divider, &kernel_dividend);
    float kernel[kernel_line][kernel_column];

    for(column = 0; column < kernel_column; column++){
        for(line = 0; line < kernel_line; line++){
            fscanf(kernel_file, "%f", &kernel_valor);
            kernel[column][line] = (kernel_divider/kernel_dividend)* kernel_valor;
        }
    }
    // close kernel file
    fclose(kernel_file);

    // open original image
    FILE* img = fopen("./images/person.ascii.pgm", "r");
    fscanf(img, "%*s %d %d %d", &image_line, &image_column, &maxValue);

    convolutional_line = image_line;
    convolutional_column = image_column;

    int convolutional[convolutional_line][convolutional_column];

    edge = 1;
    image_column += edge * 2;
    image_line += edge * 2;

    int image[image_line][image_column];

    //create matrix of 0
    for(column = 0; column < image_column; column++){
        for(line = 0; line < image_line; line++){
            image[line][column] = 0;
        }
    }

    // add border to image
    for(column = edge; column < image_column - edge; column++){
        for(line = edge; line < image_line - edge  ; line++){
            fscanf(img, "%d", &image[line][column]);
        }
    }

    // close image
    fclose(img);

    // performs convolution
    for(column = 1; column < image_line - 1; column++){
        for(line = 1; line < image_column - 1; line++){
            count_line = 0;
            sum_of_products = 0;
            for(column_sub_matrix = column - 1; column_sub_matrix < column + (kernel_line - 1); column_sub_matrix++){
                count_column = 0;
                for(line_sub_matrix = line - 1; line_sub_matrix < line + (kernel_column - 1); line_sub_matrix++){
                    sum_of_products += image[column_sub_matrix][line_sub_matrix] * kernel[count_line][count_column];
                    count_column++;
                }
                count_line++;
            }
        convolutional[column - 1][line - 1] = (int)sum_of_products;
        }
    }

    // save convolutional image
    FILE* convolutional_image = fopen("convolutional.ascii.pgm", "w");

    fprintf(convolutional_image, "P2\n");
    fprintf(convolutional_image, "%d %d \n", convolutional_line, convolutional_column);
    fprintf(convolutional_image, "%d \n", maxValue);

    for(column = 0; column < convolutional_column; column++){
        for(line = 0; line < convolutional_line; line++){
            if(convolutional[line][column] < 0){
                fprintf(convolutional_image, "%d ", 0);
            } else if(convolutional[line][column] > maxValue){
                fprintf(convolutional_image, "%d ", maxValue);
            } else{
                fprintf(convolutional_image, "%d ", convolutional[line][column]);
            }

        }
        fprintf(convolutional_image, "\n");
    }
    fclose(convolutional_image);
    return 0;
}