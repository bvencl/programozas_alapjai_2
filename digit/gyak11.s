//fordítsuk le az alábbi C programrészletet!
//int16_t a,b,c,d;
//...
// a = b + (c>>4) -d;



.bss
a: .space 2
b: .space 2
c: .space 2
d: .space 2

.text

mov b, w1
mov c, w2
mov d, w3

asr w2, #4, w2
add w1, w2, w0
sub w0, w3, w0
mov w0, a
