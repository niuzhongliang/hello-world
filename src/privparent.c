#include "privparent.h"

//��FTP�����ӽ��̲��Ͻ��ܷ��͹�����һЩ�����Э�����FTP������������Ӧ������
void handle_parent(session_t *sess)
{
	char cmd;
	while (1)
	{
		read(sess->parent_fd, &cmd, 1); //���ӽ���ͨ�ŵ�ͨ��
		// �����ڲ�����
		// �����ڲ�����
	}
}
