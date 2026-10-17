#include <ti/screen.h>
#include <ti/getcsc.h>
#include <ti/real.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
static int quadratics(void);
static int cubics(void);
static double newton(double a, double b, double c, double d);
static char* getNumericInput(unsigned int size);

int main(void) {

    uint8_t key;
    uint8_t name = 1;

    restart:

    os_ClrHome();
    if (name == 1) os_PutStrFull("(C) TI-PI-Plus-C 2026");
    else if (name == 0) os_PutStrFull("(C) N. J. McKibben 2026");
    os_NewLine();
    os_PutStrFull("Polynomial Roots v1.2.0:");
    os_NewLine();

    //select menu
    os_PutStrFull("1. Quadratics");
    os_NewLine();
    os_PutStrFull("2. Cubics");
    os_NewLine();
    os_PutStrFull("3. Exit");

    while (1) {
    
        key = os_GetCSC();
        
        if (key == sk_1) {

            quadratics();        
            break;
        
        }
        else if (key == sk_2) {
        
            cubics();
            break;
        
        }
        else if (key == sk_3) {
        
            return 0;

        }
        else if (key == sk_7) {

            name = 0;

        }
    }

    //wait for user input
    while (1) {
    
        key = os_GetCSC();
        if (key == sk_2nd) goto restart;
        else if (key == sk_Clear) break;

    }
    
    return 0;

}

