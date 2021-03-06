/*
 * All Video Processing kernels 
 * Copyright © <2010>, Intel Corporation.
 *
 * This program is licensed under the terms and conditions of the
 * Eclipse Public License (EPL), version 1.0.  The full text of the EPL is at
 * http://www.opensource.org/licenses/eclipse-1.0.php.
 *
 */

//---------- PL3_AVS_IEF_Unpack_8x4.asm ----------
        
    // Move 1st 8x8 words of Y to dest GRF at lower 8 words of each RGF.
    $for(0; <8/2; 1) {
        mov (8) uwDEST_Y(%1*2)<1>          ubAVS_RESPONSE(%1,1)<16;4,2>        // Copy high byte in a word
        mov (8) uwDEST_Y(%1*2+1)<1>        ubAVS_RESPONSE(%1,8+1)<16;4,2>      // Copy high byte in a word
	}

    // Move 8x4 words of U to dest GRF  (Copy high byte in a word)
    mov (8) uwDEST_U(0)<1>            ubAVS_RESPONSE(4,1)<16;4,2>      
    mov (8) uwDEST_U(0,8)<1>          ubAVS_RESPONSE(4,9)<16;4,2>    
    mov (8) uwDEST_U(1)<1>            ubAVS_RESPONSE(5,1)<16;4,2>      
    mov (8) uwDEST_U(1,8)<1>          ubAVS_RESPONSE(5,9)<16;4,2>    

    // Move 8x4 words of V to dest GRF  
    mov (8) uwDEST_V(0)<1>            ubAVS_RESPONSE(8,1)<16;4,2>      
    mov (8) uwDEST_V(0,8)<1>          ubAVS_RESPONSE(8,9)<16;4,2>    
    mov (8) uwDEST_V(1)<1>            ubAVS_RESPONSE(9,1)<16;4,2>      
    mov (8) uwDEST_V(1,8)<1>          ubAVS_RESPONSE(9,9)<16;4,2>    

    // Move 2nd 8x8 words of Y to dest GRF at higher 8 words of each RGF.
    $for(0; <8/2; 1) {
        mov (8) uwDEST_Y(%1*2,8)<1>        ubAVS_RESPONSE(%1+12,1)<16;4,2>     // Copy high byte in a word
        mov (8) uwDEST_Y(%1*2+1,8)<1>      ubAVS_RESPONSE(%1+12,8+1)<16;4,2>   // Copy high byte in a word
    } 

//------------------------------------------------------------------------------
    // Re-define new # of lines
    #undef nUV_NUM_OF_ROWS
    #undef nY_NUM_OF_ROWS
       
    #define nY_NUM_OF_ROWS      8
    #define nUV_NUM_OF_ROWS     4
                    

