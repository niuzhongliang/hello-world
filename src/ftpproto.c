#include "ftpproto.h"
#include "sysutil.h"

void handle_child(session_t *sess)
{
	//�����ӳɹ���ʱ����ͻ��˷���һ��220��Ϣ
	writen(sess->ctrl_fd, "220 (miniftpd 0.1)\r\n", strlen("220 (miniftpd 0.1)\r\n"));
	while (1)
	{
		memset(sess->cmdline, 0, sizeof(sess->cmdline));
		memset(sess->cmd, 0, sizeof(sess->cmd));
		memset(sess->arg, 0, sizeof(sess->arg));
		readline(sess->ctrl_fd, sess->cmdline, MAX_COMMAND_LINE);//���ж�ȡ�����ֵ����MAX_COMMAND_LINE
		// ����FTP���������
		// ����FTP����
		//������Ҫnobody���̵�Э����������nobody���̷�����Ӧ������
	}
}