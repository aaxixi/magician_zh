#ifndef __APP_ACTION_DB_H__
#define __APP_ACTION_DB_H__

#include "x_frame.h"



typedef struct 
{
    uint32_t        action_id;
    uint8_t         flag_is_en;
    pf_action_func  action_func;
}action_item_t;


enum
{
    ACTION_ID_SHELL_IN = 1,
    
    
    //---------------test
    ACTION_ID_LOAD_TEST_START  ,
    ACTION_ID_LOAD_TEST_ITEM   ,
    ACTION_ID_LOAD_TEST_END    ,
    ACTION_ID_TEST_CMD         ,
    ACTION_ID_LOAD_RESULT_CNT  ,
    ACTION_ID_LOAD_RESULT_ITEM ,
    ACTION_ID_GET_TEST_RESULT  ,



	//-----------board test
	ACTION_ID_ENTRY_TEST,
    ACTION_ID_BEATHEAT_TEST,
    ACTION_ID_IO_INTER_TEST,
    ACTION_ID_IO_OUT_TEST,
    ACTION_ID_ON_OFF_TEST,
    ACTION_ID_CAN_TEST,
    ACTION_ID_485_TEST,
    ACTION_ID_ETH_TEST,
    ACTION_ID_I2S_TEST,
    ACTION_ID_SDIO_TEST,
    ACTION_ID_ENCODER_TEST,
    ACTION_ID_TEMP_TEST,
    ACTION_ID_ADDR_TEST,
    ACTION_ID_ADC_TEST,
    ACTION_ID_DAC_TEST,
    ACTION_ID_ADC_DAC_INTER_TEST,
    ACTION_ID_RS232_TEST,
    ACTION_ID_VGA_TEST,
    ACTION_ID_MOTOR_TEST,
    ACTION_ID_PCBA_TEST,
    
};

int32_t user_app_action(hal_frame_info_t* p_frame,action_remap_t* p_action_remap,uint32_t max_item);

#endif //__APP_ACTION_DB_H__
