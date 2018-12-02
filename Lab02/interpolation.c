#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Linear interpolation for voltage\n");

    float t1, t2, t3, t4; //temperature
    float v1, v2, v3, v4; //voltage
    float avet; //average for t
    float avev; //average for v
    float cov; //cov(t,v)
    float coeff_ang;
    float intercept;
    float dev_a;
    float voltage, temperature;
    //must use cov(AB) and averages to calculate interpolation
    t1 = 0;
    t2 = 15;
    t3 = 27;
    t4 = 35;
    v1 = 0;
    v2 = 20;
    v3 = 55;
    v4 = 100;

    avet = (t1 + t2 + t3 + t4) / 4.0;
    avev = (v1 + v2 + v3 + v4) / 4.0;
    cov = ((t1 - avet) * (t2 - avet) * (t3 - avet) * (t4 - avet) * (v1 - avev) * (v2 - avev) * (v3 - avev) * (v4 - avev)) / (4.0);
    dev_a = ((t1 - avet)*(t1 - avet) + (t2 - avet)*(t2 - avet) + (t3 - avet)*(t3 - avet) + (t4 - avet)*(t4 - avet)) / (4.0);
    coeff_ang = cov / (dev_a * dev_a);
    intercept = avev - coeff_ang * avet;
    //write the inverse formula and then have to receive input
    intercept = - intercept / coeff_ang;
    coeff_ang = 1.0 / coeff_ang;
    //get input and give output: almost done!
    printf("Give me the voltage you have");
    scanf("%g", &voltage);
    temperature = coeff_ang * voltage + intercept;
    printf("The temperature is: %g", temperature);
    return 0;
}
