// ���ļ��ɺ���ҫ��ƣ�����ͨ��QQ��ϵ���ߣ�26750452
#include "usrinc.h"
#include "LCDConf.h"
#include "GUI.h"
#include "DIALOG.h"
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
static U64 __StackGUI[16384 / 8] MEM_PI_STACK;
static __task void __ThreadGUI(void);
static OS_TID _gui_tid = 0;

////////////////////////////////////////////////////////////////////////////////
//|          |
//| �������� |: APP_CreateGuiService
//| �������� |: ����GUI�̲߳�����GUI����
//|          |:
//| �����б� |:
//|          |:
//| ��    �� |:
//|          |:
//| ��ע��Ϣ |:
//|          |:
////////////////////////////////////////////////////////////////////////////////
bool_t APP_CreateGuiService(void)
{
  _gui_tid = os_tsk_create_user(
                 __ThreadGUI,
                 TSK_PRIO_LOLIMIT,
                 __StackGUI,
                 sizeof(__StackGUI));

  if (_gui_tid == 0) {
    DBG_PUTS("GUI failed.\n");
    return false;
  }
  return true;
}

////////////////////////////////////////////////////////////////////////////////
//|          |
//| �������� |: __ThreadGUI
//| �������� |: GUI�߳�
//|          |:
//| �����б� |:
//|          |:
//| ��    �� |:
//|          |:
//| ��ע��Ϣ |:
//|          |:
////////////////////////////////////////////////////////////////////////////////
static __task void __ThreadGUI(void)
{
  puts("RTX+emWin");
  MainTask();
  os_tsk_delete_self();
}

////////////////////////////////////////////////////////////////////////////////

