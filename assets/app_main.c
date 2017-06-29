#define DEF_DBG_I
#define DEF_DBG_W
#define DEF_DBG_E
#include "debug.h"

#include "x_frame.h"


const uint32_t debug_id = DEFAULT_DEBUG_DEV;
uint32_t flag_enable_cpf = ENABLE_COLOR_CONSOLE;
REG_DEBUG(debug_id);


int32_t en_cpf(uint8_t argc, uint8_t *argv[])
{
    if(argc==2)
    {
        sscanf((const char*)(argv[1]),"%d",&flag_enable_cpf);
        DBG_I("set color console:%s",(flag_enable_cpf>0)?"Enable":"Disable");
    }
    else
    {
        DBG_I("cur use color console:%s",(flag_enable_cpf>0)?"Enable":"Disable");
    }     
	return RET_OK;
}

REG_SHELL_CMD(en_cpf,0,en_cpf,"en_cpf!", "en_cpf 0/1\r\n ");



static void update_task(void)
{
   DBG_I("test!!!!!!! x-frame-lib-src");
   DBG_W("test!!!!!!! x-frame-lib-src");
   DBG_E("test!!!!!!! x-frame-lib-src");    
    
   //DBG_I_LIMIT(1000,"dasdasdasdas!!!"); 
}

REG_TASK(3,1000,update_task);













int32_t p_send_func(uint8_t argc, uint8_t *argv[])
{
    hal_frame_info_t frame={0};
    uint8_t* str="help\r\n";
    frame.link_id = PC_LINK_ID;
    frame.cmd_func = 0x1;
    frame.cmd_id   = 0x21;
    frame.src      = 0x4;
    frame.dest     = 0x5;
    frame.pdata = (uint8_t*)str;
    frame.data_len = strlen((const char*)str);
	frame.check_type = 0;
	protocol_send(&frame);
	
	return RET_OK;
}

REG_SHELL_CMD(p_send_demo,0,p_send_func,"protocol send!!", "protocol send by PC_LINK_ID\r\n ");

int32_t p_send_func2(uint8_t argc, uint8_t *argv[])
{
    
    hal_frame_info_t frame={0};
    uint32_t send_data = 0x12345678;
    frame.link_id = DOBOT_LINK_ID;
    frame.cmd_id   = 170;
    frame.pdata = (uint8_t*)&send_data;
    frame.data_len =sizeof(uint32_t);
	frame.check_type = 0;
	protocol_send(&frame);
	
	return RET_OK;
}

REG_SHELL_CMD(p_send2,0,p_send_func2,"protocol send!!", "protocol send by DOBOT_LINK_ID\r\n ");


uint32_t flag_en_send = 0;

#define SEND_LEN 800
uint8_t send_buf[SEND_LEN]={0};
void vcp_speed_test(void)
{
    if(flag_en_send)
    {
        hal_app_write(DRIVER_USB_VCP,send_buf,SEND_LEN,0,NULL);
    }
}

REG_TASK(0,1,vcp_speed_test);

int32_t start_vcp_test(uint8_t argc, uint8_t *argv[])
{
    if(argc==2)
    {
        sscanf((const char*)argv[1],"%d",&flag_en_send);
        if(flag_en_send){DBG_I("start send vcp");}
        else            {DBG_I("stop  send vcp");}
    }
	return RET_OK;
}

REG_SHELL_CMD(vcp_en,0,start_vcp_test,"start_vcp_test", "start_vcp_test\r\n ");

