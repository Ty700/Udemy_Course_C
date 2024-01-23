#include <stdio.h>
#include <stdarg.h>
#include <math.h>

// double average(double num1, double num2, ...);
double sample_stddev(int count, ...);

int main(void){
//     double num1 = 10.5, num2 = 2.5;
//     int num3 = 6, num4 = 5;
//     float num5 = 12L, num6 = 20L;

//     printf("Average = %.2lf\n", average(num1, 3.5, num2, 4.5, 5.0, 0.0));
//     printf("Average = %.2lf\n", average(1.0, 2.0, 3.0, 0.0));
//     printf("Average = %.2lf\n", average((double)(num4), num2, (double)(num3), (double)(num5), (double)(num6), 0.0));

    printf("%f\n", sample_stddev(4, 25.0, 27.3, 26.9, 25.7));

}

double sample_stddev(int count, ...){
    double sum = 0;

    va_list p_arg, p_argCopy;

    va_start(p_arg, count);   
    va_copy(p_argCopy, p_arg);

    //Going through p_arg list and adding them
    for(int i = 0; i < count; i++){
        sum += va_arg(p_arg, double);
    }
    //Clean up
    va_end(p_arg);

    //Using sum calculated by first pass to calculate meean
    double mean = sum/count;

    double sum_sq_diff = 0;

    //Second pass through is required to calculate stddev, thus we need a copy of the arg list
    //Hence the use of va_copy
    for(int i = 0; i < count; i++){
        double num = va_arg(p_argCopy, double);
        sum_sq_diff = (num - mean) * (num - mean);
    }

    va_end(p_argCopy);

    return (double)(sqrt(sum_sq_diff/ count));
    
}

//Assuming all args are of type double and not 0
// double average(double num1, double num2, ...){
//     va_list p_arg;
//     double sum = num1 + num2;
//     double value = 0.0;

//     int count = 2;
//     va_start(p_arg, num2);

//     while((value = va_arg(p_arg, double)) != 0.0){
//         sum += value;
//         // printf("%lf\n", sum);
//         ++count;
//     }

//     va_end(p_arg);

//     return sum/count;
// }

