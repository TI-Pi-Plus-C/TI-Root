#include <ti/screen.h>
#include <ti/getcsc.h>
#include <ti/real.h>
#include <math.h>
#include <string.h>

char* GetNumInput(char* prompt, char* ret, int size);

int main(void) {

    //variables
    char buff[20];
    real_t ra;
    real_t rb;
    real_t rc;
    real_t rr1;
    real_t rr2;
    double a;
    double b;
    double c;
    double r1;
    double r2;
    uint8_t key;

    restart:

    os_ClrHome();

    //get all variables
    os_PutStrFull("(C) TI-PI-Plus-C 2026");
    os_NewLine();
    os_PutStrFull("Quadratic Equation Solver:");
    os_NewLine();
    memset(buff, 0, 20);
    GetNumInput("A= ", buff, 20);
    ra = os_StrToReal(buff, NULL);
    a = os_RealToFloat(&ra);
    os_NewLine();
    memset(buff, 0, 20);
    GetNumInput("B= ", buff, 20);
    rb = os_StrToReal(buff, NULL);
    b = os_RealToFloat(&rb);
    os_NewLine();
    memset(buff, 0, 20);
    GetNumInput("C= ", buff, 20);
    rc = os_StrToReal(buff, NULL);
    c = os_RealToFloat(&rc);
    os_NewLine();

    //quadratic formula
    r1 = ((-1 * b) - sqrt((b*b) - (4 * a * c))) / (2 * a);
    r2 = ((-1 * b) + sqrt((b*b) - (4 * a * c))) / (2 * a);

    //print results
    os_NewLine();
    if (((b*b) - (4 * (a * c))) >= 0) {

        rr1 = os_FloatToReal(r1);
        rr2 = os_FloatToReal(r2);
        memset(buff, 0, 20);
        os_RealToStr(buff, &rr1, 8, 0, 9);
        os_PutStrFull("X= ");
        os_PutStrFull(buff);
        os_NewLine();
        memset(buff, 0, 20);
        os_RealToStr(buff, &rr2, 8, 0, 9);
        os_PutStrFull("X= ");
        os_PutStrFull(buff);

    } else {

        r1 = (-1 * b) / (2 * a);
        r2 = -1 * ((b*b) - (4 * (a * c)));
        r2 = sqrt(r2) / (2 * a);
        rr1 = os_FloatToReal(r1);
        rr2 = os_FloatToReal(r2);
        memset(buff, 0, 20);
        os_RealToStr(buff, &rr1, 8, 0, 9);
        os_PutStrFull(buff);
        os_PutStrFull(" +/- ");
        memset(buff, 0, 20);
        os_RealToStr(buff, &rr2, 8, 0, 9);
        os_PutStrFull(buff);
        os_PutStrFull("i");

    }

    //wait for user input
    while (1) {
    
        key = os_GetCSC();
        if (key == sk_2nd) goto restart;
        else if (key == sk_Clear) break;

    }

    return 0;

}

char* GetNumInput(char* prompt, char* ret, int size) {

    os_PutStrFull(prompt);
    uint8_t key;
    int i = 0;

    while ((key = os_GetCSC()) != sk_Enter) {

        if (i > size) continue;

        switch (key) {

            case sk_0:
                ret[i] = '0';
                os_PutStrFull("0");
                break;

            case sk_1:
                ret[i] = '1';
                os_PutStrFull("1");
                break;

            case sk_2:
                ret[i] = '2';
                os_PutStrFull("2");
                break;

            case sk_3:
                ret[i] = '3';
                os_PutStrFull("3");
                break;

            case sk_4:
                ret[i] = '4';
                os_PutStrFull("4");
                break;

            case sk_5:
                ret[i] = '5';
                os_PutStrFull("5");
                break;

            case sk_6:
                ret[i] = '6';
                os_PutStrFull("6");
                break;

            case sk_7:
                ret[i] = '7';
                os_PutStrFull("7");
                break;

            case sk_8:
                ret[i] = '8';
                os_PutStrFull("8");
                break;

            case sk_9:
                ret[i] = '9';
                os_PutStrFull("9");
                break;

            case sk_DecPnt:
                ret[i] = '.';
                os_PutStrFull(".");
                break;
            
            case sk_Chs:
                ret[i] = '-';
                os_PutStrFull("-");
                break;
            
            default:
                continue;

        }

        i++;
    }

    return ret;

}