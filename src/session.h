#ifndef _SESSION_H_
#define _SESSION_H_

#include "common.h"

typedef struct session
{
	// 控制连接
	int ctrl_fd;  //控制连接的套接字
	char cmdline[MAX_COMMAND_LINE]; //保存命令行
	char cmd[MAX_COMMAND]; // 保存命令
	char arg[MAX_ARG]; //解析的参数

	// 父子进程通道
	int parent_fd;
	int child_fd;
} session_t;
void begin_session(session_t *sess);

#endif /* _SESSION_H_ */