//function to find roots of a quadratic equation
static int quadratics(void) {

    //variables
    char* buff;
    real_t ra, rb, rc, rr1, rr2;
    double a, b, c, r1, r2;

    //get all variables
    os_ClrHome();
    os_PutStrFull("Quadratics (AX^2+BX+C)");
    os_NewLine();
    os_PutStrFull("A= ");
    buff = getNumericInput(20);
    ra = os_StrToReal(buff, NULL);
    free(buff);
    a = os_RealToFloat(&ra);
    os_NewLine();
    os_PutStrFull("B= ");
    buff = getNumericInput(20);
    rb = os_StrToReal(buff, NULL);
    free(buff);
    b = os_RealToFloat(&rb);
    os_NewLine();
    os_PutStrFull("C= ");
    buff = getNumericInput(20);
    rc = os_StrToReal(buff, NULL);
    free(buff);
    c = os_RealToFloat(&rc);
    os_NewLine();

    //quadratic formula
    r1 = ((-1 * b) - sqrt((b*b) - (4 * a * c))) / (2 * a);
    r2 = ((-1 * b) + sqrt((b*b) - (4 * a * c))) / (2 * a);

    //print results
    os_NewLine();
    if (((b * b) - (4 * (a * c))) >= 0) {

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
        r2 = -1 * ((b * b) - (4 * (a * c)));
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
    
    return 0;

}

static int cubics(void) {

    char* buff;
    real_t ra, rb, rc, rd, rr1, rr2, rr3;
    double a, b, c, d, r1, r2, r3;
    
    //Get variables
    os_ClrHome();
    os_PutStrFull("Cubics (AX^3+BX^2+CX+D)");
    os_NewLine();
    os_PutStrFull("A= ");
    buff = getNumericInput(20);
    ra = os_StrToReal(buff, NULL);
    free(buff);
    a = os_RealToFloat(&ra);
    os_NewLine();
    os_PutStrFull("B= ");
    buff = getNumericInput(20);
    rb = os_StrToReal(buff, NULL);
    b = os_RealToFloat(&rb);
    os_NewLine();
    os_PutStrFull("C= ");
    buff = getNumericInput(20);
    rc = os_StrToReal(buff, NULL);
    c = os_RealToFloat(&rc);
    os_NewLine();
    os_PutStrFull("D= ");
    buff = getNumericInput(20);
    rd = os_StrToReal(buff, NULL);
    d = os_RealToFloat(&rd);

    //calculate one real root
    r1 = newton(a, b, c, d);
    rr1 = os_FloatToReal(r1);
    memset(buff, 0, 20);
    os_NewLine();
    os_RealToStr(buff, &rr1, 8, 0, 9);
    os_PutStrFull("X= ");
    os_PutStrFull(buff);

    //divide synthetically
    b += (a * r1);
    c += (b * r1);

    //quadratic formula
    r2 = ((-1 * b) - sqrt((b * b) - (4 * a * c))) / (2 * a);
    r3 = ((-1 * b) + sqrt((b * b) - (4 * a * c))) / (2 * a);

    //print results
    os_NewLine();
    if (((b * b) - (4 * (a * c))) >= 0) {

        rr2 = os_FloatToReal(r2);
        rr3 = os_FloatToReal(r3);
        memset(buff, 0, 20);
        os_RealToStr(buff, &rr2, 8, 0, 9);
        os_PutStrFull("X= ");
        os_PutStrFull(buff);
        os_NewLine();
        memset(buff, 0, 20);
        os_RealToStr(buff, &rr3, 8, 0, 9);
        os_PutStrFull("X= ");
        os_PutStrFull(buff);

    } else {

        r2 = (-1 * b) / (2 * a);
        r3 = -1 * ((b * b) - (4 * (a * c)));
        r3 = sqrt(r2) / (2 * a);
        rr2 = os_FloatToReal(r2);
        rr3 = os_FloatToReal(r3);
        memset(buff, 0, 20);
        os_RealToStr(buff, &rr2, 8, 0, 9);
        os_PutStrFull(buff);
        os_PutStrFull(" +/- ");
        memset(buff, 0, 20);
        os_RealToStr(buff, &rr3, 8, 0, 9);
        os_PutStrFull(buff);
        os_PutStrFull("i");

    }

    return 0;

}

//function to get input from user
static char* getNumericInput(unsigned int size) {

  char* buffer = (char*)calloc(size, sizeof(char));
  unsigned int i = 0;
  uint8_t key;
  unsigned int r, c;

  os_EnableCursor();

  if (!buffer) exit(1);

  while (i < size) {

    key = os_GetCSC();

    switch (key) {

      case sk_0:

        buffer[i] = '0';
        os_PutStrFull("0");
        break;

      case sk_1:
        buffer[i] = '1';
        os_PutStrFull("1");
        break;

      case sk_2:

        buffer[i] = '2';
        os_PutStrFull("2");
        break;

      case sk_3:

        buffer[i] = '3';
        os_PutStrFull("3");
        break;

      case sk_4:

        buffer[i] = '4';
        os_PutStrFull("4");
        break;

      case sk_5:

        buffer[i] = '5';
        os_PutStrFull("5");
        break;

      case sk_6:

        buffer[i] = '6';
        os_PutStrFull("6");
        break;

      case sk_7:

        buffer[i] = '7';
        os_PutStrFull("7");
        break;

      case sk_8:

        buffer[i] = '8';
        os_PutStrFull("8");
        break;

      case sk_9:

        buffer[i] = '9';
        os_PutStrFull("9");
        break;

      case sk_Del:

        if (i == 0) continue;
        buffer[i--] = ' ';
        os_GetCursorPos(&r, &c);
        if (c == 0) continue;
        os_PutStrFull(" ");
        os_SetCursorPos(r, (c - 1));
        continue;
       
       case sk_Chs:
        buffer[i] = '-';
        os_PutStrFull("-");
        break;
        
       case sk_DecPnt:
        buffer[i] = '.';
        os_PutStrFull(".");
        break;

      case sk_Enter:

        i = size;
        continue;
        break;

      default:

        continue;

    }

    i++;

  }

  os_DisableCursor();

  return buffer;

}

//function to find one real root using newton's method
static double newton(double a, double b, double c, double d) {

   double guess = 1;
   
   for (unsigned int i = 0; i < 50; i++) {
   
      guess = guess - (guess * (guess * (a * guess + b) + c) + d) / (guess * (3* a * guess + 2 * b) + c);

   }

   return guess;

}