#pragma  once

#ifdef __cplusplus
extern "C"
{
#endif

//����������
	int ReadCfgFile(char *file, char *key, char *value, int *len);
	int WriteCfgFile(char *file, char *key, char *value, int len);

#ifdef __cplusplus
}
#endif