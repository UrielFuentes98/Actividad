#define ONE 0x3F
#define TWO 0x06
#define THREE 0x5B
#define FOUR 0x4F
#define FIVE 0x6D
#define SIX 0x7D
#define SEVEN 0x07
#define EIGHT 0x7F
#define NINE 0x6F
#define l_A 0x77
#define l_B 0x7C
#define 1_C 0x39 
#define l_D 0x5E
#define l_E 0x79
#define l_F 
 
void disp(uint32_t base, uint8_t datoDisp) {
	
	uint8_t segment_vals[] = {ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
							  EIGHT, NINE, l_A, l_B, l_C, l_D , l_E, l_F};
	
	uint8_t aux, high_N, low_N, dataOut;
	const uint8_t MASK_N = 0xB;
	
    high_N = datoDisp / 16;
    low_N = datoDisp % 16;
     
	//Cargar el nibble menos significativo

	dataOut = segment_vals[high_N];

    for(uint8_t bit = 0, aux = 0; bit < 8; bit++){
        aux = in(base) ^ MASK_N;
        output = aux & 0xFE;
        out(base+2, output ^ MASK_N);
        sleep(100);
        out(base, dataOut)
        dataOut = dataOut >> 1;
        sleep(100)
        output = aux|0x1;
        out(base+2, output ^ MASK_N);
    }
	
    //Cargar el nibble mas significativo

	dataOut = segment_vals[low_N];

    for(uint8_t bit = 0, aux = 0; bit < 8; bit++){
        aux = in(base) ^ MASK_N;
        output = aux & 0xFE;
        out(base+2, output ^ MASK_N);
        sleep(100);
        out(base, dataOut)
        dataOut = dataOut >> 1;
        sleep(100)
        output = aux|0x1;
        out(base+2, output ^ MASK_N);
    }
    
	//Habilitar la salida de los datos en paralelo
	
	aux = in(base) ^ MASK_N;
	output = aux & 0xFD;
	out(base+2, output ^ MASK_N);
	sleep(100);
	out(base, dato)
	sleep(100)
	output = aux|0x2;
	out(base+2, output ^ MASK_N);
}