// Aluno: Luan Francisco Gibson Coutinho matricula: 2411167
// Aluno: Pedro Pitta Paulino            matricula: 2410242


#define NUM_BITS 128
typedef unsigned char BigInt[NUM_BITS/8];

#include <stdio.h>
#include "bigint.h"

void dump(BigInt a) {
    printf("0x");
    // percorre do byte mais significativo (a[15]) até o menos significativo (a[0])
    for (int i = NUM_BITS/8 - 1; i >= 0; i--) {
        printf("%02X", a[i]);
    }
    printf("\n");
}





int main(void) {
    BigInt res; // declare apenas uma vez

    long a = 0xFFFFFFFFFFFFFFFF;
    long b = 0x0;
    long c = 0xFFFF;

    printf("Atribuição de valor \n");
    // Teste 1
    for (int i = 0; i < 16; i++) res[i] = 0;  // zera o BigInt
    big_val(res, a);
    dump(res);
    printf("\n");

    // Teste 2
    for (int i = 0; i < 16; i++) res[i] = 0;
    big_val(res, b);
    dump(res);
    printf("\n");

    // Teste 3
    for (int i = 0; i < 16; i++) res[i] = 0;
    big_val(res, c);
    dump(res);
    printf("\n");



    

    /* Operacoes aritmeticas */

    
    BigInt temp;
    BigInt temp2;



/* res = -a */
printf("Inversão de Valor \n");
    //Teste1
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    big_val(temp, a);
    dump(temp);

    big_comp2( res, temp);
    dump(res);
    printf("\n");


    //Teste 2

   
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    big_val(temp, b);
    dump(temp);

    big_comp2( res, temp);
    dump(res);

     printf("\n");

     //Teste 3
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    big_val(temp, c);
    dump(temp);

    big_comp2( res, temp);
    dump(res);

    printf("\n");




    /* res = a + b */

    printf("Soma\n");

    // Caso limite superior
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    for (int i = 0; i < 16; i++) temp2[i] = 0;
    big_val(temp, a);
    dump(temp);

    big_val(temp2, a);
    dump(temp2);

    big_sum (res, temp, temp2);
    dump(res);
    printf("\n");

 // Caso 0
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    for (int i = 0; i < 16; i++) temp2[i] = 0;
    big_val(temp, b);
    dump(temp);

    big_val(temp2, b);
    dump(temp2);

    big_sum (res, temp, temp2);
    dump(res);
    printf("\n");

 // Caso Normal
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    for (int i = 0; i < 16; i++) temp2[i] = 0;
    big_val(temp, a);
    dump(temp);

    big_val(temp2, b);
    dump(temp2);

    big_sum (res, temp, temp2);
    dump(res);
    printf("\n");


    /* res = a - b */

    printf("Subtração\n");

    // Caso limite superior
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    for (int i = 0; i < 16; i++) temp2[i] = 0;
    big_val(temp, a);
    dump(temp);

    big_val(temp2, a);
    dump(temp2);

    big_sub (res, temp, temp2);
    dump(res);
    printf("\n");

 // Caso 0
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    for (int i = 0; i < 16; i++) temp2[i] = 0;
    big_val(temp, b);
    dump(temp);

    big_val(temp2, b);
    dump(temp2);

    big_sub (res, temp, temp2);
    dump(res);
    printf("\n");

 // Caso Normal
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    for (int i = 0; i < 16; i++) temp2[i] = 0;
    big_val(temp, a);
    dump(temp);

    big_val(temp2, b);
    dump(temp2);

    big_sub (res, temp, temp2);
    dump(res);
    printf("\n");
   

    /* res = a * b */

    printf("Multiplicação\n");

    // Caso limite superior
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    for (int i = 0; i < 16; i++) temp2[i] = 0;
    big_val(temp, a);
    dump(temp);

    big_val(temp2, a);
    dump(temp2);

    big_mul (res, temp, temp2);
    dump(res);
    printf("\n");

 // Caso 0
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    for (int i = 0; i < 16; i++) temp2[i] = 0;
    big_val(temp, b);
    dump(temp);

    big_val(temp2, b);
    dump(temp2);

    big_mul (res, temp, temp2);
    dump(res);
    printf("\n");

 // Caso Normal
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    for (int i = 0; i < 16; i++) temp2[i] = 0;
    big_val(temp, a);
    dump(temp);

    big_val(temp2, b);
    dump(temp2);

    big_mul (res, temp, temp2);
    dump(res);
    printf("\n");



    

    /* Operacoes de deslocamento */

    int x= 128;
    int y= 0;
    int z= 8;

    /* res = a << n */

    printf("Bitshift <<\n");

    // Caso limite superior
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    x= 128;
    big_val(temp, a);
    dump(temp);

    big_shl (res, temp, x);
    dump(res);
    printf("\n");

 // Caso 0
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    y= 0;
    big_val(temp, a);
    dump(temp);


    big_shl (res, temp, y);
    dump(res);
    printf("\n");

 // Caso Normal
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    z= 8;
    big_val(temp, a);
    dump(temp);

    big_shl (res, temp, z);
    dump(res);
    printf("\n");


    // /* res = a >> n (logico) */

    printf("Bitshift >> Logica \n");

    // Caso limite superior
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    x= 128;
    big_val(temp, a);
    dump(temp);

    big_shr (res, temp, x);
    dump(res);
    printf("\n");

 // Caso 0
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    y= 0;
    big_val(temp, a);
    dump(temp);


    big_shr (res, temp, y);
    dump(res);
    printf("\n");

 // Caso Normal
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    z= 8;
    big_val(temp, a);
    dump(temp);

    big_shr (res, temp, z);
    dump(res);
    printf("\n");

   

    // /* res = a >> n (aritmetico) */

    printf("Bitshift >> Aritmeca \n");

    // Caso limite superior
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    x= 128;
    big_val(temp, a);
    dump(temp);

    big_sar (res, temp, x);
    dump(res);
    printf("\n");

 // Caso 0
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    y= 0;
    big_val(temp, a);
    dump(temp);


    big_sar (res, temp, y);
    dump(res);
    printf("\n");

 // Caso Normal
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    z= 8;
    big_val(temp, a);
    dump(temp);

    big_sar (res, temp, z);
    dump(res);
    printf("\n");

 // Caso Positivo
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    z= 8;
    big_val(temp, 1);
    dump(temp);

    big_sar (res, temp, z);
    dump(res);
    printf("\n");

     // Caso Negativo
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    z= 8;
    big_val(temp, -1);
    dump(temp);

    big_sar (res, temp, z);
    dump(res);
    printf("\n");


     // Caso Positivo
    for (int i = 0; i < 16; i++) res[i] = 0;
    for (int i = 0; i < 16; i++) temp[i] = 0;
    z= 128;
    big_val(temp, 1);
    dump(temp);

    big_sar (res, temp, z);
    dump(res);
    printf("\n");

    return 0;
 }