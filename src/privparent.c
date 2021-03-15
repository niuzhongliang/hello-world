#include "privparent.h"

//从FTP服务子进程不断接受发送过来的一些命令，来协助这个FTP服务进程完成相应的任务
void handle_parent(session_t *sess)
{
	char cmd;
	while (1)
	{
		read(sess->parent_fd, &cmd, 1); //父子进程通信的通道
		// 解析内部命令
		// 处理内部命令
	}
}
