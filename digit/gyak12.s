// int16_t tomb [100]
//int32_t osszeg;
//...
//osszeg = 0
//for(uint8_t=0;i<100;i++)
//  osszeg = osszeg + tomb[i]; 

.bss
    tomb: .space 200
    osszeg: .space 4

.text

//osszeg a w1 w0 regiszterben, w1 msb
//kiolvasom a memoriabol a tomb i-edik elemet, majf felbovitem 32 bitre es igy adom ossze --> w5, w4, w5 msb

/* tomb i-edik eleme?
tomb + (i * 2) --> "kétkomponensű címzés (eltolással)"
*/

mov #tomb, w2; tomb kezdet
clr w0
clr w1
clr w3

ciklus:
    sl w3, #1, w4; w4 = i * 2
    mov [w2 + w4], w4; w4 = tomb[i]
