#include <ti/screen.h>
#include <ti/getcsc.h>
#include <ti/real.h>
#include <math.h>
#include <string.h>

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
    char* end;
    uint8_t key;

    start:
    os_ClrHome();

    //get all variables
    os_PutStrFull("(C) TI-PI-Plus-C 2026");
    os_NewLine();
    os_PutStrFull("Quadratic Equation Solver:");
    os_NewLine();
    os_GetStringInput("A= ", buff, 20);
    ra = os_StrToReal(buff, &end);
    a = os_RealToFloat(&ra);
    os_NewLine();
    os_GetStringInput("B= ", buff, 20);
    rb = os_StrToReal(buff, &end);
    b = os_RealToFloat(&rb);
    os_NewLine();
    os_GetStringInput("C= ", buff, 20);
    rc = os_StrToReal(buff, &end);
    c = os_RealToFloat(&rc);
    os_NewLine();

    //quadratic formula
    r1 = ((-1 * b) - sqrt((b*b) - (4 * a * c))) / (2 * a);
    r2 = ((-1 * b) + sqrt((b*b) - (4 * a * c))) / (2 * a);

    //print results
    os_NewLine();
    if (((b*b) -4 * (a * c)) >= 0) {

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

        os_PutStrFull("Roots are imaginary.");

    }

    //wait for user input
    while (1) {
    
        key = os_GetCSC();
        if (key == sk_2nd) goto start;
        else if (key == sk_Clear) break;

    }

    return 0;

}