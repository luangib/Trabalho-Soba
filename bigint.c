void big_val(BigInt res, long val) {
    unsigned char *p = (unsigned char *)&val;

    // Copia os bytes do long para res (já em little endian)
    for (int i = 0; i < sizeof(long); i++) {
        res[i] = p[i];
    }

    // Extensão de sinal
    unsigned char fill = (val < 0) ? 0xFF : 0x00;
    for (int i = sizeof(long); i < NUM_BITS/8; i++) {
        res[i] = fill;
    }
}

/* res = -a */

void big_comp2(BigInt res, BigInt a) {
    // 1. Inverte todos os bits
    for (int i = 0; i < NUM_BITS/8; i++) {
        res[i] = ~a[i];
    }

    // 2. Soma 1 (com propagação de carry)
    unsigned carry = 1;
    for (int i = 0; i < NUM_BITS/8; i++) {
        unsigned sum = res[i] + carry;
        res[i] = (unsigned char)(sum & 0xFF);
        carry   = (sum >> 8) & 0x01;
        if (!carry) break; // se não teve overflow, para
    }
}


/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b) {
    unsigned carry = 0;


    for (int i = 0; i < 16; i++) {
        // soma os bytes correspondentes de a e b + carry
        unsigned sum = a[i] + b[i] + carry;

        // armazena apenas os 8 bits menos significativos
        res[i] = (unsigned char)(sum & 0xFF);

        // o carry é o que “transbordou” para o próximo byte
        carry = (sum >> 8) & 0xFF;
    }
}

void big_sub(BigInt res, BigInt a, BigInt b) {

    BigInt neg_b;

    // neg_b = complemento de 2 de b
    big_comp2(neg_b, b);

    // res = a + neg_b
    big_sum(res, a, neg_b);
}


void big_mul(BigInt res, BigInt a, BigInt b) {
    unsigned int temp[32] = {0}; // até 256 bits temporários (32 bytes)

    // Multiplicação byte a byte
    for (int i = 0; i < 16; i++) {
        unsigned carry = 0;
        for (int j = 0; j < 16; j++) {
            unsigned sum = temp[i + j] + a[i] * b[j] + carry;

            temp[i + j] = sum & 0xFF;   // guarda o byte atual
            carry       = sum >> 8;     // o que transbordou
        }
        temp[i + 16] += carry; // resto do carry
    }

    // Copia só os 16 bytes menos significativos (128 bits)
    for (int i = 0; i < 16; i++) {
        res[i] = (unsigned char)(temp[i] & 0xFF);
    }
}

void big_shl(BigInt res, BigInt a, int n) {
    // zera o resultado
    for (int i = 0; i < 16; i++) res[i] = 0;

    int byteShift = n / 8;   // quantos bytes andar
    int bitShift  = n % 8;   // quantos bits andar dentro do byte

    for (int i = 15; i >= 0; i--) {
        // pega o byte de a que vai "cair" na posição nova
        int j = i - byteShift;
        if (j < 0) continue; // já passou do limite inferior

        unsigned int val = a[j] << bitShift;

        // parte baixa vai para res[i]
        res[i] |= (unsigned char)(val & 0xFF);

        // parte alta (carry de bits deslocados) vai para o próximo byte
        if (i > 0) {
            res[i - 1] |= (unsigned char)((val >> 8) & 0xFF);
        }
    }
}


void big_shr(BigInt res, BigInt a, int n) {
    // zera o resultado
    for (int i = 0; i < 16; i++) res[i] = 0;

    int byteShift = n / 8;  // quantos bytes andar
    int bitShift  = n % 8;  // quantos bits andar dentro do byte

    for (int i = 0; i < 16; i++) {
        int j = i + byteShift;
        if (j >= 16) break;  // passou do limite do BigInt

        unsigned int val = a[j] >> bitShift;

        // guarda parte baixa
        res[i] |= (unsigned char)(val & 0xFF);

        // agora, se bitShift > 0, pega os bits "roubados" do próximo byte
        if (j + 1 < 16 && bitShift > 0) {
            unsigned int carry = (a[j + 1] & ((1 << bitShift) - 1)) << (8 - bitShift);
            res[i] |= (unsigned char)(carry & 0xFF);
        }
    }
}


void big_sar(BigInt res, BigInt a, int n) {
    // zera o resultado
    for (int i = 0; i < 16; i++) res[i] = 0;

    int byteShift = n / 8;  // quantos bytes andar
    int bitShift  = n % 8;  // quantos bits andar dentro do byte

    // bit de sinal vem do MSB (byte 15, bit 7)
    unsigned char sign = (a[15] & 0x80) ? 0xFF : 0x00;

    for (int i = 0; i < 16; i++) {
        int j = i + byteShift;
        if (j >= 16) {
            res[i] = sign;  // já saiu fora, só preenche com sinal
            continue;
        }

        unsigned int val = a[j] >> bitShift;

        // guarda parte baixa
        res[i] |= (unsigned char)(val & 0xFF);

        // agora, se bitShift > 0, pega os bits que vêm do próximo byte
        if (j + 1 < 16 && bitShift > 0) {
            unsigned int carry = (a[j + 1] & ((1 << bitShift) - 1)) << (8 - bitShift);
            res[i] |= (unsigned char)(carry & 0xFF);
        }
    }

    // Preenche os bytes mais altos com o bit de sinal
    if (sign == 0xFF) {
        for (int i = 15; i >= 16 - byteShift; i--) {
            res[i] = 0xFF;
        }

        if (bitShift > 0) {
            // completa os bits superiores com 1 no último byte
            res[15] |= ((0xFF << (8 - bitShift)) & 0xFF);
        }
    }
}
