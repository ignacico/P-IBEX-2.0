// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#include "simple_system_common.h"

void calculate(){ // ~ calculate256
  uint32_t resultBuffer[256];

  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000003);
  
  for(int i = 0; i<256; i++){
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  }
  for(int i = 0; i<256; i++){
    resultBuffer[i] = DEV_READ(POSIT_COOPROC_DIV, 0);
  }  
}

void add64(){
  uint32_t resultBuffer[64];

  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000001);
  
  for(int i = 0; i<64; i++){
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  }
  for(int i = 0; i<64; i++){
    resultBuffer[i] = DEV_READ(POSIT_COOPROC_ADD, 0);
  }  
}
void mult64(){
  uint32_t resultBuffer[64];

  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000002);
  
  for(int i = 0; i<64; i++){
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  }
  for(int i = 0; i<64; i++){
    resultBuffer[i] = DEV_READ(POSIT_COOPROC_MUL, 0);
  }  
}
void div64(){
  uint32_t resultBuffer[64];

  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000003);
  
  for(int i = 0; i<64; i++){
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  }
  for(int i = 0; i<64; i++){
    resultBuffer[i] = DEV_READ(POSIT_COOPROC_DIV, 0);
  }  
}

void calculate1024(){
  for(int j = 0; j<4; j++){
    uint32_t resultBuffer[256];

    DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000001);
    // DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000003);
    
    for(int i = 0; i<256; i++){
      DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
      DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    }
    for(int i = 0; i<256; i++){
      resultBuffer[i] = DEV_READ(POSIT_COOPROC_ADD, 0);
      //resultBuffer[i] = DEV_READ(POSIT_COOPROC_DIV, 0);
    }  
  }
}

void addN(int n){
  uint32_t resultBuffer[n];

  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000001);
  
  for(int i = 0; i<n; i++){
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  }
  for(int i = 0; i<n; i++){
    resultBuffer[i] = DEV_READ(POSIT_COOPROC_ADD, 0);
  }  
}
void multN(int n){
  uint32_t resultBuffer[n];

  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000002);
  
  for(int i = 0; i<n; i++){
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  }
  for(int i = 0; i<n; i++){
    resultBuffer[i] = DEV_READ(POSIT_COOPROC_MUL, 0);
  }  
}
void divN(int n){
  uint32_t resultBuffer[n];

  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000003);
  
  for(int i = 0; i<n; i++){
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  }
  for(int i = 0; i<n; i++){
    resultBuffer[i] = DEV_READ(POSIT_COOPROC_DIV, 0);
  }  
}
//uint32_t resultBuffer[32];
  











void addMax(){
  for(int i = 0;i<4; i++){
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  }
  for(int i = 0;i<4; i++){
    DEV_READ(POSIT_COOPROC_ADD, 0);
  }

}
void addMaxOperations(){
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);

  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
}
void mulMaxOperations(){
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);

  DEV_READ(POSIT_COOPROC_MUL, 0);
  DEV_READ(POSIT_COOPROC_MUL, 0);
  DEV_READ(POSIT_COOPROC_MUL, 0);
  DEV_READ(POSIT_COOPROC_MUL, 0);
}

int main(int argc, char **argv) {
  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000001);
  for(int i = 0;i<4; i++){
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
  }
  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000002);
  for(int i = 0;i<4; i++){
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
    DEV_READ(POSIT_COOPROC_MUL, 0);
  }
  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000003);
  for(int i = 0;i<4; i++){
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
    DEV_READ(POSIT_COOPROC_DIV, 0);
  }
  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000001);
  for(int i = 0;i<4; i++){
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
    DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
    DEV_READ(POSIT_COOPROC_ADD, 0);
  }
  return 0;
}


































































































































































































/*
  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000001);
  
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  
DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
  DEV_READ(POSIT_COOPROC_ADD, 0);
*/














/* Pruebas de rendimiento
  calculate();
  calculate();
  calculate();
  calculate();
*/

/* Prueba 2 sumas 2 divisiones 3 multiplicaciones y 4 sumas
  // initialice coprocessor process
  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000001);
  
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x41400000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x41400000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    
  puthex(DEV_READ(POSIT_COOPROC_ADD, 0));
  puts("\n");
  puthex(DEV_READ(POSIT_COOPROC_ADD, 0));
  puts("\n");

  puts("\n");


  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000003);
  
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x41000000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40800000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x41800000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40800000);

  puthex(DEV_READ(POSIT_COOPROC_DIV, 0));
  puts("\n");
  puthex(DEV_READ(POSIT_COOPROC_DIV, 0));
  puts("\n");

  puts("\n");


  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000002);
  
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40800000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40800000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40800000);

  puthex(DEV_READ(POSIT_COOPROC_MUL, 0));
  puts("\n");
  puthex(DEV_READ(POSIT_COOPROC_MUL, 0));
  puts("\n");
  puthex(DEV_READ(POSIT_COOPROC_MUL, 0));
  puts("\n");

  puts("\n");


  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000001);
  
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40800000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40800000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40800000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40800000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x40c00000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40c00000);
    
  puthex(DEV_READ(POSIT_COOPROC_ADD, 0));
  puts("\n");
  puthex(DEV_READ(POSIT_COOPROC_ADD, 0));
  puts("\n");
  puthex(DEV_READ(POSIT_COOPROC_ADD, 0));
  puts("\n");
  puthex(DEV_READ(POSIT_COOPROC_ADD, 0));
  puts("\n");
*/

  /*
  DEV_WRITE(POSIT_COOPROC_BASE, 0x00000000);

  DEV_WRITE(POSIT_COOPROC_OP_A, 0x41000000);
  DEV_WRITE(POSIT_COOPROC_OP_A, 0x41000000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40800000);
  DEV_WRITE(POSIT_COOPROC_OP_B, 0x40800000);

  DEV_WRITE(POSIT_COOPROC_OP_CODE, 0x00000001);
  DEV_WRITE(POSIT_COOPROC_START, 0x00000000);


  puthex(DEV_READ(POSIT_COOPROC_BASE, 0));
  puts("\n");
  puthex(DEV_READ(POSIT_COOPROC_BASE, 0));
  puts("\n");
  */
