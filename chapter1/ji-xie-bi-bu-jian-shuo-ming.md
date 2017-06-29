[http://gitbook.zhangjikai.com/themes.html](http://gitbook.zhangjikai.com/themes.html)

```c
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
```



