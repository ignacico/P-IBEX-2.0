
#include "simple_system_common.h"




// 2 sumas 2 div 3 mult 4 sumas

int main(int argc, char **argv) {
  DEV_WRITE(POSIT_SINGLE_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_SINGLE_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_SINGLE_OUTPUT, 0x00000001);
  puthex(DEV_READ(POSIT_SINGLE_OUTPUT, 0));
  puts("\n");

  return 0;
}

/*
  DEV_WRITE(POSIT_SINGLE_OP_A, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OP_B, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OUTPUT, 0x00000001);
  puthex(DEV_READ(POSIT_SINGLE_OUTPUT, 0));
  puts("\n");

  DEV_WRITE(POSIT_SINGLE_OP_A, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OP_B, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OUTPUT, 0x00000001);
  puthex(DEV_READ(POSIT_SINGLE_OUTPUT, 0));
  puts("\n");

  puts("\n");

  DEV_WRITE(POSIT_SINGLE_OP_A, 0x41000000);
  DEV_WRITE(POSIT_SINGLE_OP_B, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OUTPUT, 0x00000003);
  puthex(DEV_READ(POSIT_SINGLE_OUTPUT, 0));
  puts("\n");
  DEV_WRITE(POSIT_SINGLE_OP_A, 0x41800000);
  DEV_WRITE(POSIT_SINGLE_OP_B, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OUTPUT, 0x00000003);
  puthex(DEV_READ(POSIT_SINGLE_OUTPUT, 0));
  puts("\n");

  puts("\n");

  DEV_WRITE(POSIT_SINGLE_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_SINGLE_OP_B, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OUTPUT, 0x00000002);
  puthex(DEV_READ(POSIT_SINGLE_OUTPUT, 0));
  puts("\n");
  DEV_WRITE(POSIT_SINGLE_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_SINGLE_OP_B, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OUTPUT, 0x00000002);
  puthex(DEV_READ(POSIT_SINGLE_OUTPUT, 0));
  puts("\n");
  DEV_WRITE(POSIT_SINGLE_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_SINGLE_OP_B, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OUTPUT, 0x00000002);
  puthex(DEV_READ(POSIT_SINGLE_OUTPUT, 0));
  puts("\n");

  puts("\n");

  DEV_WRITE(POSIT_SINGLE_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_SINGLE_OP_B, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OUTPUT, 0x00000001);
  puthex(DEV_READ(POSIT_SINGLE_OUTPUT, 0));
  puts("\n");
  DEV_WRITE(POSIT_SINGLE_OP_A, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OP_B, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OUTPUT, 0x00000001);
  puthex(DEV_READ(POSIT_SINGLE_OUTPUT, 0));
  puts("\n");
  DEV_WRITE(POSIT_SINGLE_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_SINGLE_OP_B, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OUTPUT, 0x00000001);
  puthex(DEV_READ(POSIT_SINGLE_OUTPUT, 0));
  puts("\n");
  DEV_WRITE(POSIT_SINGLE_OP_A, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OP_B, 0x40800000);
  DEV_WRITE(POSIT_SINGLE_OUTPUT, 0x00000001);
  puthex(DEV_READ(POSIT_SINGLE_OUTPUT, 0));
  puts("\n");
*/

/*
 /home/ignacio/Escritorio/simple_unit/posit_coprocessor/sw/posit_cooprocessor_test
  DEV_WRITE(dira, 0x00000000);
  DEV_WRITE(dirb, 0x00000000);
  DEV_WRITE(diro, 0x2);
  puthex(DEV_READ(diro, 0));
  puts("\n");

  DEV_WRITE(dira, 0x00000000);
  DEV_WRITE(dirb, 0x00000000);
  DEV_WRITE(diro, 0x3);
  puthex(DEV_READ(diro, 0));
  puts("\n");
  DEV_WRITE(dira, 0x00000000);
  DEV_WRITE(dirb, 0x00000000);
  DEV_WRITE(diro, 0x3);
  puthex(DEV_READ(diro, 0));
  puts("\n");
  
  DEV_WRITE(dira, 0x00000000);
  DEV_WRITE(dirb, 0x00000000);
  DEV_WRITE(diro, 0x2);
  puthex(DEV_READ(diro, 0));
  puts("\n");
  DEV_WRITE(dira, 0x00000000);
  DEV_WRITE(dirb, 0x00000000);
  DEV_WRITE(diro, 0x1);
  puthex(DEV_READ(diro, 0));
  puts("\n");

*/