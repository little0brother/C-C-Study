//��ֹͷ�ļ��ظ�����
#pragma once

//Ϊ�˼���C++������
#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

//����������

//�������ļ�
int ReadCfgFile(char *fileName, char *pKey, char *pVal, int *pLen);

//д���޸������ļ�
int WriteCfgFile(char *fileName, char *pKey, char *pVal, int len);


#ifdef __cplusplus
}
#endif // __cplusplus
