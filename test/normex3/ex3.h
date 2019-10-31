//######################################################################//                              //
//#                             #IFNDEF                                 //                              //
//######################################################################//                              //
#ifndef EX3_H                                                                                       	//
                                                                                                        //
#define EX3_H                                                                                       	//
//######################################################################//                              //
//#                             #INCLUDE                                //                              //
//######################################################################//                              //
#include <stdio.h>                                                                                                       //
#include <unistd.h>                                                                                                       //
#include <stdlib.h>                                                                                                       //
#include <stdint.h>                                                                                                       //
//#define DEVELOPMENT_VERSION                                                                           //
//#define PRODUCTION_VERSION                                                                            //
//#define DEMO_VERSION                                                                                  //
#define SILENCE_MODE                                                                                    //
                                                                                                        //
#define FIRST_BIT (0x01)                                                                                //
                                                                                                        //
#define RESET_TO_ZERO (0)                                                                               //
                                                                                                        //
#define NIL '\0'                                                                                        //
                                                                                                        //
#define FALSE (0)                                                                                       //
                                                                                                        //
#define ZERO (0)                                                                                        //
#define ONE (1)                                                                                         //
                                                                                                        //
#define SUCCESS (0)                                                                                     //
#define FAILURE (1)                                                                                     //
#define IMPOSSIBLE (2)                                                                                  //
                                                                                                        //
#define RETURN_SUCCESS SUCCESS                                                                          //
#define RETURN_FAILURE FAILURE                                                                          //
#define RETURN_IMPOSSIBLE IMPOSSIBLE                                                                    //
                                                                                                        //
struct	stc_param                                                                                      //
    {                                                                                                   //
    uint8_t u8_struct_init_status_;                                                                     //
    int32_t *ptr_s32_tab_;										//
    int16_t s16_index_left_;										//
    uint8_t u8_index_right_; 										//
    };                                                                                                  //
                                                                                                        //
//######################################################################//                              //
//#                             FUNCTIONS                               //                              //
//######################################################################//                              //
													//
uint8_t		Fu8__check_tab(struct stc_param *ptr_stc_param);					//
uint8_t		Fu8__sort(struct stc_param *ptr_stc_param); 						//
uint8_t		Fu8__swap(struct stc_param *ptr_pssd_stc_param);	    //
uint8_t		Fu8__quick_sort(struct stc_param *ptr_stc_param); 					//
uint8_t		Fu8__init_struct(struct stc_param *ptr_pssd_stc_param);
                                                                                                        //
#endif                                                                                                  //
